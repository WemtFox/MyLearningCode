// ManagerService.h : main header file for the MANAGERSERVICE application
//

#if !defined(AFX_MANAGERSERVICE_H__3E4435B1_D40B_4961_8CD4_FC1004D42ED0__INCLUDED_)
#define AFX_MANAGERSERVICE_H__3E4435B1_D40B_4961_8CD4_FC1004D42ED0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CManagerServiceApp:
// See ManagerService.cpp for the implementation of this class
//

class CManagerServiceApp : public CWinApp
{
public:
	CManagerServiceApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManagerServiceApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CManagerServiceApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGERSERVICE_H__3E4435B1_D40B_4961_8CD4_FC1004D42ED0__INCLUDED_)
