// Dll_Inject_UnInjectDlg.h : header file
//

#if !defined(AFX_DLL_INJECT_UNINJECTDLG_H__6926595E_1E65_4889_8C78_BEC43A717BF5__INCLUDED_)
#define AFX_DLL_INJECT_UNINJECTDLG_H__6926595E_1E65_4889_8C78_BEC43A717BF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDll_Inject_UnInjectDlg dialog

class CDll_Inject_UnInjectDlg : public CDialog
{
// Construction
public:
	VOID UnInjectDll(DWORD dwPid, char *szDllName);
	VOID InjectDll(DWORD dwPid, char *szDllName);
	CDll_Inject_UnInjectDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDll_Inject_UnInjectDlg)
	enum { IDD = IDD_DLL_INJECT_UNINJECT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDll_Inject_UnInjectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDll_Inject_UnInjectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONInject();
	afx_msg void OnBUTTONUnInject();
	afx_msg void OnButtonBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLL_INJECT_UNINJECTDLG_H__6926595E_1E65_4889_8C78_BEC43A717BF5__INCLUDED_)
