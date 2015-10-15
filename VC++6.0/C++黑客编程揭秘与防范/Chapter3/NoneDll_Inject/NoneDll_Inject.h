// NoneDll_Inject.h : main header file for the NONEDLL_INJECT application
//

#if !defined(AFX_NONEDLL_INJECT_H__0635EDE1_2073_4ED9_83B6_12D4A833B559__INCLUDED_)
#define AFX_NONEDLL_INJECT_H__0635EDE1_2073_4ED9_83B6_12D4A833B559__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNoneDll_InjectApp:
// See NoneDll_Inject.cpp for the implementation of this class
//

class CNoneDll_InjectApp : public CWinApp
{
public:
	CNoneDll_InjectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoneDll_InjectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNoneDll_InjectApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NONEDLL_INJECT_H__0635EDE1_2073_4ED9_83B6_12D4A833B559__INCLUDED_)
