// TerminateProcessDlg.h : header file
//

#if !defined(AFX_TERMINATEPROCESSDLG_H__7C0A6544_60D0_44B3_96F2_952F84BFF000__INCLUDED_)
#define AFX_TERMINATEPROCESSDLG_H__7C0A6544_60D0_44B3_96F2_952F84BFF000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTerminateProcessDlg dialog

class CTerminateProcessDlg : public CDialog
{
// Construction
public:
	CTerminateProcessDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTerminateProcessDlg)
	enum { IDD = IDD_TERMINATEPROCESS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTerminateProcessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTerminateProcessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TERMINATEPROCESSDLG_H__7C0A6544_60D0_44B3_96F2_952F84BFF000__INCLUDED_)
