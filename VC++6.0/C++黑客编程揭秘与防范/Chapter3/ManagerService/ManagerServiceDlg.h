// ManagerServiceDlg.h : header file
//

#if !defined(AFX_MANAGERSERVICEDLG_H__F194DE9C_488E_4ACB_9589_A8C53D453329__INCLUDED_)
#define AFX_MANAGERSERVICEDLG_H__F194DE9C_488E_4ACB_9589_A8C53D453329__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CManagerServiceDlg dialog

class CManagerServiceDlg : public CDialog
{
// Construction
public:
	void ShowServiceList(DWORD dwServiceType);
	CManagerServiceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CManagerServiceDlg)
	enum { IDD = IDD_MANAGERSERVICE_DIALOG };
	CListCtrl	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManagerServiceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CManagerServiceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonExit();
	afx_msg void OnRadioWin32();
	afx_msg void OnRadioDriver();
	afx_msg void OnButtonStop();
	afx_msg void OnButtonStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGERSERVICEDLG_H__F194DE9C_488E_4ACB_9589_A8C53D453329__INCLUDED_)
