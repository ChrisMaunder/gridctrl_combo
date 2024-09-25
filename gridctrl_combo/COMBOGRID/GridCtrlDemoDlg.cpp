// GridCtrlDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GridCtrlDemo.h"
#include "GridCtrlDemoDlg.h"

#include "GridCellCombo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg() : CDialog(IDD_ABOUTBOX) {}
};

/////////////////////////////////////////////////////////////////////////////
// CGridCtrlDemoDlg dialog

CGridCtrlDemoDlg::CGridCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGridCtrlDemoDlg::IDD, pParent)
{
	m_OldSize = CSize(-1,-1);

	//{{AFX_DATA_INIT(CGridCtrlDemoDlg)
	m_nFixCols = 1;
	m_nFixRows = 1;
	m_nCols = 8;
	m_nRows = 20;
	m_bEditable = TRUE;
	m_bHorzLines = TRUE;
	m_bListMode = FALSE;
	m_bVertLines = TRUE;
	m_bSelectable = TRUE;
	m_bAllowColumnResize = TRUE;
	m_bAllowRowResize = TRUE;
	m_bHeaderSort = TRUE;
	m_bReadOnly = TRUE;
	m_bItalics = TRUE;
	m_btitleTips = TRUE;
	m_bSingleSelMode = FALSE;
	m_bCellURL = FALSE;
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGridCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGridCtrlDemoDlg)
	DDX_Control(pDX, IDC_SPIN_ROW, m_RowSpin);
	DDX_Control(pDX, IDC_SPIN_FIXROW, m_FixRowSpin);
	DDX_Control(pDX, IDC_SPIN_FIXCOL, m_FixColSpin);
	DDX_Control(pDX, IDC_SPIN_COL, m_ColSpin);
	DDX_Text(pDX, IDC_EDIT_FIXCOLS, m_nFixCols);
	DDX_Text(pDX, IDC_EDIT_FIXROWS, m_nFixRows);
	DDX_Text(pDX, IDC_EDIT_COLS, m_nCols);
	DDX_Text(pDX, IDC_EDIT_ROWS, m_nRows);
	DDX_Check(pDX, IDC_EDITABLE, m_bEditable);
	DDX_Check(pDX, IDC_HORZ_LINES, m_bHorzLines);
	DDX_Check(pDX, IDC_LISTMODE, m_bListMode);
	DDX_Check(pDX, IDC_VERT_LINES, m_bVertLines);
	DDX_Check(pDX, IDC_ALLOW_SELECTION, m_bSelectable);
	DDX_Check(pDX, IDC_COL_RESIZE, m_bAllowColumnResize);
	DDX_Check(pDX, IDC_ROW_RESIZE, m_bAllowRowResize);
	DDX_Check(pDX, IDC_HEADERSORT, m_bHeaderSort);
	DDX_Check(pDX, IDC_READ_ONLY, m_bReadOnly);
	DDX_Check(pDX, IDC_ITALICS, m_bItalics);
	DDX_Check(pDX, IDC_TITLETIPS, m_btitleTips);
	DDX_Check(pDX, IDC_SINGLESELMODE, m_bSingleSelMode);
	DDX_Check(pDX, IDC_CELL_URL, m_bCellURL);
	//}}AFX_DATA_MAP

    // There is a problem with registering the grid as an OLE Drop target
    // in the CGridCtrl::PreSubclassWindow function that only shows itself
    // under win95. To ensure that the grid can accept drag and drop items,
    // we use the DDX_GridControl routine which ensures that CGridCtrl::SubclassWindow
    // is called, and hence the grid will be registered as a drop target.
    //
    // If ANYONE knows a neater way, please let me know. I'm new to this stuff!
	DDX_GridControl(pDX, IDC_GRID, m_Grid);
}

