// ManageRun.h : main header file for the MANAGERUN application
//

#if !defined(AFX_MANAGERUN_H__4AA83275_185A_4E0B_AD70_123CF5F31E7C__INCLUDED_)
#define AFX_MANAGERUN_H__4AA83275_185A_4E0B_AD70_123CF5F31E7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CManageRunApp:
// See ManageRun.cpp for the implementation of this class
//

class CManageRunApp : public CWinApp
{
public:
	CManageRunApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManageRunApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CManageRunApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGERUN_H__4AA83275_185A_4E0B_AD70_123CF5F31E7C__INCLUDED_)
