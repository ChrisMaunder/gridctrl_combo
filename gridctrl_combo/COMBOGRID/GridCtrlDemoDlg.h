// GridCtrlDemoDlg.h : header file
//

#if !defined(AFX_GRIDCTRLDEMODLG_H__34B6D7A6_9CDC_11D1_9C11_00A0243D1382__INCLUDED_)
#define AFX_GRIDCTRLDEMODLG_H__34B6D7A6_9CDC_11D1_9C11_00A0243D1382__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CGridCtrlDemoDlg dialog

#include "GridCtrl_src/GridCtrl.h"

class CGridCtrlDemoDlg : public CDialog
{
// Construction
public:
	CGridCtrlDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGridCtrlDemoDlg)
	enum { IDD = IDD_GRIDCTRLDEMO_DIALOG };
	CSpinButtonCtrl	m_RowSpin;
	CSpinButtonCtrl	m_FixRowSpin;
	CSpinButtonCtrl	m_FixColSpin;
	CSpinButtonCtrl	m_ColSpin;
	CStatic	m_GridRect;
	int		m_nFixCols;
	int		m_nFixRows;
	int		m_nCols;
	int		m_nRows;
	BOOL	m_bEditable;
	BOOL	m_bHorzLines;
	BOOL	m_bListMode;
	BOOL	m_bVertLines;
	BOOL	m_bSelectable;
	BOOL	m_bAllowColumnResize;
	BOOL	m_bAllowRowResize;
	BOOL	m_bHeaderSort;
	BOOL	m_bReadOnly;
	BOOL	m_bItalics;
	BOOL	m_btitleTips;
	BOOL	m_bSingleSelMode;
	BOOL	m_bCellURL;
	//}}AFX_DATA
	CGridCtrl m_Grid;
	CSize m_OldSize;

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGridCtrlDemoDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CImageList m_ImageList;

	// Generated message map functions
	//{{AFX_MSG(CGridCtrlDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnUpdateEditCols();
	afx_msg void OnUpdateEditFixcols();
	afx_msg void OnUpdateEditFixrows();
	afx_msg void OnUpdateEditRows();
	afx_msg void OnGridLines();
	afx_msg void OnListmode();
	afx_msg void OnEditable();
	afx_msg void OnPrintButton();
	afx_msg void OnAllowSelection();
	afx_msg void OnRowResize();
	afx_msg void OnColResize();
	afx_msg void OnFontButton();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHeaderSort();
	afx_msg void OnEditSelectall();
	afx_msg void OnAppAbout();
	afx_msg void OnReadOnly();
	afx_msg void OnItalics();
	afx_msg void OnTitletips();
	afx_msg void OnInsertRow();
	afx_msg void OnDeleteRow();
	afx_msg void OnSingleselmode();
	afx_msg void OnExpandToFit();
	afx_msg void OnAutoSize();
	afx_msg void OnFill();
	afx_msg void OnCellUrl();
	//}}AFX_MSG
    afx_msg void OnGridDblClick(NMHDR *pNotifyStruct, LRESULT* pResult);
    afx_msg void OnGridClick(NMHDR *pNotifyStruct, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
#ifndef GRIDCONTROL_NO_CLIPBOARD
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCopyOrCut(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRIDCTRLDEMODLG_H__34B6D7A6_9CDC_11D1_9C11_00A0243D1382__INCLUDED_)