BEGIN_MESSAGE_MAP(CGridCtrlDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CGridCtrlDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_QUERYDRAGICON()
	ON_EN_UPDATE(IDC_EDIT_COLS, OnUpdateEditCols)
	ON_EN_UPDATE(IDC_EDIT_FIXCOLS, OnUpdateEditFixcols)
	ON_EN_UPDATE(IDC_EDIT_FIXROWS, OnUpdateEditFixrows)
	ON_EN_UPDATE(IDC_EDIT_ROWS, OnUpdateEditRows)
	ON_BN_CLICKED(IDC_HORZ_LINES, OnGridLines)
	ON_BN_CLICKED(IDC_LISTMODE, OnListmode)
	ON_BN_CLICKED(IDC_EDITABLE, OnEditable)
	ON_BN_CLICKED(IDC_PRINT_BUTTON, OnPrintButton)
	ON_BN_CLICKED(IDC_ALLOW_SELECTION, OnAllowSelection)
	ON_BN_CLICKED(IDC_ROW_RESIZE, OnRowResize)
	ON_BN_CLICKED(IDC_COL_RESIZE, OnColResize)
	ON_BN_CLICKED(IDC_FONT_BUTTON, OnFontButton)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_HEADERSORT, OnHeaderSort)
	ON_COMMAND(ID_EDIT_SELECTALL, OnEditSelectall)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_BN_CLICKED(IDC_READ_ONLY, OnReadOnly)
	ON_BN_CLICKED(IDC_ITALICS, OnItalics)
	ON_BN_CLICKED(IDC_TITLETIPS, OnTitletips)
	ON_BN_CLICKED(IDC_INSERT_ROW, OnInsertRow)
	ON_BN_CLICKED(IDC_DELETE_ROW, OnDeleteRow)
	ON_BN_CLICKED(IDC_SINGLESELMODE, OnSingleselmode)
	ON_BN_CLICKED(IDC_EXPAND_TO_FIT, OnExpandToFit)
	ON_BN_CLICKED(IDC_AUTO_SIZE, OnAutoSize)
	ON_BN_CLICKED(IDC_FILL, OnFill)
	ON_BN_CLICKED(IDC_VERT_LINES, OnGridLines)
	ON_COMMAND(ID_FILE_PRINT, OnPrintButton)
	ON_BN_CLICKED(IDC_CELL_URL, OnCellUrl)
	//}}AFX_MSG_MAP
    ON_NOTIFY(NM_DBLCLK, IDC_GRID, OnGridDblClick)
    ON_NOTIFY(NM_CLICK, IDC_GRID, OnGridClick)
#ifndef GRIDCONTROL_NO_CLIPBOARD
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopyOrCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCopyOrCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
#endif
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGridCtrlDemoDlg message handlers

BOOL CGridCtrlDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

#ifndef _WIN32_WCE
	CMenu* pSysMenu = GetSystemMenu(FALSE);

    if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
#else
    CSize ScreenSize();
    ::SetWindowPos(m_hWnd, HWND_TOP,0,0, 
                 GetSystemMetrics(SM_CXSCREEN), 
                 GetSystemMetrics(SM_CYSCREEN) - 32, // 32 = kludge value
                 SWP_SHOWWINDOW);
#endif

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CRect rect;
	GetClientRect(rect);
	m_OldSize = CSize(rect.Width(), rect.Height());

	// init spin controls
	m_RowSpin.SetRange(0,999);
	m_FixRowSpin.SetRange(0,999);
	m_FixColSpin.SetRange(0,999);
	m_ColSpin.SetRange(0,999);

	OnListmode();

	/////////////////////////////////////////////////////////////////////////
	// initialise grid properties
	/////////////////////////////////////////////////////////////////////////

    m_Grid.SetDefaultCellType(RUNTIME_CLASS(CGridCellCombo));

	m_ImageList.Create(MAKEINTRESOURCE(IDB_IMAGES), 16, 1, RGB(255,255,255));
	m_Grid.SetImageList(&m_ImageList);

	m_Grid.SetEditable(m_bEditable);
	m_Grid.SetListMode(m_bListMode);
	m_Grid.EnableDragAndDrop(TRUE);
	m_Grid.SetTextBkColor(RGB(0xFF, 0xFF, 0xE0));

	TRY {
		m_Grid.SetRowCount(m_nRows);
		m_Grid.SetColumnCount(m_nCols);
		m_Grid.SetFixedRowCount(m_nFixRows);
		m_Grid.SetFixedColumnCount(m_nFixCols);
	}
	CATCH (CMemoryException, e)
	{
		e->ReportError();
		e->Delete();
		return FALSE;
	}
    END_CATCH

    DWORD dwTextStyle = DT_RIGHT|DT_VCENTER|DT_SINGLELINE|DT_NOPREFIX;
