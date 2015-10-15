// NoneDll_InjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NoneDll_Inject.h"
#include "NoneDll_InjectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define STRLEN 20

typedef struct _DATA {
	DWORD dwLoadLibrary;
	DWORD dwGetProcAddress;
	DWORD dwGetModuleHandle;
	DWORD dwGetModuleFileName;

	char User32Dll[STRLEN];
	char MessageBox[STRLEN];
	char Str[STRLEN];
}DATA, *PDATA;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

DWORD WINAPI RemoteThreadProc(LPVOID lpParam)
{
	PDATA pData = (PDATA)lpParam;
	
	HMODULE (__stdcall *MyLoadLibrary)(LPCTSTR);
	FARPROC (__stdcall *MyGetProcAddress)(HMODULE, LPCTSTR);
	HMODULE (__stdcall *MyGetModuleHandle)(LPCTSTR);
	int (__stdcall *MyMessageBox)(HWND, LPCTSTR, LPCTSTR, UINT);
	DWORD (__stdcall *MyGetModuleFileName)(HMODULE, LPCTSTR, DWORD);

	MyLoadLibrary = (HMODULE (__stdcall *)(LPCTSTR))pData->dwLoadLibrary;
	MyGetProcAddress = (FARPROC (__stdcall *)(HMODULE, LPCTSTR))pData->dwGetProcAddress;
	MyGetModuleHandle = (HMODULE (__stdcall *)(LPCTSTR))pData->dwGetModuleHandle;
	MyGetModuleFileName = (DWORD (__stdcall *)(HMODULE, LPCTSTR, DWORD))pData->dwGetModuleFileName;

	HMODULE hModule = MyLoadLibrary(pData->User32Dll);
	MyMessageBox = (int (__stdcall *)(HWND, LPCTSTR, LPCTSTR, UINT))MyGetProcAddress(hModule, pData->MessageBox);

	char szModuleName[MAX_PATH] = {0};
    MyGetModuleFileName(NULL, szModuleName, MAX_PATH);

	MyMessageBox(NULL, pData->Str, szModuleName, MB_OK);
	
	return 0;
}


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
// CNoneDll_InjectDlg dialog

CNoneDll_InjectDlg::CNoneDll_InjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNoneDll_InjectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNoneDll_InjectDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNoneDll_InjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNoneDll_InjectDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNoneDll_InjectDlg, CDialog)
	//{{AFX_MSG_MAP(CNoneDll_InjectDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Inject, OnBUTTONInject)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoneDll_InjectDlg message handlers

BOOL CNoneDll_InjectDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNoneDll_InjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNoneDll_InjectDlg::OnPaint() 
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
HCURSOR CNoneDll_InjectDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

VOID CNoneDll_InjectDlg::InjectCode(DWORD dwPid)
{
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
	if (hProcess == NULL)
	{
		return ;
	}

	DATA Data = {0};

	Data.dwLoadLibrary = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");
	Data.dwGetProcAddress = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"), "GetProcAddress");
	Data.dwGetModuleHandle = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"), "GetModuleHandleA");
	Data.dwGetModuleFileName = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"), "GetModuleFileNameA");

	lstrcpy(Data.User32Dll, "user32.dll");
	lstrcpy(Data.MessageBox, "MessageBoxA");
	lstrcpy(Data.Str, "Inject Code!");

	LPVOID lpData = VirtualAllocEx(hProcess, NULL, sizeof(DATA), MEM_COMMIT | MEM_RELEASE, PAGE_READWRITE);
	DWORD dwWriteNum = 0;
	WriteProcessMemory(hProcess, lpData, &Data, sizeof(DATA), &dwWriteNum);

	DWORD dwFunSize = 0x2000;
	LPVOID lpCode = VirtualAllocEx(hProcess, NULL, dwFunSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	WriteProcessMemory(hProcess, lpCode, RemoteThreadProc, dwFunSize, &dwWriteNum);

	HANDLE hRemoteThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)lpCode, lpData, 0, NULL);

	WaitForSingleObject(hProcess, INFINITE);

	CloseHandle(hRemoteThread);

	CloseHandle(hProcess);

}



void CNoneDll_InjectDlg::OnBUTTONInject() 
{
	// TODO: Add your control notification handler code here
	char pid[10];
	GetDlgItem(IDC_EDIT_PID)->GetWindowText(pid, 10);
	DWORD dwPid = atoi(pid);

	InjectCode(dwPid);
}
