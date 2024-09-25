; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CInPlaceList
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "gridctrldemo.h"
LastPage=0

ClassCount=8
Class1=CComboEdit
Class2=CInPlaceList
Class3=CGridCtrl
Class4=CGridDropTarget
Class5=CInPlaceEdit
Class6=CTitleTip
Class7=CGridCtrlDemoApp
Class8=CGridCtrlDemoDlg

ResourceCount=3
Resource1=IDD_GRIDCTRLDEMO_DIALOG
Resource2=IDD_ABOUTBOX (English (U.S.))
Resource3=IDR_MENU

[CLS:CComboEdit]
Type=0
BaseClass=CEdit
HeaderFile=GridCellCombo.h
ImplementationFile=GridCellCombo.cpp
LastObject=CComboEdit

[CLS:CInPlaceList]
Type=0
BaseClass=CComboBox
HeaderFile=GridCellCombo.h
ImplementationFile=GridCellCombo.cpp
LastObject=CInPlaceList
Filter=W
VirtualFilter=cWC

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

[DLG:IDD_GRIDCTRLDEMO_DIALOG]
Type=1
Class=CGridCtrlDemoDlg
ControlCount=37
Control1=IDC_INFO1,static,1342308352
Control2=IDC_INFO2,static,1342308352
Control3=IDC_GRID,MFCGridCtrl,1350631424
Control4=IDC_EDIT_ROWS,edit,1350639744
Control5=IDC_SPIN_ROW,msctls_updown32,1342177334
Control6=IDC_EDIT_COLS,edit,1350639744
Control7=IDC_SPIN_COL,msctls_updown32,1342177334
Control8=IDC_EDIT_FIXROWS,edit,1350639744
Control9=IDC_SPIN_FIXROW,msctls_updown32,1342177334
Control10=IDC_EDIT_FIXCOLS,edit,1350639744
Control11=IDC_SPIN_FIXCOL,msctls_updown32,1342177334
Control12=IDC_VERT_LINES,button,1342242819
Control13=IDC_HORZ_LINES,button,1342242819
Control14=IDC_ROW_RESIZE,button,1342242819
Control15=IDC_COL_RESIZE,button,1342242819
Control16=IDC_EDITABLE,button,1342242819
Control17=IDC_ALLOW_SELECTION,button,1342242819
Control18=IDC_LISTMODE,button,1342242819
Control19=IDC_HEADERSORT,button,1342242819
Control20=IDC_SINGLESELMODE,button,1342242819
Control21=IDC_READ_ONLY,button,1342242819
Control22=IDC_ITALICS,button,1342242819
Control23=IDC_CELL_URL,button,1342242819
Control24=IDC_FILL,button,1342242816
Control25=IDC_AUTO_SIZE,button,1342242816
Control26=IDC_EXPAND_TO_FIT,button,1342242816
Control27=IDC_INSERT_ROW,button,1342242816
Control28=IDC_DELETE_ROW,button,1342242816
Control29=IDC_TITLETIPS,button,1342242819
Control30=IDC_FONT_BUTTON,button,1342242816
Control31=IDC_PRINT_BUTTON,button,1342242816
Control32=IDCANCEL,button,1342242816
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,static,1342308352
Control35=IDC_STATIC,static,1342308352
Control36=IDC_STATIC,static,1342308352
Control37=IDC_SIZEBOX,scrollbar,1342177308

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
Class=?
Command1=ID_FILE_PRINT
Command2=ID_APP_EXIT
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_SELECTALL
Command7=ID_APP_ABOUT
CommandCount=7