#ifndef _WIN32_WCE
    dwTextStyle |= DT_END_ELLIPSIS;
#endif

	// fill rows/cols with text
	for (int row = 0; row < m_Grid.GetRowCount(); row++)
		for (int col = 0; col < m_Grid.GetColumnCount(); col++)
		{ 
			GV_ITEM Item;
			Item.mask = GVIF_TEXT|GVIF_FORMAT;
			Item.row = row;
			Item.col = col;
			if (row < m_nFixRows)
            {
				Item.nFormat = DT_LEFT|DT_WORDBREAK|DT_NOPREFIX;
				Item.strText.Format(_T("Column %d"),col);
			}
            else if (col < m_nFixCols) 
            {
				Item.nFormat = dwTextStyle;
				Item.strText.Format(_T("Row %d"),row);
			}
            else 
            {
				Item.nFormat = dwTextStyle;
				Item.strText.Format(_T("%d"),row*col);
			}
			m_Grid.SetItem(&Item);

			if (col == (m_Grid.GetFixedColumnCount()-1) )//&& row >= m_Grid.GetFixedRowCount())
				m_Grid.SetItemImage(row, col, rand()%m_ImageList.GetImageCount());
			//else if (rand() % 10 == 1)
			//	m_Grid.SetItemImage(row, col, 0);

			if (rand() % 10 == 1)
			{
                COLORREF clr = RGB(rand()%128 + 128, rand()%128 + 128, rand()%128 + 128);
				m_Grid.SetItemBkColour(row, col, clr);
				m_Grid.SetItemFgColour(row, col, RGB(255,0,0));
			}
		}

	// Make cell 1,1 read-only
    m_Grid.SetItemState(1,1, m_Grid.GetItemState(1,1) | GVIS_READONLY);

    OnItalics();
    OnTitletips();
    
	m_Grid.AutoSize();
	//m_Grid.SetRowHeight(0, 3*m_Grid.GetRowHeight(0)/2);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGridCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

HCURSOR CGridCtrlDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGridCtrlDemoDlg::OnUpdateEditCols() 
{
	if (!::IsWindow(m_Grid.m_hWnd)) return;
	UpdateData();

    int nOldNumCols = m_Grid.GetColumnCount();

	TRY { 
        m_Grid.SetColumnCount(m_nCols); 
    }
	CATCH (CMemoryException, e)
	{
		e->ReportError();
		e->Delete();
		return;
	}
    END_CATCH

	m_nCols = m_Grid.GetColumnCount();
	m_nFixCols = m_Grid.GetFixedColumnCount();
	UpdateData(FALSE);

    CString str;
    for (int i = nOldNumCols; i < m_nCols; i++)
    {
        str.Format(_T("Column %d"), i);
        m_Grid.SetItemText(0,i,str);
    }
}

void CGridCtrlDemoDlg::OnUpdateEditFixcols() 
{
	if (!::IsWindow(m_Grid.m_hWnd)) return;
	UpdateData();

	TRY {
        m_Grid.SetFixedColumnCount(m_nFixCols); 
    }
	CATCH (CMemoryException, e)
	{
		e->ReportError();
		e->Delete();
		return;
	}
    END_CATCH

	m_nCols = m_Grid.GetColumnCount();
	m_nFixCols = m_Grid.GetFixedColumnCount();
	UpdateData(FALSE);
}

