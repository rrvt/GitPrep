// GitPrep.cpp : Defines the class behaviors for the application.


#include "stdafx.h"
#include "GitPrep.h"
#include "AboutDlg.h"
#include "IniFileEx.h"
#include "MainFrame.h"
#include "NotePad.h"
#include "GitPrepDoc.h"
#include "GitPrepView.h"
#include "Resource.h"
#include "ResourceExtra.h"


GitPrep   theApp;                         // The one and only GitPrep object
IniFileEx iniFile(theApp);


// GitPrep

BEGIN_MESSAGE_MAP(GitPrep, CWinAppEx)
  ON_COMMAND(ID_FILE_PRINT_SETUP, &OnFilePrintSetup)
  ON_COMMAND(ID_Help,             &OnHelp)
  ON_COMMAND(ID_App_About,        &OnAppAbout)
END_MESSAGE_MAP()


// GitPrep initialization

BOOL GitPrep::InitInstance() {

  CWinAppEx::InitInstance();

  iniFile.setAppDataPath(m_pszHelpFilePath);

  notePad.clear();

  SetRegistryKey(appID);

  LoadStdProfileSettings(0);  // Load standard INI file options (including MRU)

  // Register the application's document templates.  Document templates
  // serve as the connection between documents, frame windows and views

  CSingleDocTemplate* pDocTemplate;

  pDocTemplate = new CSingleDocTemplate(
    IDR_MAINFRAME,
    RUNTIME_CLASS(GitPrepDoc),
    RUNTIME_CLASS(MainFrame),                             // main SDI frame window
    RUNTIME_CLASS(GitPrepView));

  if (!pDocTemplate) return FALSE;

  AddDocTemplate(pDocTemplate);

  // Parse command line for standard shell commands, DDE, file open

  CCommandLineInfo cmdInfo;   ParseCommandLine(cmdInfo);

  // Dispatch commands specified on the command line.  Will return FALSE if
  // app was launched with /RegServer, /Register, /Unregserver or /Unregister.

  if (!ProcessShellCommand(cmdInfo)) return FALSE;

  setAppName(_T("GitPrep")); setTitle(_T("Git Prep"));

  view()->setFont(_T("Arial"), 12.0);

  m_pMainWnd->ShowWindow(SW_SHOW);   m_pMainWnd->UpdateWindow();   return TRUE;
  }


int GitPrep::ExitInstance() {return CApp::ExitInstance();}


void GitPrep::OnHelp() {
String topic = m_pszHelpFilePath; topic += _T(">Introduction");

  ::HtmlHelp(m_pMainWnd->m_hWnd, topic,  HH_DISPLAY_TOC, 0);
  }


void GitPrep::OnAppAbout() {AboutDlg aboutDlg; aboutDlg.DoModal();}

