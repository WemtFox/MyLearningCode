// NoneDll_InjectDlg.h : header file
//

#if !defined(AFX_NONEDLL_INJECTDLG_H__5A19BFCB_5B22_4021_962C_84D01BA21386__INCLUDED_)
#define AFX_NONEDLL_INJECTDLG_H__5A19BFCB_5B22_4021_962C_84D01BA21386__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNoneDll_InjectDlg dialog

class CNoneDll_InjectDlg : public CDialog
{
// Construction
public:
	VOID InjectCode(DWORD dwPid);
	CNoneDll_InjectDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNoneDll_InjectDlg)
	enum { IDD = IDD_NONEDLL_INJECT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoneDll_InjectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNoneDll_InjectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONInject();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NONEDLL_INJECTDLG_H__5A19BFCB_5B22_4021_962C_84D01BA21386__INCLUDED_)
