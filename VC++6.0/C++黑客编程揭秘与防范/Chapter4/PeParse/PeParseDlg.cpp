// PeParseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PeParse.h"
#include "PeParseDlg.h"

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
// CPeParseDlg dialog

CPeParseDlg::CPeParseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPeParseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPeParseDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPeParseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPeParseDlg)
	DDX_Control(pDX, IDC_EDIT_VA, m_VA);
	DDX_Control(pDX, IDC_EDIT_RVA, m_RVA);
	DDX_Control(pDX, IDC_EDIT_FileOffset, m_FileOffset);
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPeParseDlg, CDialog)
	//{{AFX_MSG_MAP(CPeParseDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BROWSE, OnButtonBrowse)
	ON_BN_CLICKED(IDC_RADIO_VA, OnRadioVa)
	ON_BN_CLICKED(IDC_RADIO_RVA, OnRadioRva)
	ON_BN_CLICKED(IDC_RADIO_FileOffset, OnRADIOFileOffset)
	ON_BN_CLICKED(IDC_BUTTON_CALC, OnButtonCalc)
	ON_BN_CLICKED(IDC_BUTTON_ADD_SEC, OnButtonAddSec)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPeParseDlg message handlers

BOOL CPeParseDlg::OnInitDialog()
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
	SetWindowText("PE�ļ��鿴��(by giantbranch)");

	//��ʼ�����б�
	m_List.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	m_List.InsertColumn(0,"����");
	m_List.InsertColumn(1,"V.ƫ��");
	m_List.InsertColumn(2,"V.��С");
	m_List.InsertColumn(3,"R.ƫ��");
	m_List.InsertColumn(4,"R.��С");
	m_List.InsertColumn(5,"��־");
	m_List.SetColumnWidth(0,60);
	m_List.SetColumnWidth(1,70);
	m_List.SetColumnWidth(2,70);
	m_List.SetColumnWidth(3,70);
	m_List.SetColumnWidth(4,70);
	m_List.SetColumnWidth(5,70);

	InitAddrEdit();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPeParseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPeParseDlg::OnPaint() 
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
HCURSOR CPeParseDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//���
void CPeParseDlg::OnButtonBrowse() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CFileDialog dlg( TRUE, _T( ".exe" ), _T( "test.exe" ), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T( "Ӧ�ó���(exe)|*.exe|�����ļ�|*||" ) );
	if ( dlg.DoModal() == IDOK ) 
	{
		CString path = dlg.GetPathName();	//��ȡ·��
		//AfxMessageBox(path);
		const char* key = (LPCSTR)path;
		GetDlgItem(IDC_EDIT_PATH)->SetWindowText(key);

		char* FileName = new char[200];//�㹻��

		strcpy(FileName,key);

		//���ļ�������ӳ����ͼ
		FileCreate(FileName);
		//�ж��Ƿ�Ϊpe�ļ�������ȡ��ؽṹָ��
		IsPeFileAndGetPePointer();
		//��������pe�ֶ�
		ParseBasePe();
		//ö�ٽڱ�
		EnumSections();

		GetPeInfo();
	}

	
}

//ö�ٽڱ�
VOID CPeParseDlg::EnumSections()
{
	int nSecNum = m_pNtHdr->FileHeader.NumberOfSections;

	int i = 0;
	CString StrTmp;

	for (i = 0; i < nSecNum; i++)
	{
		m_List.InsertItem (i, (const char *)m_pSecHdr[i].Name);

		StrTmp.Format("%08X", m_pSecHdr[i].VirtualAddress);
		m_List.SetItemText(i, 1, StrTmp);

		StrTmp.Format("%08X", m_pSecHdr[i].Misc.VirtualSize);
		m_List.SetItemText(i, 2, StrTmp);

		StrTmp.Format("%08X", m_pSecHdr[i].PointerToRawData);
		m_List.SetItemText(i, 3, StrTmp);

		StrTmp.Format("%08X", m_pSecHdr[i].SizeOfRawData);
		m_List.SetItemText(i, 4, StrTmp);

		StrTmp.Format("%08X", m_pSecHdr[i].Characteristics);
		m_List.SetItemText(i, 5, StrTmp);

	}
}

