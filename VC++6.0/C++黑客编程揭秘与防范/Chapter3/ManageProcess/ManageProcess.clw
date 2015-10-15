; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ManageProcess.h"

ClassCount=3
Class1=CManageProcessApp
Class2=CManageProcessDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_MANAGEPROCESS_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_DIALOG1

[CLS:CManageProcessApp]
Type=0
HeaderFile=ManageProcess.h
ImplementationFile=ManageProcess.cpp
Filter=N

[CLS:CManageProcessDlg]
Type=0
HeaderFile=ManageProcessDlg.h
ImplementationFile=ManageProcessDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CManageProcessDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ManageProcessDlg.h
ImplementationFile=ManageProcessDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MANAGEPROCESS_DIALOG]
Type=1
Class=CManageProcessDlg
ControlCount=8
Control1=IDC_LIST1,SysListView32,1350631425
Control2=IDC_LIST2,SysListView32,1350631425
Control3=IDC_BUTTON_CREAT,button,1342242816
Control4=IDC_BUTTON_END,button,1342242816
Control5=IDC_BUTTON_STOP,button,1342242816
Control6=IDC_BUTTON_REC,button,1342242816
Control7=IDC_BUTTON_DLL,button,1342242816
Control8=IDC_BUTTON_EXIT,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

