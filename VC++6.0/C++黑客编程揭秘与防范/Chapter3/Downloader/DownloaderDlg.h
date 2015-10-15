// DownloaderDlg.h : header file
//

#if !defined(AFX_DOWNLOADERDLG_H__FE692EA9_A299_4964_A363_DCFC93F5BFCA__INCLUDED_)
#define AFX_DOWNLOADERDLG_H__FE692EA9_A299_4964_A363_DCFC93F5BFCA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDownloaderDlg dialog

class CDownloaderDlg : public CDialog
{
// Construction
public:
	CDownloaderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDownloaderDlg)
	enum { IDD = IDD_DOWNLOADER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownloaderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDownloaderDlg)
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

#endif // !defined(AFX_DOWNLOADERDLG_H__FE692EA9_A299_4964_A363_DCFC93F5BFCA__INCLUDED_)