//��������pe�ֶ�
VOID CPeParseDlg::ParseBasePe()
{
	CString StrTmp;

	//��ڵ�ַ
	StrTmp.Format("%08X", m_pNtHdr->OptionalHeader.AddressOfEntryPoint);
	SetDlgItemText(IDC_EDIT_IN, StrTmp);

	//ӳ�����ַ
	StrTmp.Format("%08X", m_pNtHdr->OptionalHeader.ImageBase);
	SetDlgItemText(IDC_EDIT_BASE, StrTmp);

	//�������汾��
	StrTmp.Format("%d.%d", m_pNtHdr->OptionalHeader.MajorLinkerVersion, m_pNtHdr->OptionalHeader.MinorLinkerVersion);
	SetDlgItemText(IDC_EDIT_LINK_VER, StrTmp);

	//�ڱ�����
	StrTmp.Format("%02X", m_pNtHdr->FileHeader.NumberOfSections);
	SetDlgItemText(IDC_EDIT_NUM, StrTmp);

	//�ļ������С
	StrTmp.Format("%08X", m_pNtHdr->OptionalHeader.FileAlignment);
	SetDlgItemText(IDC_EDIT_FILE, StrTmp);

	//�ڴ�����С
	StrTmp.Format("%08X", m_pNtHdr->OptionalHeader.SectionAlignment);
	SetDlgItemText(IDC_EDIT_MEMORY, StrTmp);
}

//�ر��ļ�
VOID CPeParseDlg::FileClose()
{
	UnmapViewOfFile(m_lpBase);
}

