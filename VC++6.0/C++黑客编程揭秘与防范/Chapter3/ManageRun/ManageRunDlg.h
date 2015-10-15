// ManageRunDlg.h : header file
//

#if !defined(AFX_MANAGERUNDLG_H__2DB40E38_243B_4FBF_9E39_9A92C49564EB__INCLUDED_)
#define AFX_MANAGERUNDLG_H__2DB40E38_243B_4FBF_9E39_9A92C49564EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CManageRunDlg dialog

class CManageRunDlg : public CDialog
{
// Construction
public:
	void ShowRunList();
	CManageRunDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CManageRunDlg)
	enum { IDD = IDD_MANAGERUN_DIALOG };
	CListCtrl	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManageRunDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CManageRunDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDel();
	afx_msg void OnButtonExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGERUNDLG_H__2DB40E38_243B_4FBF_9E39_9A92C49564EB__INCLUDED_)
