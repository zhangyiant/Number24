; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNumber24Dlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Number24.h"

ClassCount=3
Class1=CNumber24App
Class2=CNumber24Dlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_NUMBER24_DIALOG
Resource4=IDR_MAINMENU

[CLS:CNumber24App]
Type=0
HeaderFile=Number24.h
ImplementationFile=Number24.cpp
Filter=N
LastObject=ID_HELP_ABOUT

[CLS:CNumber24Dlg]
Type=0
HeaderFile=Number24Dlg.h
ImplementationFile=Number24Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_CACULATE

[CLS:CAboutDlg]
Type=0
HeaderFile=Number24Dlg.h
ImplementationFile=Number24Dlg.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_NUMBER24_DIALOG]
Type=1
Class=CNumber24Dlg
ControlCount=9
Control1=IDC_STATIC,button,1342177287
Control2=IDC_NUMBER1,edit,1350762624
Control3=IDC_NUMBER2,edit,1350762624
Control4=IDC_NUMBER3,edit,1350762624
Control5=IDC_NUMBER4,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_RESULT,edit,1350631552
Control8=IDC_CACULATE,button,1342242816
Control9=IDOK,button,1342242817

[MNU:IDR_MAINMENU]
Type=1
Class=?
Command1=ID_HELP_ABOUT
CommandCount=1

