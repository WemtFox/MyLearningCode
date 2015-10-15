// ManagerServiceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ManagerService.h"
#include "ManagerServiceDlg.h"
#include "winsvc.h"


/*
//Win32Ӧ�ó������
#define SERVICE_WIN32 (SERVICE_WIN32_OWN_PROCESS| SERVICE_WIN32_SHARE_PROCESS)
//�����������
#define SERVICE_DRIVER (SERVICE_KERNEL_DRIVER|SERVICE_FILE_SYSTEM_DRIVER|SERVICE_RECOGNIZER_DRIVER)
*/

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
// CManagerServiceDlg dialog

CManagerServiceDlg::CManagerServiceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CManagerServiceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManagerServiceDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CManagerServiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManagerServiceDlg)
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CManagerServiceDlg, CDialog)
	//{{AFX_MSG_MAP(CManagerServiceDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	ON_BN_CLICKED(IDC_RADIO_WIN32, OnRadioWin32)
	ON_BN_CLICKED(IDC_RADIO_DRIVER, OnRadioDriver)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManagerServiceDlg message handlers

BOOL CManagerServiceDlg::OnInitDialog()
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
	//���ñ���
	SetWindowText("���������(by giantbranch)");

	m_List.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);

	m_List.InsertColumn(0,"���");
	m_List.InsertColumn(1,"������");
	m_List.InsertColumn(2,"��ʾ��");
	m_List.InsertColumn(3,"״̬");

	m_List.SetColumnWidth(0,LVSCW_AUTOSIZE_USEHEADER);
	m_List.SetColumnWidth(1,150);
	m_List.SetColumnWidth(2,300);
	m_List.SetColumnWidth(3,LVSCW_AUTOSIZE_USEHEADER);
	
	//ö�ٷ���(Ĭ��WIN32)
	CheckRadioButton(IDC_RADIO_WIN32,IDC_RADIO_DRIVER,IDC_RADIO_WIN32);
	ShowServiceList(SERVICE_WIN32);

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CManagerServiceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CManagerServiceDlg::OnPaint() 
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
HCURSOR CManagerServiceDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CManagerServiceDlg::ShowServiceList(DWORD dwServiceType)
{
	
	m_List.DeleteAllItems();

	SC_HANDLE hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);	//�򿪷��������

	if (NULL == hSCM)
	{
		AfxMessageBox("����������ʧ��");//����������ʧ��
		return ;
	}

	DWORD dwBufSize = 512 * sizeof(ENUM_SERVICE_STATUS);
	DWORD dwByteNeeded, dwServicesReturned;
	LPENUM_SERVICE_STATUS SerStatus = (LPENUM_SERVICE_STATUS)LocalAlloc(LPTR,64*1024);; 
	BOOL bRet = EnumServicesStatus(hSCM, 
				dwServiceType, 
				SERVICE_STATE_ALL, 
				SerStatus, 
				1024*64, 
				&dwByteNeeded, 
				&dwServicesReturned, 
				NULL);
	
	if (FALSE == bRet)
	{
		AfxMessageBox("ö�ٷ���ʧ��");
		CloseServiceHandle(hSCM);
		return ;
	}
	

	for (DWORD i = 0; i < dwServicesReturned; i++)
	{
		CString str;
		str.Format("%d", i);
		m_List.InsertItem(i, str);
		m_List.SetItemText(i, 1, SerStatus[i].lpServiceName);
		m_List.SetItemText(i, 2, SerStatus[i].lpDisplayName);
		
		//���ݷ��ص�״̬��ʾ��Ӧ����
		
		switch(SerStatus[i].ServiceStatus.dwCurrentState) {
		case SERVICE_PAUSED: 
			{
				m_List.SetItemText(i, 3, "��ͣ");
				break;
			}
		case SERVICE_STOP: 
			{
				m_List.SetItemText(i, 3, "ֹͣ");
				break;
			}
		case SERVICE_RUNNING: 
			{
				m_List.SetItemText(i, 3, "����");
				break;
			}
			
		default:
			m_List.SetItemText(i, 3, "����");
		}
	}

	CloseServiceHandle(hSCM);
	


    
}

void CManagerServiceDlg::OnButtonExit() 
{
	// TODO: Add your control notification handler code here
	EndDialog(IDCANCEL);
}

void CManagerServiceDlg::OnRadioWin32() 
{
	// TODO: Add your control notification handler code here
	ShowServiceList(SERVICE_WIN32);
}

void CManagerServiceDlg::OnRadioDriver() 
{
	// TODO: Add your control notification handler code here
	ShowServiceList(SERVICE_DRIVER);
}

void CManagerServiceDlg::OnButtonStop() 
{
	// TODO: Add your control notification handler code here
	//��ȡѡ�з��������

	POSITION pos = m_List.GetFirstSelectedItemPosition();	//��õ���ѡ��Ԫ�ص�λ��
	int nSelect = -1;

	while (pos)	//��while���Զ�ѡ
	{
		nSelect = m_List.GetNextSelectedItem(pos);	//���ѡ��Ԫ�ص�����
	}

	if (-1 == nSelect)
	{
		AfxMessageBox("��ѡ��Ҫɾ����������");
		return ;
	}

	//��ȡѡ�еķ�����
	char szServiceName[MAXBYTE] = {0};
	m_List.GetItemText(nSelect, 1, szServiceName, MAXBYTE);

	SC_HANDLE hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (NULL == hSCM)
	{
		AfxMessageBox("�򿪷��������ʧ��");
		return ;
	}

	SC_HANDLE hSCService = OpenService(hSCM, szServiceName, SERVICE_ALL_ACCESS);	//	�򿪷�����
	SERVICE_STATUS ServiceStatus;

	//ֹͣ����
	BOOL bRet = ControlService(hSCService,SERVICE_CONTROL_STOP, &ServiceStatus);
	if (bRet == TRUE)
	{
		m_List.SetItemText(nSelect, 3, "ֹͣ");
	}else{
		int n = GetLastError();
	}

	//�رվ��
	CloseServiceHandle(hSCM);
	CloseServiceHandle(hSCService);
	
}

void CManagerServiceDlg::OnButtonStart() 
{
	// TODO: Add your control notification handler code here
	//��ȡѡ�з��������

	POSITION pos = m_List.GetFirstSelectedItemPosition();	//��õ���ѡ��Ԫ�ص�λ��
	int nSelect = -1;

	while (pos)	//��while���Զ�ѡ
	{
		nSelect = m_List.GetNextSelectedItem(pos);	//���ѡ��Ԫ�ص�����
	}

	if (-1 == nSelect)
	{
		AfxMessageBox("��ѡ��Ҫɾ����������");
		return ;
	}

	//��ȡѡ�еķ�����
	char szServiceName[MAXBYTE] = {0};
	m_List.GetItemText(nSelect, 1, szServiceName, MAXBYTE);

	SC_HANDLE hSCM = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (NULL == hSCM)
	{
		AfxMessageBox("�򿪷��������ʧ��");
		return ;
	}
	
	SC_HANDLE hSCService = OpenService(hSCM, szServiceName, SERVICE_ALL_ACCESS);	//	�򿪷�����
	
	//��������
	BOOL bRet = StartService(hSCService, 0, NULL);
	if (bRet == TRUE)
	{
		m_List.SetItemText(nSelect, 3, "����");
	}else{
		int n = GetLastError();
	}
}
