// ManageProcessDlg.h : header file
//

#if !defined(AFX_MANAGEPROCESSDLG_H__B8D9E420_14B2_4A10_995C_209E39A5A366__INCLUDED_)
#define AFX_MANAGEPROCESSDLG_H__B8D9E420_14B2_4A10_995C_209E39A5A366__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CManageProcessDlg dialog

class CManageProcessDlg : public CDialog
{
// Construction
public:
	void DebugPrivilege();
	void ShowModule(int pid);
	void ShowProcess();
	CManageProcessDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CManageProcessDlg)
	enum { IDD = IDD_MANAGEPROCESS_DIALOG };
	CListCtrl	m_List2;
	CListCtrl	m_List1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManageProcessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CManageProcessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonDll();
	afx_msg void OnButtonStop();
	afx_msg void OnButtonExit();
	afx_msg void OnButtonRec();
	afx_msg void OnButtonEnd();
	afx_msg void OnButtonCreat();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGEPROCESSDLG_H__B8D9E420_14B2_4A10_995C_209E39A5A366__INCLUDED_)
