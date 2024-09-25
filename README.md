# Using comboboxes in the MFC Grid Control

Explains how to use comboboxes to edit cells in the MFC Grid Control

![Sample Image - gridctrl_combo.gif](https://raw.githubusercontent.com/ChrisMaunder/gridctrl_combo/master/docs/assets/gridctrl_combo.gif)

## Introduction

Since I posted my [MFC grid control](https://github.com/ChrisMaunder/MFC-GridCtrl) I've had a lot of requests asking how to use other methods of editing cells in the grid. Ken Bertelson has taken this to the extreme with his [Grid Tree control](https://www.codeproject.com/Articles/126054/CTreeGridCtrl-A-Grid-Control-with-Tree-Like-Functi). For some this was a little too involved, so I've created a demo project that shows how to replace the default editing with a simple combo box. 

Previous methods of achieving this required that a new `CGridCtrl` derived class be created. With the new structure in the 2.X versions of `CGridCtrl` it's now a lot simpler. 

## A new cell type

Changing the way cells are edited is simply a matter of deriving a new grid cell class from `CGridCellBase` (or derivatives such as `CGridCell`). 

I'm using the In-Place list that I used in previous versions. It's not the greatest - but it does demonstrate how to replace the default editing. 

The first step is to derive a new class from `CGridCell` - I call it `CGridCellCombo` - and override `Edit` (which initiates editing) and `EndEdit` (which stops editing). You can find this class in the GridCellCombo.\* files. 

In `Edit` I create a `CWnd` derived class that will perform the actual editing - in this case my `CInPlaceList` from previous versions of the grid. There are a number of things to be aware of when creating such `CWnd` derived `Edit` classes: 

- The control will receive the row and column to be edited, the dimensions and location of the in-place edit control, the style of control to create, the original text in the cell plus the initial character that caused editing to commence (or VK\_LBUTTON if the mouse was clicked on the current cell).
- Your editing control should stop editing when it loses input focus.
- Your editing object should handle mouse keys in a way that allows the user to navigate between cells while editing. If the control gets an arrow key for instance, it should cancel editing and return the last key it encountered back to the grid via the GVN\_ENDLABELEDIT notification message. 
Note that the grid control accepts Ctrl+&lt;arrows&gt; for navigation, so if your in-place edit control needs to use the arrows, you can always reserve Ctrl+&lt;arrows&gt; to move to other cells.
- Your edit control should pass back information about the last key pressed before editing ended. This allows correct movement among cells

The `EndEdit` function of your grid cell class should cease editing and destroy the in-place editing window. 

If you look at the code you will see that the grid cell derived class is merely a wrapper that creates an instance of a `CInPlaceList` window and then sits back with the knowledge of a job well done. The actual guts of the grid cell class are as follows: 

```cpp
// Create a control to do the editing
BOOL CGridCellCombo::Edit(int nRow, int nCol, CRect rect, CPoint /* point */,
                          UINT nID, UINT nChar)
{
    m_bEditing = TRUE;
    
    // CInPlaceList auto-deletes itself
    m_pEditWnd = new CInPlaceList(GetGrid(), rect, GetStyle(), nID, nRow, nCol, 
                                  m_Strings, GetText(), nChar);

    return TRUE;
}

// Cancel the editing.
void CGridCellCombo::EndEdit()
{
    if (m_pEditWnd)
        ((CInPlaceList*)m_pEditWnd)->EndEdit();
}
```

We rely on `CGridCell::OnEndEdit` to set *m\_bEditing* to FALSE and *m\_pEditWnd* to NULL when editing has finished. `CInPlaceList` is also self-deleting, which saves a whole line of code in `EndEdit`. 

The `CInPlaceList` does the actual work, and keeps track of issues such as the last key pressed and it's current focus state. It also has niceties such as ensuring that the drop down list is correctly sized. 

The major issue is that the control must pass the necessary data back to the parent grid once editing has been completed. It uses the following code snippet in it's `EndEdit` method to do this: 

```cpp
void CInPlaceList::EndEdit()
{
    CString str;
    GetWindowText(str);
 
    // Send Notification to parent
    GV_DISPINFO dispinfo;

    dispinfo.hdr.hwndFrom = GetSafeHwnd();
    dispinfo.hdr.idFrom   = GetDlgCtrlID();
    dispinfo.hdr.code     = GVN_ENDLABELEDIT;
 
    dispinfo.item.mask    = LVIF_TEXT|LVIF_PARAM;
    dispinfo.item.row     = m_nRow;
    dispinfo.item.col     = m_nCol;
    dispinfo.item.strText = str;
    dispinfo.item.lParam  = (LPARAM) m_nLastChar; 
 
    CWnd* pOwner = GetOwner();
    if (IsWindow(pOwner->GetSafeHwnd()))
        pOwner->SendMessage(WM_NOTIFY, GetDlgCtrlID(), (LPARAM)&dispinfo );
 
    // Close this window (PostNcDestroy will delete this)
    PostMessage(WM_CLOSE, 0, 0);
}
```

I pass the character that initiated editing to the edit control itself so that it can deal with keys appropriately. For instance in the default edit control, if the edit control is passed a normal character or arrow key as the "initiating" key, then it will cease editing when it encounters an arrow key (to allow navigation using the keyboard). If the edit control is passed VK\_LBUTTON (meaning editing was initiated by a mouse click) then arrow keys will not cause the editing to cease. 

One last thing I do is ensure that the new cell displays a user hint that it is not a normal grid cell. When a cell is selected I override drawing so that a small drop down arrow is shown. The code is quite simple: 

```cpp
BOOL CGridCellCombo::Draw(CDC* pDC, int nRow, int nCol, CRect rect,
                          BOOL bEraseBkgnd /*=TRUE*/)
{
    // Cell selected?
    DWORD dwState = GetState();
    if ( !(dwState & GVIS_FIXED) && (dwState & GVIS_FOCUSED))
    {
        // Get the size of the scroll box
        CSize sizeScroll(GetSystemMetrics(SM_CXVSCROLL), 
                         GetSystemMetrics(SM_CYHSCROLL));

        // enough room to draw?
        if (sizeScroll.cy < rect.Width() && sizeScroll.cy < rect.Height())
        {
            // Draw control at RHS of cell
            CRect ScrollRect = rect;
            ScrollRect.left   = rect.right - sizeScroll.cx;
            ScrollRect.bottom = rect.top + sizeScroll.cy;

            // Do the draw 
            pDC->DrawFrameControl(ScrollRect, DFC_SCROLL, DFCS_SCROLLDOWN);

            // Adjust the remaining space in the cell
            rect.right = ScrollRect.left;
        }
    }

    // drop through and complete the cell drawing using the base class' method
    return CGridCell::Draw(pDC, nRow, nCol, rect,  bEraseBkgnd);
}
```

## Using the new cell type

Using the new cell is simple. You can either use the Grid control's default cell instantiation method (ie. do nothing) and then call `CGridCtrl::SetCellType` or you can call `CGridCtrl::SetDefaultCellType` and *then* do nothing. The first option changes cells from one type to another, and is good if you only want specific cells to be affected. The second option tells the grid the class type that you want to be used at the outset, and is good if you want all cells in the grid to be of your new type. 

## Thanks

Thanks go to [Roelf Werkman](mailto:rdw@inn.nl) for his work in extending the `CInPlaceList` to allow the CBS\_DROPDOWN and CBS\_SIMPLE styles to be used, and thanks to Fred Ackers for moticating me to finally write this up.