//���ļ�������ӳ����ͼ
BOOL CPeParseDlg::FileCreate(char *szFileName)
{
	BOOL bRet = FALSE;

	m_hFile = CreateFile(szFileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (m_hFile == INVALID_HANDLE_VALUE)
	{
		return bRet;
	}
	
	m_hMap = CreateFileMapping(m_hFile, NULL, PAGE_READWRITE |SEC_IMAGE, 0, 0, 0);
	if (m_hMap == NULL)
	{
		CloseHandle(m_hFile);
		return bRet;
	}

	m_lpBase = MapViewOfFile(m_hMap, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
	if (m_lpBase == NULL)
	{
		CloseHandle(m_hMap);
		CloseHandle(m_hFile);
		return bRet;
	}
	bRet = TRUE;
	return bRet;
}

//�ж��Ƿ�Ϊpe�ļ�������ȡ��ؽṹָ��
BOOL CPeParseDlg::IsPeFileAndGetPePointer()
{
	BOOL bRet = FALSE;

	m_pDosHdr = (PIMAGE_DOS_HEADER)m_lpBase;

	if (m_pDosHdr->e_magic != IMAGE_DOS_SIGNATURE)
	{
		return bRet;
	}

	m_pNtHdr = (PIMAGE_NT_HEADERS)((DWORD)m_lpBase + m_pDosHdr->e_lfanew);

	if (m_pNtHdr->Signature != IMAGE_NT_SIGNATURE)
	{
		return bRet;
	}

	m_pSecHdr = (PIMAGE_SECTION_HEADER)((DWORD)&(m_pNtHdr->OptionalHeader)+m_pNtHdr->FileHeader.SizeOfOptionalHeader);
	
	bRet = TRUE;
	return bRet;
}


#define NAMELEN 20
#define SIGNLEN 32

typedef struct _SIGN
{
    char szName[NAMELEN];
    BYTE bSign[SIGNLEN + 1];
}SIGN, *PSIGN;

SIGN Sign[2] = 
{
    {
        // VC6
        "VC6",
        "\x55\x8B\xEC\x6A\xFF\x68\xC0\x54\x41\x00" \
        "\x68\xF8\x26\x40\x00\x64\xA1\x00\x00\x00" \
        "\x00\x50\x64\x89\x25\x00\x00\x00\x00\x83" \
        "\xC4\x94"
    },
    {
        // ASPACK
        "ASPACK",
        "\x60\xE8\x03\x00\x00\x00\xE9\xEB\x04\x5D" \
        "\x45\x55\xC3\xE8\x01\x00\x00\x00\xEB\x5D" \
        "\xBB\xED\xFF\xFF\xFF\x03\xDD\x81\xEB" \
        "\x00\xB0\x01"
    }
};


VOID CPeParseDlg::GetPeInfo()
{
	PBYTE pSign = NULL;

	//PE�ļ����λ��
	pSign = (PBYTE)((DWORD)m_lpBase + m_pNtHdr->OptionalHeader.AddressOfEntryPoint);
	
	if ( memcmp(Sign[0].bSign, pSign, SIGNLEN) == 0 )
    {
        SetDlgItemText(IDC_EDIT_PEINFO, Sign[0].szName);
    }
    else if ( memcmp(Sign[1].bSign, pSign, SIGNLEN) == 0  )
    {
        SetDlgItemText(IDC_EDIT_PEINFO, Sign[1].szName);
    }
    else
    {
        SetDlgItemText(IDC_EDIT_PEINFO, "δ֪");
    }


}

void CPeParseDlg::OnRadioVa() 
{
	// TODO: Add your control notification handler code here
	m_VA.EnableWindow(TRUE);
	m_RVA.EnableWindow(FALSE);
	m_FileOffset.EnableWindow(FALSE);
	
	m_select = 1;
}

void CPeParseDlg::OnRadioRva() 
{
	// TODO: Add your control notification handler code here
	m_VA.EnableWindow(FALSE);
	m_RVA.EnableWindow(TRUE);
	m_FileOffset.EnableWindow(FALSE);

	m_select = 2;
}

void CPeParseDlg::OnRADIOFileOffset() 
{
	// TODO: Add your control notification handler code here
	m_VA.EnableWindow(FALSE);
	m_RVA.EnableWindow(FALSE);
	m_FileOffset.EnableWindow(TRUE);
	
	m_select = 3;
}

VOID CPeParseDlg::InitAddrEdit()
{
	m_VA.EnableWindow(FALSE);
	m_RVA.EnableWindow(FALSE);
	m_FileOffset.EnableWindow(FALSE);
}

void CPeParseDlg::OnButtonCalc() 
{
	// TODO: Add your control notification handler code here
	DWORD dwAddr = 0;
	
	//���ó�Ա��������ȡ��ַ
	dwAddr = GetAddr();

	//��ַ���ڵĽ�
	int nInNum = GetAddrInsecNum(dwAddr);

	//����������ַ
	CalcAddr(nInNum, dwAddr);

}

DWORD CPeParseDlg::GetAddr()
{
	char szAddr[10] = {0};
	DWORD dwAddr = 0;
	switch(m_select) {
		case 1:
			GetDlgItemText(IDC_EDIT_VA, szAddr, 10);
			HexStrToInt(szAddr, &dwAddr);
			break;
		case 2:
			GetDlgItemText(IDC_EDIT_RVA, szAddr, 10);
			HexStrToInt(szAddr, &dwAddr);
			break;
		case 3:
			GetDlgItemText(IDC_EDIT_FileOffset, szAddr, 10);
			HexStrToInt(szAddr, &dwAddr);
			break;
	}
	return dwAddr;
}

int CPeParseDlg::GetAddrInsecNum(DWORD dwAddr)
{
	int nInNum;
	int nSecNum = m_pNtHdr->FileHeader.NumberOfSections;
	switch(m_select) {
		case 1:
			{
				DWORD dwImageBase = m_pNtHdr->OptionalHeader.ImageBase;
				for (nInNum = 0; nInNum < nSecNum; nInNum++)
				{
					if (dwAddr >= dwImageBase + m_pSecHdr[nInNum].VirtualAddress && dwAddr <= dwImageBase +m_pSecHdr[nInNum].Misc.VirtualSize)
					{
						return nInNum;
					}
				}
				break;
			}
		case 2:
			{
				DWORD dwImageBase = m_pNtHdr->OptionalHeader.ImageBase;
				for (nInNum = 0; nInNum < nSecNum; nInNum++)
				{
					if (dwAddr >= dwImageBase + m_pSecHdr[nInNum].VirtualAddress && dwAddr <= dwImageBase +m_pSecHdr[nInNum].Misc.VirtualSize)
					{
						return nInNum;
					}
				}
				break;
			}
		case 3:
			{
				DWORD dwImageBase = m_pNtHdr->OptionalHeader.ImageBase;
				for (nInNum = 0; nInNum < nSecNum; nInNum++)
				{
					if (dwAddr >= dwImageBase + m_pSecHdr[nInNum].VirtualAddress && dwAddr <= dwImageBase +m_pSecHdr[nInNum].Misc.VirtualSize)
					{
						return nInNum;
					}
				}
				break;
			}
	}
	return -1;
}

VOID CPeParseDlg::CalcAddr(int nInNum, DWORD dwAddr)
{
	DWORD dwVa = 0;
	DWORD dwRva = 0;
	DWORD dwFileOffset = 0;

	switch(m_select) {
	case 1:
		{
			dwVa = dwAddr;
			dwRva = dwVa - m_pNtHdr->OptionalHeader.ImageBase;
			dwFileOffset = m_pSecHdr[nInNum].PointerToRawData + (dwRva - m_pSecHdr[nInNum].VirtualAddress);
			break;
		}
	case 2:
		{
			dwVa = dwAddr + m_pNtHdr->OptionalHeader.ImageBase;
			dwRva = dwAddr;
			dwFileOffset = m_pSecHdr[nInNum].PointerToRawData + (dwRva - m_pSecHdr[nInNum].VirtualAddress);
			break;
		}
	case 3:
		{
			dwFileOffset = dwAddr;
			dwRva = m_pSecHdr[nInNum].VirtualAddress + (dwFileOffset - m_pSecHdr[nInNum].PointerToRawData);
			dwVa = dwRva + m_pNtHdr->OptionalHeader.ImageBase;
			break;
		}

	}

	SetDlgItemText(IDC_EDIT_SECTION, (const char *)m_pSecHdr[nInNum].Name);

	CString str;
	str.Format("%08X", dwVa);
	SetDlgItemText(IDC_EDIT_VA, str);

	str.Format("%08X", dwRva);
	SetDlgItemText(IDC_EDIT_RVA, str);

	str.Format("%08X", dwFileOffset);
	SetDlgItemText(IDC_EDIT_FileOffset, str);

	SetDlgItemText(IDC_EDIT_SECTION, (const char *)m_pSecHdr[nInNum].Name);
}

VOID CPeParseDlg::HexStrToInt(char *szHexStr, DWORD *pdwHexVal)
{
	char   *pCH, c;
    DWORD  dwVal = 0, dw;
    
    pCH = szHexStr;
	//��ĸת���;���ASCII��
    while (*pCH)
    {
        c = toupper(*pCH++);//ͳһ����д����
        if (c >= 'A' && c <= 'F')
            dw = (DWORD)c - ((DWORD)'A' - 10);//��c-a+10
        else if (c >= '0' && c <= '9')
            dw = (DWORD)c - (DWORD)'0';
        else
            return ; // invalid hex char
        dwVal = (dwVal << 4) + dw; //������������λ�����Ŵθ�λ����ӵĻ���֮ǰ��ֵҪ������λ�������
    }
    
    *pdwHexVal = dwVal;
}

void CPeParseDlg::OnButtonAddSec() 
{
	// TODO: Add your control notification handler code here
	//����
	char szSecName = {0};
	//�ڴ�С
	int nSecSize = 0;

	GetDlgItemText(IDC_EDIT_SECNAME, &szSecName, 8);
	nSecSize = GetDlgItemInt(IDC_EDIT_SECSIZE, FALSE, TRUE);

	AddSec(&szSecName, nSecSize);
}

VOID CPeParseDlg::AddSec(char *szSecName, int nSecSize)
{
	int nSecNum = m_pNtHdr->FileHeader.NumberOfSections;
	DWORD dwFileAlignment = m_pNtHdr->OptionalHeader.FileAlignment;
	DWORD dwSecAlignment = m_pNtHdr->OptionalHeader.SectionAlignment;

	PIMAGE_SECTION_HEADER pTmpSec = m_pSecHdr +nSecNum;

	//��������
	strncpy((char *)pTmpSec->Name, szSecName, 7);
	//�ڵ��ڴ��С
	pTmpSec->Misc.VirtualSize = AlignSize(nSecSize, dwSecAlignment);
	//�ڵ��ڴ���ʼ��ַ
	pTmpSec->VirtualAddress = m_pSecHdr[nSecNum-1].VirtualAddress + AlignSize(m_pSecHdr[nSecNum-1].Misc.VirtualSize, dwSecAlignment);
	//�ڵ��ļ���С
	pTmpSec->SizeOfRawData = AlignSize(nSecSize, dwSecAlignment);
	//�ڵ��ļ���ʼλ��
	pTmpSec->PointerToRawData = m_pSecHdr[nSecNum-1].PointerToRawData + AlignSize(m_pSecHdr[nSecNum-1].SizeOfRawData, dwSecAlignment);
	
	//�����ڵ�����
	m_pNtHdr->FileHeader.NumberOfSections++;
	//����ӳ���С
	m_pNtHdr->OptionalHeader.SizeOfImage += pTmpSec->Misc.VirtualSize;

	FlushViewOfFile(m_lpBase, 0);

	//��ӽ�����(ȫΪ0)
	AddSecData(pTmpSec->SizeOfRawData);
	
	EnumSections();



}

DWORD CPeParseDlg::AlignSize(int nSecSize, DWORD Alignment)
{
	int nSize = nSecSize;
	if (nSize % Alignment != 0)
	{
		nSecSize = (nSize / Alignment + 1) * Alignment;
	}

	return nSecSize;
}

VOID CPeParseDlg::AddSecData(int nSecSize)
{
	PBYTE pByte = NULL;
	pByte = (PBYTE)malloc(nSecSize);
	ZeroMemory(pByte, nSecSize);

	DWORD dwNum = 0;
	SetFilePointer(m_hFile, 0, 0, FILE_END);
	WriteFile(m_hFile, pByte, nSecSize, &dwNum, NULL);
	FlushFileBuffers(m_hFile);

	free(pByte);
}
