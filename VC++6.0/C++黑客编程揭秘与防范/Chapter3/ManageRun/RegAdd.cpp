// RegAdd.cpp : implementation file
//

#include "stdafx.h"
#include "ManageRun.h"
#include "RegAdd.h"
#include "ManageRunDlg.h"

#define REG_RUN "Software\\Microsoft\\Windows\\CurrentVersion\\Run"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegAdd dialog


CRegAdd::CRegAdd(CWnd* pParent /*=NULL*/)
	: CDialog(CRegAdd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegAdd)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRegAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegAdd)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegAdd, CDialog)
	//{{AFX_MSG_MAP(CRegAdd)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegAdd message handlers
/////////////////////////////////////////////////////////////////////////////
// RegAddDlg dialog


RegAddDlg::RegAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(RegAddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(RegAddDlg)
	//}}AFX_DATA_INIT
}


void RegAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RegAddDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(RegAddDlg, CDialog)
	//{{AFX_MSG_MAP(RegAddDlg)
	ON_BN_CLICKED(IDC_BUTTON_FIND, OnButtonFind)
	ON_BN_CLICKED(IDC_BUTTON_CANCLE, OnButtonCancle)
	ON_BN_CLICKED(IDC_BUTTON_OK, OnButtonOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// RegAddDlg message handlers

void RegAddDlg::OnButtonFind() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg( TRUE, _T( ".exe" ), _T( "test.exe" ), OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T( "应用程序(exe)|*.exe|所有文件|*||" ) );
	if ( dlg.DoModal() == IDOK ) 
	{
		CString path = dlg.GetPathName();	//获取路径
		//AfxMessageBox(path);
		const char* key = (LPCSTR)path;
		GetDlgItem(IDC_EDIT_PATH)->SetWindowText(key);
	}
}

void RegAddDlg::OnButtonCancle() 
{
	// TODO: Add your control notification handler code here
	EndDialog(IDCANCEL);
}

void RegAddDlg::OnButtonOk() 
{
	// TODO: Add your control notification handler code here
	CString szKeyValue,szKeyName;
	GetDlgItem(IDC_EDIT_PATH)->GetWindowText(szKeyValue);
	GetDlgItem(IDC_EDIT_KEY)->GetWindowText(szKeyName);
	//AfxMessageBox(szKeyName);
	//AfxMessageBox(szKeyValue);
	if (strlen(szKeyName)>0 && strlen(szKeyValue)>0)
	{
		HKEY hKey = NULL;

		LONG lRet = RegOpenKey(HKEY_LOCAL_MACHINE, REG_RUN, &hKey);	//打开启动项注册表

		if (lRet != ERROR_SUCCESS)
		{
			return ;
		}
		
		const unsigned char * value = (const unsigned char *)(LPCTSTR)szKeyValue;
		RegSetValueEx(hKey, szKeyName, NULL, REG_SZ, value, strlen(szKeyValue)+sizeof(char));

		RegCloseKey(hKey);
		CManageRunDlg ManageRunDlg;
		ManageRunDlg.ShowRunList();
	}else{
		AfxMessageBox("请输入完整内容");
	}
}
