; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDll_Inject_UnInjectDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Dll_Inject_UnInject.h"

ClassCount=3
Class1=CDll_Inject_UnInjectApp
Class2=CDll_Inject_UnInjectDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DLL_INJECT_UNINJECT_DIALOG

[CLS:CDll_Inject_UnInjectApp]
Type=0
HeaderFile=Dll_Inject_UnInject.h
ImplementationFile=Dll_Inject_UnInject.cpp
Filter=N

[CLS:CDll_Inject_UnInjectDlg]
Type=0
HeaderFile=Dll_Inject_UnInjectDlg.h
ImplementationFile=Dll_Inject_UnInjectDlg.cpp
Filter=D
LastObject=CDll_Inject_UnInjectDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Dll_Inject_UnInjectDlg.h
ImplementationFile=Dll_Inject_UnInjectDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DLL_INJECT_UNINJECT_DIALOG]
Type=1
Class=CDll_Inject_UnInjectDlg
ControlCount=6
Control1=IDC_STATIC_PATH,static,1342308352
Control2=IDC_STATIC_PID,static,1342308352
Control3=IDC_EDIT_PATH,edit,1350631552
Control4=IDC_EDIT_PID,edit,1350631552
Control5=IDC_BUTTON_Inject,button,1342242816
Control6=IDC_BUTTON_UnInject,button,1342242816

