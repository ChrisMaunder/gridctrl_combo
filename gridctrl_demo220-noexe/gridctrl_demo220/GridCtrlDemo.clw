; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGridCtrlDemoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "gridctrldemo.h"
LastPage=0

ClassCount=8
Class1=CGridCtrl
Class2=CGridDropTarget
Class3=CInPlaceEdit
Class4=CTitleTip
Class5=CGridCtrlDemoApp
Class6=CGridCtrlDemoDlg
Class7=CComboEdit
Class8=CInPlaceList

ResourceCount=5
Resource1=IDD_GRIDCTRLDEMO_DIALOG
Resource2=IDD_ABOUTBOX (English (U.S.))
Resource3=IDR_MENU
Resource4=IDD_GRIDCTRLDEMO_DIALOG (English (U.S.))
Resource5=IDR_MENU (English (U.S.))

[CLS:CGridCtrl]
Type=0
BaseClass=CWnd
HeaderFile=GridCtrl_src\GridCtrl.h
ImplementationFile=GridCtrl_src\GridCtrl.cpp

[CLS:CGridDropTarget]
Type=0
BaseClass=COleDropTarget
HeaderFile=GridCtrl_src\GridDropTarget.h
ImplementationFile=GridCtrl_src\GridDropTarget.cpp

[CLS:CInPlaceEdit]
Type=0
BaseClass=CEdit
HeaderFile=GridCtrl_src\InPlaceEdit.h
ImplementationFile=GridCtrl_src\InPlaceEdit.cpp

[CLS:CTitleTip]
Type=0
BaseClass=CWnd
HeaderFile=GridCtrl_src\TitleTip.h
ImplementationFile=GridCtrl_src\TitleTip.cpp

[CLS:CGridCtrlDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=GridCtrlDemo.h
ImplementationFile=GridCtrlDemo.cpp

[CLS:CGridCtrlDemoDlg]
Type=0
BaseClass=CDialog
HeaderFile=GridCtrlDemoDlg.h
ImplementationFile=GridCtrlDemoDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CGridCtrlDemoDlg

[CLS:CComboEdit]
Type=0
BaseClass=CEdit
HeaderFile=NewCellTypes\GridCellCombo.h
ImplementationFile=NewCellTypes\GridCellCombo.cpp

[CLS:CInPlaceList]
Type=0
BaseClass=CComboBox
HeaderFile=NewCellTypes\GridCellCombo.h
ImplementationFile=NewCellTypes\GridCellCombo.cpp

[DLG:IDD_GRIDCTRLDEMO_DIALOG]
Type=1
Class=CGridCtrlDemoDlg
ControlCount=19
Control1=IDC_GRID,MFCGridCtrl,1350631424
Control2=IDC_CELL_NORMAL,button,1342308361
Control3=IDC_CELL_READONLY,button,1342177289
Control4=IDC_CELL_URL,button,1342177289
Control5=IDC_CELL_COMBO,button,1342177289
Control6=IDC_EDIT_ROWS,edit,1350639744
Control7=IDC_SPIN_ROW,msctls_updown32,1342177334
Control8=IDC_EDIT_COLS,edit,1350639744
Control9=IDC_SPIN_COL,msctls_updown32,1342177334
Control10=IDC_EDIT_FIXROWS,edit,1350639744
Control11=IDC_SPIN_FIXROW,msctls_updown32,1342177334
Control12=IDC_EDIT_FIXCOLS,edit,1350639744
Control13=IDC_SPIN_FIXCOL,msctls_updown32,1342177334
Control14=IDCANCEL,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_SIZEBOX,scrollbar,1073741852

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=?
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[MNU:IDR_MENU]
Type=1
Class=CGridCtrlDemoDlg
Command1=IDC_PRINT_BUTTON
Command2=ID_APP_EXIT
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_SELECTALL
Command7=IDC_EDITABLE
Command8=IDC_ALLOW_SELECTION
Command9=IDC_FIXEDCELL_SELECTION
Command10=IDC_FILL
Command11=IDC_AUTO_SIZE
Command12=IDC_EXPAND_TO_FIT
Command13=IDC_EXPAND_LAST
Command14=IDC_HORZ_LINES
Command15=IDC_VERT_LINES
Command16=IDC_INSERT_ROW
Command17=IDC_DELETE_ROW
Command18=IDC_SET_FOCUS
Command19=IDC_FONT_BUTTON
Command20=IDC_TITLETIPS
Command21=IDC_TRACKFOCUS
Command22=IDC_FRAMEFOCUS
Command23=IDC_HEADERSORT
Command24=IDC_ITALICS
Command25=IDC_VERTICAL_TEXT
Command26=IDC_LISTMODE
Command27=IDC_SINGLESELMODE
Command28=IDC_ROW_RESIZE
Command29=IDC_COL_RESIZE
Command30=IDC_VIRTUAL_MODE
Command31=IDC_CALLBACK_FUNCTION
Command32=ID_APP_ABOUT
CommandCount=32

[MNU:IDR_MENU (English (U.S.))]
Type=1
Class=?
Command1=IDC_PRINT_BUTTON
Command2=ID_APP_EXIT
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_SELECTALL
Command7=IDC_ALLOW_SELECTION
Command8=IDC_FIXEDCOL_SELECTION
Command9=IDC_FIXEDROW_SELECTION
Command10=IDC_SINGLECOLSELMODE
Command11=IDC_FILL
Command12=IDC_AUTO_SIZE
Command13=IDC_EXPAND_TO_FIT
Command14=IDC_EXPAND_LAST
Command15=IDC_HORZ_LINES
Command16=IDC_VERT_LINES
Command17=IDC_INSERT_ROW
Command18=IDC_DELETE_ROW
Command19=IDC_SET_FOCUS
Command20=IDC_FONT_BUTTON
Command21=IDC_EDITABLE
Command22=IDC_TITLETIPS
Command23=IDC_TRACKFOCUS
Command24=IDC_FRAMEFOCUS
Command25=IDC_HEADERSORT
Command26=IDC_ITALICS
Command27=IDC_VERTICAL_TEXT
Command28=IDC_LISTMODE
Command29=IDC_SINGLESELMODE
Command30=IDC_ROW_RESIZE
Command31=IDC_COL_RESIZE
Command32=IDC_VIRTUAL_MODE
Command33=IDC_CALLBACK_FUNCTION
Command34=ID_APP_ABOUT
CommandCount=34

[DLG:IDD_GRIDCTRLDEMO_DIALOG (English (U.S.))]
Type=1
Class=?
ControlCount=19
Control1=IDC_GRID,MFCGridCtrl,1342242816
Control2=IDC_CELL_NORMAL,button,1342308361
Control3=IDC_CELL_READONLY,button,1342177289
Control4=IDC_CELL_URL,button,1342177289
Control5=IDC_CELL_COMBO,button,1342177289
Control6=IDC_EDIT_ROWS,edit,1350639744
Control7=IDC_SPIN_ROW,msctls_updown32,1342177334
Control8=IDC_EDIT_COLS,edit,1350639744
Control9=IDC_SPIN_COL,msctls_updown32,1342177334
Control10=IDC_EDIT_FIXROWS,edit,1350639744
Control11=IDC_SPIN_FIXROW,msctls_updown32,1342177334
Control12=IDC_EDIT_FIXCOLS,edit,1350639744
Control13=IDC_SPIN_FIXCOL,msctls_updown32,1342177334
Control14=IDCANCEL,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_SIZEBOX,scrollbar,1342177308