void CGridCtrlDemoDlg::OnUpdateEditFixrows() 
{
	if (!::IsWindow(m_Grid.m_hWnd)) return;
	UpdateData();

	TRY {
        m_Grid.SetFixedRowCount(m_nFixRows); 
    }
	CATCH (CMemoryException, e)
	{
		e->ReportError();
		e->Delete();
		return;
	}
    END_CATCH

	m_nRows = m_Grid.GetRowCount();
	m_nFixRows = m_Grid.GetFixedRowCount();
	UpdateData(FALSE);
}

void CGridCtrlDemoDlg::OnUpdateEditRows() 
{	
	if (!::IsWindow(m_Grid.m_hWnd)) return;
	UpdateData();

    int nOldNumRows = m_Grid.GetRowCount();

	TRY {
        m_Grid.SetRowCount(m_nRows); 
    }
	CATCH (CMemoryException, e)
	{
		e->ReportError();
		e->Delete();
		return;
	}
    END_CATCH

	m_nRows = m_Grid.GetRowCount();
	m_nFixRows = m_Grid.GetFixedRowCount();
	UpdateData(FALSE);

    CString str;
    for (int i = nOldNumRows; i < m_nRows; i++)
    {
        str.Format(_T("Row %d"), i);
        m_Grid.SetItemText(i,0,str);
    }
}

void CGridCtrlDemoDlg::OnGridLines() 
{
	UpdateData();

	if (!m_bHorzLines && !m_bVertLines)
		m_Grid.SetGridLines(GVL_NONE);
	else if (m_bHorzLines && !m_bVertLines)
		m_Grid.SetGridLines(GVL_HORZ);
	else if (!m_bHorzLines && m_bVertLines)
		m_Grid.SetGridLines(GVL_VERT);
	else 
		m_Grid.SetGridLines(GVL_BOTH);
}

void CGridCtrlDemoDlg::OnListmode() 
{
	UpdateData();
	m_Grid.SetListMode(m_bListMode);

	CWnd* pButton = GetDlgItem(IDC_HEADERSORT);
	if (pButton) 
	{
		pButton->ModifyStyle(m_bListMode?WS_DISABLED:0, m_bListMode? 0:WS_DISABLED);
		pButton->Invalidate();
	}
	pButton = GetDlgItem(IDC_SINGLESELMODE);
	if (pButton) 
	{
		pButton->ModifyStyle(m_bListMode?WS_DISABLED:0, m_bListMode? 0:WS_DISABLED);
		pButton->Invalidate();
	}
}

void CGridCtrlDemoDlg::OnHeaderSort() 
{
	UpdateData();
	m_Grid.SetHeaderSort(m_bHeaderSort);
}

void CGridCtrlDemoDlg::OnSingleselmode() 
{
	UpdateData();
	m_Grid.SetSingleRowSelection(m_bSingleSelMode);
}

void CGridCtrlDemoDlg::OnEditable() 
{
	UpdateData();
	m_Grid.SetEditable(m_bEditable);
}

void CGridCtrlDemoDlg::OnAllowSelection() 
{
	UpdateData();
	m_Grid.EnableSelection(m_bSelectable);
}

void CGridCtrlDemoDlg::OnRowResize() 
{
	UpdateData();
	m_Grid.SetRowResize(m_bAllowRowResize);
}

void CGridCtrlDemoDlg::OnColResize() 
{
	UpdateData();
	m_Grid.SetColumnResize(m_bAllowColumnResize);
}

void CGridCtrlDemoDlg::OnPrintButton() 
{
#if !defined(WCE_NO_PRINTING) && !defined(GRIDCONTROL_NO_PRINTING)
	m_Grid.Print();
#endif
}

void CGridCtrlDemoDlg::OnFontButton() 
{
#ifndef _WIN32_WCE
	LOGFONT lf;
	m_Grid.GetFont()->GetLogFont(&lf);

	CFontDialog dlg(&lf);
	if (dlg.DoModal() == IDOK) {
		dlg.GetCurrentFont(&lf);

		CFont Font;
		Font.CreateFontIndirect(&lf);
		m_Grid.SetFont(&Font);
        OnItalics();	
		m_Grid.AutoSize();
		Font.DeleteObject();	
	}
#endif
}

