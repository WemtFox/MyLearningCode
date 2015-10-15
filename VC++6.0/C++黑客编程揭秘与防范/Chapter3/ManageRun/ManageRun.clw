; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=RegAddDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ManageRun.h"

ClassCount=4
Class1=CManageRunApp
Class2=CManageRunDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_MANAGERUN_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=RegAddDlg
Resource4=IDD_DIALOG1

[CLS:CManageRunApp]
Type=0
HeaderFile=ManageRun.h
ImplementationFile=ManageRun.cpp
Filter=N
LastObject=IDC_LIST2

[CLS:CManageRunDlg]
Type=0
HeaderFile=ManageRunDlg.h
ImplementationFile=ManageRunDlg.cpp
Filter=D
LastObject=CManageRunDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ManageRunDlg.h
ImplementationFile=ManageRunDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MANAGERUN_DIALOG]
Type=1
Class=CManageRunDlg
ControlCount=4
Control1=IDC_BUTTON_ADD,button,1342242816
Control2=IDC_BUTTON_DEL,button,1342242816
Control3=IDC_BUTTON_EXIT,button,1342242816
Control4=IDC_LIST1,SysListView32,1350631425

[DLG:IDD_DIALOG1]
Type=1
Class=RegAddDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_KEY,edit,1350631552
Control4=IDC_EDIT_PATH,edit,1350631552
Control5=IDC_BUTTON_FIND,button,1342242816
Control6=IDC_BUTTON_OK,button,1342242816
Control7=IDC_BUTTON_CANCLE,button,1342242816

[CLS:RegAddDlg]
Type=0
HeaderFile=RegAdd.h
ImplementationFile=RegAdd.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_KEY

