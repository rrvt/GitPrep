// GitPrep.h : main header file for the GitPrep application

#pragma once
#include "CApp.h"


class GitPrepDoc;
class GitPrepView;
class MainFrame;


// GitPrep:
// See GitPrep.cpp for the implementation of this class

class GitPrep : public CApp {

public:

               GitPrep() noexcept : CApp(this) { }

  virtual BOOL InitInstance();
  virtual int  ExitInstance();

          GitPrepDoc*  doc()  {return (GitPrepDoc*)  CApp::getDoc();}
          GitPrepView* view() {return (GitPrepView*) CApp::getView();}
          MainFrame*       mainFrm() {return (MainFrame*) m_pMainWnd;}

  DECLARE_MESSAGE_MAP()

  afx_msg void OnFilePrintSetup();
  afx_msg void OnAppAbout();
  afx_msg void OnHelp();
  };


extern GitPrep theApp;

inline void             invalidate() {theApp.invalidate();}
inline GitPrepDoc*  doc()        {return theApp.doc();}
inline GitPrepView* view()       {return theApp.view();}