BOOL CALLBACK EnumProc(HWND hwnd, LPARAM lParam)
{
	CWnd* pWnd = CWnd::FromHandle(hwnd);
	CSize* pTranslate = (CSize*) lParam;

	CGridCtrlDemoDlg* pDlg = (CGridCtrlDemoDlg*) pWnd->GetParent();
	if (!pDlg) return FALSE;

	CRect rect;
	pWnd->GetWindowRect(rect);
	if (hwnd == pDlg->m_Grid.GetSafeHwnd())
		TRACE(_T("Wnd rect: %d,%d - %d,%d\n"),rect.left,rect.top, rect.right, rect.bottom);
	pDlg->ScreenToClient(rect);
	if (hwnd == pDlg->m_Grid.GetSafeHwnd())
		TRACE(_T("Scr rect: %d,%d - %d,%d\n"),rect.left,rect.top, rect.right, rect.bottom);


	if (hwnd == pDlg->m_Grid.GetSafeHwnd())
	{
		if (  ((rect.top >= 7 && pTranslate->cy > 0) || rect.Height() > 20) &&
			  ((rect.left >= 7 && pTranslate->cx > 0) || rect.Width() > 20)   )
			pDlg->m_Grid.MoveWindow(rect.left, rect.top, 
									rect.Width()+pTranslate->cx, 
									rect.Height()+pTranslate->cy, FALSE);
		else
			pWnd->MoveWindow(rect.left+pTranslate->cx, rect.top+pTranslate->cy, 
							 rect.Width(), rect.Height(), FALSE);
	}
	else 
	{
        if (::GetDlgCtrlID(hwnd) == IDC_INFO1 || ::GetDlgCtrlID(hwnd) == IDC_INFO2)
    		pWnd->MoveWindow(rect.left, rect.top+pTranslate->cy, 
	    					 rect.Width(), rect.Height(), FALSE);
        else
       		pWnd->MoveWindow(rect.left+pTranslate->cx, rect.top+pTranslate->cy, 
        					 rect.Width(), rect.Height(), FALSE);
	}
	pDlg->Invalidate();

	return TRUE;
}

void CGridCtrlDemoDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	if (cx <= 1 || cy <= 1 ) 
        return;

#ifdef _WIN32_WCE
    m_Grid.MoveWindow(0,0, cx,cy, FALSE);
#else
	CSize Translate(cx - m_OldSize.cx, cy - m_OldSize.cy);

	::EnumChildWindows(GetSafeHwnd(), EnumProc, (LPARAM)&Translate);
	m_OldSize = CSize(cx,cy);
#endif

    //if (::IsWindow(m_Grid.m_hWnd))
    //    m_Grid.ExpandToFit();
}

#ifndef GRIDCONTROL_NO_CLIPBOARD
void CGridCtrlDemoDlg::OnEditCopy() 
{
	m_Grid.OnEditCopy();	
}

void CGridCtrlDemoDlg::OnEditCut() 
{
	m_Grid.OnEditCut();	
}

void CGridCtrlDemoDlg::OnEditPaste() 
{
	m_Grid.OnEditPaste();	
}

void CGridCtrlDemoDlg::OnUpdateEditCopyOrCut(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_Grid.GetSelectedCount() > 0);
}

void CGridCtrlDemoDlg::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
    // Attach a COleDataObject to the clipboard see if there is any data
    COleDataObject obj;
    pCmdUI->Enable(obj.AttachClipboard() && obj.IsDataAvailable(CF_TEXT)); 
}
#endif

void CGridCtrlDemoDlg::OnEditSelectall() 
{
	m_Grid.OnEditSelectAll();
}

