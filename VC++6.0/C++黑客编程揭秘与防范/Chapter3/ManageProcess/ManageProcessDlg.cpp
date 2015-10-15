// ManageProcessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ManageProcess.h"
#include "ManageProcessDlg.h"
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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManageProcessDlg dialog

CManageProcessDlg::CManageProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CManageProcessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManageProcessDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CManageProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManageProcessDlg)
	DDX_Control(pDX, IDC_LIST2, m_List2);
	DDX_Control(pDX, IDC_LIST1, m_List1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CManageProcessDlg, CDialog)
	//{{AFX_MSG_MAP(CManageProcessDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DLL, OnButtonDll)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_REC, OnButtonRec)
	ON_BN_CLICKED(IDC_BUTTON_END, OnButtonEnd)
	ON_BN_CLICKED(IDC_BUTTON_CREAT, OnButtonCreat)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManageProcessDlg message handlers

BOOL CManageProcessDlg::OnInitDialog()
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
	//������ǰ����Ȩ��
	DebugPrivilege();
	
	//���ñ���
	SetWindowText("���̹�����(by giantbranch)");

	//��ʼ�����б�
	m_List1.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_List1.InsertColumn(0,"pid");
	m_List1.InsertColumn(1,"������");
	m_List1.SetColumnWidth(0,LVSCW_AUTOSIZE_USEHEADER);
	m_List1.SetColumnWidth(1,LVSCW_AUTOSIZE_USEHEADER);
	//��ʼ�����б�
	m_List2.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_List2.InsertColumn(0,"���");
	m_List2.InsertColumn(1,"DLL��");
	m_List2.InsertColumn(2,"DLL·��");
	m_List2.SetColumnWidth(0,LVSCW_AUTOSIZE_USEHEADER);
	m_List2.SetColumnWidth(1,100);
	m_List2.SetColumnWidth(2,LVSCW_AUTOSIZE_USEHEADER);

	//ö�ٽ���
	ShowProcess();
	


	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CManageProcessDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CManageProcessDlg::OnPaint() 
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
HCURSOR CManageProcessDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CManageProcessDlg::ShowProcess()
{
	m_List1.DeleteAllItems();
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	
	if (hSnap == NULL)
	{
		AfxMessageBox("��ȡ���̿���ʧ��");
	}

	PROCESSENTRY32 pe32 = {0};
	pe32.dwSize = sizeof(PROCESSENTRY32);
	BOOL bRet = Process32First(hSnap, &pe32);
	int i = 0;
	while (bRet)
	{
		CString str;
		str.Format("%d", pe32.th32ProcessID);
		m_List1.InsertItem(i, str);
		m_List1.SetItemText(i, 1, pe32.szExeFile);
		bRet = Process32Next(hSnap, &pe32);
		i++;
	}
	
	CloseHandle(hSnap);
}

void CManageProcessDlg::ShowModule(int pid)
{

	m_List2.DeleteAllItems();
	MODULEENTRY32 Me32 = {0};
	Me32.dwSize = sizeof(MODULEENTRY32);
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
	
	if (hSnap == NULL)
	{
		AfxMessageBox("��ȡDLL����ʧ��");
		return ;
	} 
	BOOL bRet = Module32First(hSnap, &Me32);
	if (bRet == NULL)
	{
		AfxMessageBox("Ȩ�޲���");
		return ;
	}
	int i= 0;
	while (bRet)
	{
		CString str;
		str.Format("%d", i);
		m_List2.InsertItem(i, str);
		m_List2.SetItemText(i, 1, Me32.szModule);
		m_List2.SetItemText(i, 2, Me32.szExePath);
		bRet = Module32Next(hSnap, &Me32);
		i++;
	}
}

void CManageProcessDlg::OnButtonDll() 
{
	// TODO: Add your control notification handler code here
	POSITION pos = m_List1.GetFirstSelectedItemPosition();	//��õ���ѡ��Ԫ�ص�λ��
	int nSelect = -1;

	while (pos)	//��while���Զ�ѡ
	{
		nSelect = m_List1.GetNextSelectedItem(pos);	//���ѡ��Ԫ�ص�����
	}

	if (-1 == nSelect)
	{
		AfxMessageBox("��ѡ�����");
		return ;
	}
	int pid;
	char pidChar[MAXBYTE] = {0};
	m_List1.GetItemText(nSelect, 0, pidChar,MAXBYTE);
	pid = atoi(pidChar);	//��char����ת��Ϊint����
	ShowModule(pid);
	
}

//��������Ȩ�ޣ���Щ����ûȨ
void CManageProcessDlg::DebugPrivilege()
{
	HANDLE hToken = NULL;

	BOOL bRet = OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken);

	if (bRet == TRUE)
	{
		TOKEN_PRIVILEGES tp;
		tp.PrivilegeCount = 1;
		LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
		tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL);

		CloseHandle(hToken);
	}
}

