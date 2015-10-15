// PeParseDlg.h : header file
//

#if !defined(AFX_PEPARSEDLG_H__7F7F6D1C_E953_473A_B255_88670E64351F__INCLUDED_)
#define AFX_PEPARSEDLG_H__7F7F6D1C_E953_473A_B255_88670E64351F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPeParseDlg dialog

class CPeParseDlg : public CDialog
{
// Construction
public:
	VOID AddSecData(int nSecSize);
	DWORD AlignSize(int nSecSize, DWORD Alignment);
	VOID AddSec(char *szSecName, int nSecSize);
	VOID HexStrToInt(char *szHexStr, DWORD *pdwHexVal);
	VOID CalcAddr(int nInNum, DWORD dwAddr);
	int GetAddrInsecNum(DWORD dwAddr);
	DWORD GetAddr();
	VOID InitAddrEdit();
	VOID GetPeInfo();
	BOOL IsPeFileAndGetPePointer();
	BOOL FileCreate(char *szFileName);
	VOID FileClose();
	VOID ParseBasePe();
	VOID EnumSections();
	CPeParseDlg(CWnd* pParent = NULL);	// standard constructor

	PIMAGE_DOS_HEADER m_pDosHdr;	//Dosͷָ��
	PIMAGE_NT_HEADERS m_pNtHdr;		//PEͷָ��
	PIMAGE_SECTION_HEADER m_pSecHdr;	//�ڱ�ָ��

	LPVOID m_lpBase;				//ӳ����ͼָ��
	HANDLE m_hMap;					//ӳ����
	HANDLE m_hFile;					//�ļ����
	

// Dialog Data
	//{{AFX_DATA(CPeParseDlg)
	enum { IDD = IDD_PEPARSE_DIALOG };
	CEdit	m_VA;
	CEdit	m_RVA;
	CEdit	m_FileOffset;
	CListCtrl	m_List;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPeParseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_select;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPeParseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonBrowse();
	afx_msg void OnRadioVa();
	afx_msg void OnRadioRva();
	afx_msg void OnRADIOFileOffset();
	afx_msg void OnButtonCalc();
	afx_msg void OnButtonAddSec();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PEPARSEDLG_H__7F7F6D1C_E953_473A_B255_88670E64351F__INCLUDED_)