void CGridCtrlDemoDlg::OnAppAbout() 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CGridCtrlDemoDlg::OnReadOnly() 
{
	UpdateData();
    if (m_bReadOnly)
        m_Grid.SetItemState(1,1, m_Grid.GetItemState(1,1) | GVIS_READONLY);
    else
        m_Grid.SetItemState(1,1, m_Grid.GetItemState(1,1) & ~GVIS_READONLY);
}

void CGridCtrlDemoDlg::OnItalics() 
{
    UpdateData();
    
    // Set fixed cell fonts as italics
	for (int row = 0; row < m_Grid.GetRowCount(); row++)
		for (int col = 0; col < m_Grid.GetColumnCount(); col++)
		{ 
		    if (row < m_Grid.GetFixedRowCount() || col < m_Grid.GetFixedColumnCount())
		    {
		        const LOGFONT* pLF = m_Grid.GetItemFont(row ,col);
		        if (!pLF) continue;
		        
		        LOGFONT lf;
		        memcpy(&lf, pLF, sizeof(LOGFONT));
		        lf.lfItalic = (BYTE) m_bItalics;
		        
		        m_Grid.SetItemFont(row, col, &lf);
		    }
		}
	
	m_Grid.Invalidate();
}

void CGridCtrlDemoDlg::OnTitletips() 
{
    UpdateData();
    m_Grid.EnableTitleTips(m_btitleTips);
}

void CGridCtrlDemoDlg::OnInsertRow() 
{
	//m_Grid.SetSelectedRange(-1,-1,-1,-1);
	int nRow = m_Grid.GetFocusCell().row;
    if (nRow >= 0)
    {
	    m_Grid.InsertRow(_T("Newest Row"), nRow);	
	    m_Grid.Invalidate();
    }
	//m_Grid.SetSelectedRange(-1,-1,-1,-1);
}

void CGridCtrlDemoDlg::OnDeleteRow() 
{
	int nRow = m_Grid.GetFocusCell().row;
    if (nRow >= 0)
    {
	    m_Grid.DeleteRow(nRow);	
	    m_Grid.Invalidate();
    }
}

// (Thanks to Koay Kah Hoe for this)
BOOL CGridCtrlDemoDlg::PreTranslateMessage(MSG* pMsg) 
{
    if( pMsg->message == WM_KEYDOWN )
    {
        if(pMsg->wParam == VK_RETURN
            || pMsg->wParam == VK_ESCAPE )
        {
            ::TranslateMessage(pMsg);
            ::DispatchMessage(pMsg);
            return TRUE;                    // DO NOT process further
        }
    }
    return CDialog::PreTranslateMessage(pMsg);
}	

void CGridCtrlDemoDlg::OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* /*pResult*/)
{
    NM_GRIDVIEW* pItem = (NM_GRIDVIEW*) pNotifyStruct;
    if (pItem->iRow < 0)
        return;

    TRACE2("Double Clicked on row %d, col %d\n", pItem->iRow, pItem->iColumn);
}

void CGridCtrlDemoDlg::OnGridClick(NMHDR *pNotifyStruct, LRESULT* /*pResult*/)
{
    NM_GRIDVIEW* pItem = (NM_GRIDVIEW*) pNotifyStruct;
    if (pItem->iRow < 0)
        return;

    TRACE2("Clicked on row %d, col %d\n", pItem->iRow, pItem->iColumn);
}


void CGridCtrlDemoDlg::OnExpandToFit() 
{
    m_Grid.ExpandToFit();
}

void CGridCtrlDemoDlg::OnAutoSize() 
{
    m_Grid.AutoSize();
}

void CGridCtrlDemoDlg::OnFill() 
{
    m_Grid.DeleteAllItems();
    m_Grid.AutoFill();
}

void CGridCtrlDemoDlg::OnCellUrl() 
{
	UpdateData();
    if (m_bCellURL)
    {
        m_Grid.SetCellType(1,1, RUNTIME_CLASS(CGridCellCombo));
    }
    else
    {
        m_Grid.SetCellType(1,1, RUNTIME_CLASS(CGridCell));
        m_Grid.SetItemText(1,1, _T("1"));
    }
    m_Grid.Invalidate();
}
