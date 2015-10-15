// TerminateProcess.h : main header file for the TERMINATEPROCESS application
//

#if !defined(AFX_TERMINATEPROCESS_H__2601160A_30FA_438F_A598_49F9A93F9388__INCLUDED_)
#define AFX_TERMINATEPROCESS_H__2601160A_30FA_438F_A598_49F9A93F9388__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTerminateProcessApp:
// See TerminateProcess.cpp for the implementation of this class
//

class CTerminateProcessApp : public CWinApp
{
public:
	CTerminateProcessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTerminateProcessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTerminateProcessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TERMINATEPROCESS_H__2601160A_30FA_438F_A598_49F9A93F9388__INCLUDED_)
