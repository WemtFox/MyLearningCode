// SimpleConnectDlg.h : header file
//

#if !defined(AFX_SIMPLECONNECTDLG_H__AFFF19CA_ED75_456A_9076_D43EAFE9CFC2__INCLUDED_)
#define AFX_SIMPLECONNECTDLG_H__AFFF19CA_ED75_456A_9076_D43EAFE9CFC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSimpleConnectDlg dialog

class CSimpleConnectDlg : public CDialog
{
// Construction
public:
	CSimpleConnectDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSimpleConnectDlg)
	enum { IDD = IDD_SIMPLECONNECT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimpleConnectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSimpleConnectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMPLECONNECTDLG_H__AFFF19CA_ED75_456A_9076_D43EAFE9CFC2__INCLUDED_)
