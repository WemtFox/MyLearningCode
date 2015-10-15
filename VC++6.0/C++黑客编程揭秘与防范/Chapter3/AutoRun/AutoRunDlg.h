// AutoRunDlg.h : header file
//

#if !defined(AFX_AUTORUNDLG_H__AF765098_B6D1_4B92_84AD_9AB4EBC39E3A__INCLUDED_)
#define AFX_AUTORUNDLG_H__AF765098_B6D1_4B92_84AD_9AB4EBC39E3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAutoRunDlg dialog

class CAutoRunDlg : public CDialog
{
// Construction
public:
	CAutoRunDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAutoRunDlg)
	enum { IDD = IDD_AUTORUN_DIALOG };
	CComboBox	m_ComboDriver;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoRunDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAutoRunDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonImmune();
	afx_msg void OnButtonCancle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTORUNDLG_H__AF765098_B6D1_4B92_84AD_9AB4EBC39E3A__INCLUDED_)
