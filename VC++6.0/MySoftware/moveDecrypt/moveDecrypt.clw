; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMoveDecryptDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "moveDecrypt.h"

ClassCount=4
Class1=CMoveDecryptApp
Class2=CMoveDecryptDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MOVEDECRYPT_DIALOG

[CLS:CMoveDecryptApp]
Type=0
HeaderFile=moveDecrypt.h
ImplementationFile=moveDecrypt.cpp
Filter=N

[CLS:CMoveDecryptDlg]
Type=0
HeaderFile=moveDecryptDlg.h
ImplementationFile=moveDecryptDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=moveDecryptDlg.h
ImplementationFile=moveDecryptDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MOVEDECRYPT_DIALOG]
Type=1
Class=CMoveDecryptDlg
ControlCount=7
Control1=IDC_EDIT_CRYPT,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_DECRYPT1,edit,1350633540
Control4=IDC_EDIT_DECRYPT2,edit,1350633540
Control5=IDC_EDIT_DECRYPT3,edit,1350633540
Control6=IDC_EDIT_DECRYPT4,edit,1350633540
Control7=IDC_BUTTON_DECRYPT,button,1342242816

