// AutoRunDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AutoRun.h"
#include "AutoRunDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//创建目录
#define AUTORUN "autorun.inf"
//创建无法删除额的目录
#define IMMUNITY "\\Immunity...\\"
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoRunDlg dialog

CAutoRunDlg::CAutoRunDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutoRunDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAutoRunDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutoRunDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutoRunDlg)
	DDX_Control(pDX, IDC_COMBO_DRIVER, m_ComboDriver);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAutoRunDlg, CDialog)
	//{{AFX_MSG_MAP(CAutoRunDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_IMMUNE, OnButtonImmune)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, OnButtonCancle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoRunDlg message handlers

BOOL CAutoRunDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	//加载图标
	HICON hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	//设置图标
	SetIcon(hIcon, FALSE);
	// TODO: Add extra initialization here

	//设置标题
	SetWindowText("分区免疫工具(by gaintbranch)");
	

	
	char szDriverString[MAXBYTE] = {0},a[MAXBYTE] = {0};
	char *pTmp = NULL;
	
	SetDlgItemText(IDC_COMBO_DRIVER, _T("请选择要免疫的盘符"));
	GetLogicalDrives();
	GetLogicalDriveStrings(MAXBYTE, szDriverString);


	

	
	
	//书本源码
	pTmp = szDriverString;
	while (*pTmp)
	{
		m_ComboDriver.AddString(pTmp);
		pTmp+=4;
	}
	
	/*
	//参考网上的再修改
	for(pTmp=szDriverString;*pTmp;pTmp++)
	{
	//MessageBox(pTmp);
	m_ComboDriver.AddString(pTmp);
	while(*pTmp!='\0') pTmp++;
	}
	*/
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAutoRunDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAutoRunDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAutoRunDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAutoRunDlg::OnButtonImmune() 
{
	// TODO: Add your control notification handler code here
	char szPath[MAXBYTE] = {0};
	
	GetDlgItemText(IDC_COMBO_DRIVER, szPath, MAX_PATH);

	//创建autorun.inf文件夹
	strcat(szPath, AUTORUN);
	BOOL bRet = CreateDirectory(szPath, NULL);
	if (!bRet)
	{
		AfxMessageBox("无法免疫该磁盘！可能已经免疫，或者该磁盘为不可写状态！");
		return ;	
	}
	//创建无法删除的用来进行免疫的文件夹
	strcat(szPath, IMMUNITY);
	bRet = CreateDirectory(szPath, NULL);
	if (!bRet)
	{
		AfxMessageBox("无法免疫该磁盘！可能已经免疫，或者该磁盘为不可写状态！");
	}else
	{
		AfxMessageBox("免疫成功");
	}

	
	

}

void CAutoRunDlg::OnButtonCancle() 
{
	// TODO: Add your control notification handler code here
	char szPath[MAX_PATH] = {0};

	GetDlgItemText(IDC_COMBO_DRIVER, szPath, MAX_PATH);
	strcat(szPath, AUTORUN);
	strcat(szPath, IMMUNITY);
	RemoveDirectory(szPath);

	ZeroMemory(szPath, MAX_PATH);

	GetDlgItemText(IDC_COMBO_DRIVER, szPath, MAX_PATH);
	strcat(szPath, AUTORUN);
	RemoveDirectory(szPath);
	MessageBox("取消免疫成功");

}