void CManageProcessDlg::OnButtonStop() 
{
	// TODO: Add your control notification handler code here
	POSITION pos = m_List1.GetFirstSelectedItemPosition();	//��õ���ѡ��Ԫ�ص�λ��
	int nSelect = -1;

	while (pos)	//��while���Զ�ѡ
	{
		nSelect = m_List1.GetNextSelectedItem(pos);	//���ѡ��Ԫ�ص�����
	}

	if (-1 == nSelect)
	{
		AfxMessageBox("��ѡ�����");
		return ;
	}
	DWORD pid;
	char pidChar[MAXBYTE] = {0};
	m_List1.GetItemText(nSelect, 0, pidChar,MAXBYTE);
	pid = atoi(pidChar);	//��char����ת��Ϊint����

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, pid);
	if (hSnap == INVALID_HANDLE_VALUE)
	{
		AfxMessageBox("CreateToolhelp32Snapshot Error");
		return ;
	}

	THREADENTRY32 Te32 = {0};
	Te32.dwSize = sizeof(THREADENTRY32);
	BOOL bRet = Thread32First(hSnap, &Te32);

	//-->����OpenThread��������  ������WINAPI(API����_stdcall����)  
	typedef HANDLE (WINAPI * OPENTHREADFUN)(DWORD dwDesiredAccess,BOOL bInheritHandle,DWORD dwThreadId);  
  
  
	//1:kernel32 �󲿷ֳ����Զ�������kernel32.dll  �����ٻ�þ��֮ǰ����ҪLoadlibray  
	HMODULE hKernel32 = ::GetModuleHandle(_T("kernel32.dll"));  
  
	//2��ú���ָ��  
	OPENTHREADFUN pFun = (OPENTHREADFUN)GetProcAddress(hKernel32,_T("OpenThread"));

	while (bRet)
	{
		if (Te32.th32OwnerProcessID == pid)
		{
			//3����  
			HANDLE hThread = pFun(THREAD_ALL_ACCESS,FALSE,Te32.th32ThreadID);  
			//HANDLE hThread = OpenThead(THREAD_ALL_ACCESS, false, Te32.th32ThreadID);

			SuspendThread(hThread);

			CloseHandle(hThread);
		}

		bRet = Thread32Next(hSnap, &Te32);
	}
	AfxMessageBox("��ͣ�ɹ�");

}

void CManageProcessDlg::OnButtonExit() 
{
	// TODO: Add your control notification handler code here
	EndDialog(IDCANCEL);
}


void CManageProcessDlg::OnButtonRec() 
{
	// TODO: Add your control notification handler code here
	POSITION pos = m_List1.GetFirstSelectedItemPosition();	//��õ���ѡ��Ԫ�ص�λ��
	int nSelect = -1;

	while (pos)	//��while���Զ�ѡ
	{
		nSelect = m_List1.GetNextSelectedItem(pos);	//���ѡ��Ԫ�ص�����
	}

	if (-1 == nSelect)
	{
		AfxMessageBox("��ѡ�����");
		return ;
	}
	DWORD pid;
	char pidChar[MAXBYTE] = {0};
	m_List1.GetItemText(nSelect, 0, pidChar,MAXBYTE);
	pid = atoi(pidChar);	//��char����ת��Ϊint����

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, pid);
	if (hSnap == INVALID_HANDLE_VALUE)
	{
		AfxMessageBox("CreateToolhelp32Snapshot Error");
		return ;
	}

	THREADENTRY32 Te32 = {0};
	Te32.dwSize = sizeof(THREADENTRY32);
	BOOL bRet = Thread32First(hSnap, &Te32);

	//-->����OpenThread��������  ������WINAPI(API����_stdcall����)  
	typedef HANDLE (WINAPI * OPENTHREADFUN)(DWORD dwDesiredAccess,BOOL bInheritHandle,DWORD dwThreadId);  
  
  
	//1:kernel32 �󲿷ֳ����Զ�������kernel32.dll  �����ٻ�þ��֮ǰ����ҪLoadlibray  
	HMODULE hKernel32 = ::GetModuleHandle(_T("kernel32.dll"));  
  
	//2��ú���ָ��  
	OPENTHREADFUN pFun = (OPENTHREADFUN)GetProcAddress(hKernel32,_T("OpenThread"));

	while (bRet)
	{
		if (Te32.th32OwnerProcessID == pid)
		{
			//3����  
			HANDLE hThread = pFun(THREAD_ALL_ACCESS,FALSE,Te32.th32ThreadID);  

			ResumeThread(hThread);

			CloseHandle(hThread);
		}

		bRet = Thread32Next(hSnap, &Te32);
	}
	AfxMessageBox("�ָ��ɹ�");
}

//��������
void CManageProcessDlg::OnButtonEnd() 
{
	// TODO: Add your control notification handler code here
	POSITION pos = m_List1.GetFirstSelectedItemPosition();	//��õ���ѡ��Ԫ�ص�λ��
	int nSelect = -1;

	while (pos)	//��while���Զ�ѡ
	{
		nSelect = m_List1.GetNextSelectedItem(pos);	//���ѡ��Ԫ�ص�����
	}

	if (-1 == nSelect)
	{
		AfxMessageBox("��ѡ�����");
		return ;
	}
	DWORD pid;
	char pidChar[MAXBYTE] = {0};
	m_List1.GetItemText(nSelect, 0, pidChar,MAXBYTE);
	pid = atoi(pidChar);	//��char����ת��Ϊint����
	
	HANDLE HNoteHandle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	if (HNoteHandle == NULL)
	{
		return ;
	}
	TerminateProcess(HNoteHandle, 0);
	CloseHandle(HNoteHandle);

	ShowProcess();
}

//��������
void CManageProcessDlg::OnButtonCreat() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg( TRUE, _T( ".exe" ), _T( "test.exe" ), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T( "Ӧ�ó���(exe)|*.exe|�����ļ�|*||" ) );
	if ( dlg.DoModal() == IDOK ) 
	{
		CString path = dlg.GetPathName();	//��ȡ·��
		//AfxMessageBox(path);
		WinExec(path, SW_SHOW);	//���̴���
	}

}
