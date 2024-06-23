// GitPrepDoc.cpp : implementation of the GitPrepDoc class


#include "stdafx.h"
#include "GitPrepDoc.h"
#include "FileName.h"
#include "GitPrep.h"
#include "GitPrepView.h"
#include "IniFile.h"
#include "Resource.h"
#include "ResourceExtra.h"


static TCchar* GitHub    = _T("C:\\Users\\rrvt\\AppData\\Local\\GitHubDesktop\\GitHubDesktop.exe");
static TCchar* Section       = _T("Global");
static TCchar* LastGitDir    = _T("LastGitDir");
static TCchar* LastSavedFile = _T("LastSavedFile");


// GitPrepDoc

IMPLEMENT_DYNCREATE(GitPrepDoc, CDoc)

BEGIN_MESSAGE_MAP(GitPrepDoc, CDoc)

  ON_COMMAND(ID_File_Open,     &onFileOpen)
  ON_COMMAND(ID_Explore,       &onExplore)
  ON_COMMAND(ID_Commit,        &onCommit)
  ON_COMMAND(ID_FindBig,       &onFindBig)

  ON_COMMAND(ID_File_Save,     &onFileSave)

END_MESSAGE_MAP()


// GitPrepDoc construction/destruction

GitPrepDoc::GitPrepDoc() noexcept : dataSource(NotePadSrc) { }

GitPrepDoc::~GitPrepDoc() { }


void GitPrepDoc::onFileOpen() {

  notePad.clear();   dataSource = NotePadSrc;

  if (!iniFile.readString(Section, LastGitDir, path)) path.clear();

  if (getDirPathDlg(_T("Git Directory"), path)) notePad << _T("Path ") << path << nCrlf;

  iniFile.writeString(Section, LastGitDir, path);

  display(NotePadSrc);
  }


void GitPrepDoc::onExplore() {

  if (path.isEmpty()) return;

  explore.forDeletables(path);

  explore.display();

  display(NotePadSrc);
  }


void GitPrepDoc::onCommit() {
int n = explore.delEntities();

  notePad.clear();

  notePad << n << _T(" Items Deleted") << nCrlf;

  display(NotePadSrc);
  }


void GitPrepDoc::onFindBig() {

  if (path.isEmpty()) return;

  notePad.clear();

  explore.findBigEntities(path);

  explore.display();

  display(NotePadSrc);
  }


void GitPrepDoc::display(DataSource ds) {dataSource = ds; invalidate();}


void GitPrepDoc::onFileSave() {

  if (!iniFile.readString(Section, LastSavedFile, path)) path = _T("GitPrepList");

  pathDlgDsc(_T("Git Prep List"), path, _T("txt"), _T("*.txt"));

  setSaveAsPath(pathDlgDsc); OnSaveDocument(path);

  String pth = ::getPath(path);

  iniFile.writeString(Section, LastSavedFile, pth);
  }


// UglyDoc serialization

void GitPrepDoc::serialize(Archive& ar) {

  if (ar.isStoring())
    switch(dataSource) {
      case NotePadSrc : notePad.archive(ar); return;
      default         : return;
      }

  else
    switch(dataSource) {
      case NotePadSrc:
      default       : return;
      }
  }


// GitPrepDoc diagnostics

#ifdef _DEBUG
void GitPrepDoc::AssertValid() const          {CDocument::AssertValid();}
void GitPrepDoc::Dump(CDumpContext& dc) const {CDocument::Dump(dc);}
#endif //_DEBUG


