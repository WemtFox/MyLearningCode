; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNoneDll_InjectDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NoneDll_Inject.h"

ClassCount=4
Class1=CNoneDll_InjectApp
Class2=CNoneDll_InjectDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_NONEDLL_INJECT_DIALOG

[CLS:CNoneDll_InjectApp]
Type=0
HeaderFile=NoneDll_Inject.h
ImplementationFile=NoneDll_Inject.cpp
Filter=N

[CLS:CNoneDll_InjectDlg]
Type=0
HeaderFile=NoneDll_InjectDlg.h
ImplementationFile=NoneDll_InjectDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=NoneDll_InjectDlg.h
ImplementationFile=NoneDll_InjectDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NONEDLL_INJECT_DIALOG]
Type=1
Class=CNoneDll_InjectDlg
ControlCount=4
Control1=IDC_STATIC_PID,static,1342308352
Control2=IDC_EDIT_PID,edit,1350631552
Control3=IDC_BUTTON_Inject,button,1342242816
Control4=IDC_BUTTON_UnInject,button,1342242816

