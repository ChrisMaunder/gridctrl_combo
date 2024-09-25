This patch to Chris Maunder's CGridCtrl class includes the following
changes.  Search for EFW in the code to locate them.  Most changes
contain notes or are pretty self-explanatory.

MemDC.h
-------
Added code to clear the bitmap background when created so that if used
by other classes that don't completely draw over their client area, we
don't see garbage showing through.

InPlaceEdit.cpp
---------------
Fixed EndEdit() so that it does not cause assertion errors and crashes
if called multiple times.  This can occur if a derived grid control is
used that validates its input and you click on a grid control scrollbar.
In the above situation, the edit control can receive a WM_KILLFOCUS
event after EndEdit() has been called but hasn't finished yet (i.e. it
hasn't returned from the pOwner->SendMessage() call yet).  This patch
will probably need applying to any other inplace controls that use the
same code in EndEdit().

GridCell.h
----------
Added new function prototype for PrintCell() to handle the printing of
cells.

GridCell.cpp
------------
Various changes to CGridCell::Draw() to make it draw cells better when
using alternate color schemes and to keep the cell focus highlight in
any mode.

Removed printing references as that's now done by
CGridCell::PrintCell().

Fixed the sort marker so that it doesn't draw out of bounds in cells
that are as tall or shorter than the font height.

Added DT_NOPREFIX when drawing text so that we can see '&' characters.

Changed CGridCell::GetTextExtent() so that it uses its current text to
figure the extent if NULL is passed in the 'str' parameter.  This was
done to support the new CGridCtrl::GetCellTextExtent() function.

GridCtrl.h
----------
Added new CGridCtrl::GetCellTextExtent() function to get the text extent
of the text currently in the specified cell.  This saves having to
retrieve the cell text and then call CGridCtrl::GetTextExtent().

Added CGridCtrl::SetItemTextFmt() and CGridCtrl::SetItemTextFmtID() to
allow the use of printf-style formatting codes when setting text and also
the use of resource string IDs.

Added various new data members to support shaded/unshaded printout and
user-definable page margins.  Also added the relevant support functions
to get and set the new data members.

Added a message handler for OnRButtonUp() so that it can forward the
message to the parent to invoke a right click context menu.

GridCtrl.cpp
------------
Added code where relevant to support the new data members and functions
noted above.

Set m_bAllowDragAndDrop to FALSE in the constructor.  This is how it was
in the last version and is how I prefer it.  Change it back if you
prefer it the other way.

Added some bug fixes reported by others from the prior release that
didn't look like they made it into the new version (flush OLE data
source clipboard, ignore Escape in OnChar() for instant cell editing).

Added code in several locations to fix problems with cell focus and
selection highlighting.

Added code and adjusted existing code where necessary to support the new
printing features noted above.

End of changes
