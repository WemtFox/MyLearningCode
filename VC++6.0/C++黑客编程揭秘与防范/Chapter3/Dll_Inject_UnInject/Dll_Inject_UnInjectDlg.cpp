// Dll_Inject_UnInjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Dll_Inject_UnInject.h"
#include "Dll_Inject_UnInjectDlg.h"
#include "Tlhelp32.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CDll_Inject_UnInjectDlg dialog

CDll_Inject_UnInjectDlg::CDll_Inject_UnInjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDll_Inject_UnInjectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDll_Inject_UnInjectDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDll_Inject_UnInjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDll_Inject_UnInjectDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDll_Inject_UnInjectDlg, CDialog)
	//{{AFX_MSG_MAP(CDll_Inject_UnInjectDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Inject, OnBUTTONInject)
	ON_BN_CLICKED(IDC_BUTTON_UnInject, OnBUTTONUnInject)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDll_Inject_UnInjectDlg message handlers

BOOL CDll_Inject_UnInjectDlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here
	//设置标题
	SetWindowText("DLL注入/卸载器");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDll_Inject_UnInjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDll_Inject_UnInjectDlg::OnPaint() 
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
HCURSOR CDll_Inject_UnInjectDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

VOID CDll_Inject_UnInjectDlg::InjectDll(DWORD dwPid, char *szDllName)
{
	//szDllName = "D:\\All_Code\\VC++6.0\\C++黑客编程揭秘与防范\\Chapter3\\FirstDll\\Debug\\FirstDll.dll";
	if (dwPid == 0 || strlen(szDllName) == 0)
	{
		return ;
	}

	char *pFunName = "LoadLibraryA";

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
	if (hProcess == NULL)
	{
		AfxMessageBox("打开进程失败");
		return ;
	}

	int nDllLen = strlen(szDllName) + sizeof(char);

	PVOID pDllAddr = VirtualAllocEx(hProcess, NULL, nDllLen,MEM_COMMIT, PAGE_READWRITE);
	if (pDllAddr == NULL)
	{
		AfxMessageBox("申请内存失败");
		CloseHandle(hProcess);
		return ;
	}

	DWORD dwWriteNum = 0;
	WriteProcessMemory(hProcess, pDllAddr, szDllName, nDllLen, &dwWriteNum);

	FARPROC pFunAddr = GetProcAddress(GetModuleHandle("kernel32.dll"), pFunName);

	HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)pFunAddr, pDllAddr,0 ,NULL);
	if (hThread == NULL)
	{
		AfxMessageBox("注入线程失败");
		return ;
	}
	GetLastError(); 
	WaitForSingleObject(hThread, INFINITE);

	CloseHandle(hThread);
	CloseHandle(hProcess);
	AfxMessageBox("注入成功");

}

void CDll_Inject_UnInjectDlg::OnBUTTONInject() 
{
	// TODO: Add your control notification handler code here
	char szDllName[100], pid[10];
	GetDlgItem(IDC_EDIT_PATH)->GetWindowText(szDllName, 100);
	GetDlgItem(IDC_EDIT_PID)->GetWindowText(pid, 10);
	DWORD dwPid = atoi(pid);

	InjectDll(dwPid, szDllName);
}

void CDll_Inject_UnInjectDlg::OnBUTTONUnInject() 
{
	// TODO: Add your control notification handler code here
	char szDllName[100], pid[10];
	GetDlgItem(IDC_EDIT_PATH)->GetWindowText(szDllName, 100);
	GetDlgItem(IDC_EDIT_PID)->GetWindowText(pid, 10);
	DWORD dwPid = atoi(pid);

	UnInjectDll(dwPid, szDllName);
	
}

VOID CDll_Inject_UnInjectDlg::UnInjectDll(DWORD dwPid, char *szDllName)
{
	if (dwPid == 0 || strlen(szDllName) == 0)
	{
		return ;
	}
	
	/************************************************************************/
	/* 判断当前进程中是否含有要卸载的dll                                                                     */
	/************************************************************************/
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPid);
	MODULEENTRY32 Me32 = {0};
	Me32.dwSize =sizeof(MODULEENTRY32);

	BOOL bRet = Module32First(hSnap, &Me32);
	BOOL flag = FALSE;
	while (bRet)
	{
		if (strcmp(Me32.szExePath, szDllName) == 0)
		{	
			flag = TRUE;
			break;
		}
		bRet = Module32Next(hSnap, &Me32);
	}
	if (flag == FALSE)
	{
		AfxMessageBox("当前进程没有该dll，无需卸载");
		return ;
	}
	CloseHandle(hSnap);
	char *pFunName = "FreeLibrary";
	
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
	if (hProcess == NULL)
	{
		AfxMessageBox("打开进程失败");
		return ;
	}

	/************************************************************************/
	/* 获取 FreeLibrary 函数地址，并调用它                                                   
	/************************************************************************/
	FARPROC pFunAddr = GetProcAddress(GetModuleHandle("kernel32.dll"), pFunName);

	HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)pFunAddr, Me32.hModule,0 ,NULL);
	if (hThread == NULL)
	{
		AfxMessageBox("卸载失败");
		return ;
	}
	GetLastError(); 
	WaitForSingleObject(hThread, INFINITE);

	CloseHandle(hThread);
	CloseHandle(hProcess);
	AfxMessageBox("卸载成功");
}
