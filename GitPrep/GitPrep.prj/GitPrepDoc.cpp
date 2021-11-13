// GitPrepDoc.cpp : implementation of the GitPrepDoc class


#include "stdafx.h"
#include "GitPrepDoc.h"
#include "ExtraResource.h"
#include "FileName.h"
#include "GitPrep.h"
#include "GitPrepView.h"
#include "IniFile.h"
#include "Options.h"
#include "Resource.h"


static TCchar* GitHub        = _T("C:\\Users\\rrvt\\AppData\\Local\\GitHubDesktop\\GitHubDesktop.exe");
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
  ON_COMMAND(ID_Options,       &onOptions)

END_MESSAGE_MAP()


// GitPrepDoc construction/destruction

GitPrepDoc::GitPrepDoc() noexcept : dataSource(NotePadSrc) { }

GitPrepDoc::~GitPrepDoc() { }



void GitPrepDoc::onOptions() {options(view());  view()->setOrientation(options.orient);}


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

  pathDlgDsc = PathDlgDsc(_T("Git Prep List"), path, _T("txt"), _T("*.txt"));

  setSaveAsPath(pathDlgDsc); OnSaveDocument(path);

  iniFile.writeString(Section, LastSavedFile, ::getPath(path));
  }


// UglyDoc serialization

void GitPrepDoc::serialize(Archive& ar) {

  if (ar.isStoring())
    switch(dataSource) {
      case NotePadSrc : notePad.archive(ar); return;
#ifdef Examples
      case StoreSrc: store.store(ar); return;
#endif
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
void GitPrepDoc::AssertValid() const
{
  CDocument::AssertValid();
}

void GitPrepDoc::Dump(CDumpContext& dc) const
{
  CDocument::Dump(dc);
}
#endif //_DEBUG




#ifdef Examples

static TCchar* cbText[] = {_T("Zeta"),
                           _T("Beta"),
                           _T("Alpha"),
                           _T("Omega"),
                           _T("Phi"),
                           _T("Mu"),
                           _T("Xi"),
                           _T("Omicron"),
                           _T("Pi"),
                           _T("Rho"),
                           _T("Sigma"),
                           _T("Nu"),
                           _T("Kappa"),
                           _T("Iota")
                           };


void GitPrepDoc::myButton() {
TBComboBox* cb = TBComboBox::get(ID_CB);
int n = noElements(cbText);
int i;
int x;

  dataSource = NotePadSrc;

  notePad << _T("My Button") << nCrlf;

  if (!cb) {invalidate();  return;}

//  cb->SetText(_T("Greeks"));

  for (i = 0; i < n; i++) if (cb->findExact(cbText[i]) < 0) {

    x = cb->AddSortedItem(cbText[i], i);                           //AddSortedItem

    String s;  s.format(_T("%02i: "), i);

    notePad << s << _T("Pos = ") << x << _T(". Added ") << cbText[i] << nCrlf;
    }

  cb->SelectItem(-1);
  cb->SetText(_T("Greeks"));

  notePad << _T("Greeks") << nCrlf;  display(NotePadSrc);
  }


void GitPrepDoc::OnComboBoxChng() {
TBComboBox* cb = TBComboBox::get(ID_CB);
int        i;
String     s;
int        x;
MainFrame* mf = theApp.mainFrm();

  if (!cb)   return;
  i  = cb->GetCurSel();    if (i < 0) return;
  s  = cb->GetItem(i);
  x  = cb->GetItemData(i);   mf->SetFocus();

  notePad << _T("On Change, Item = ") << s << _T(", Data = ") << x << nCrlf;

  display(NotePadSrc);
  }



void GitPrepDoc::OnTBEditBox() {
TBEditBox*  eb = TBEditBox::get(ID_EditBox);   if (!eb) return;
String      s  = eb->GetContentsAll(ID_EditBox);

  notePad << s << nCrlf;   display(NotePadSrc);
  }


void GitPrepDoc::myButton1() {
TBEditBox* eb = TBEditBox::get(ID_EditBox);   if (!eb) return;
String     s  = eb->GetContentsAll(ID_EditBox);

  notePad << s << nCrlf;   display(NotePadSrc);
  }


void GitPrepDoc::onOption1() {notePad << _T("Option 1") << nCrlf; wholePage(); display(NotePadSrc);}
void GitPrepDoc::onOption2() {notePad << _T("Option 2") << nCrlf; display(NotePadSrc);}
void GitPrepDoc::onOption3() {notePad << _T("Option 3") << nCrlf; display(NotePadSrc);}


void GitPrepDoc::onOption21() {notePad << _T("Option 21") << nCrlf; display(NotePadSrc);}
void GitPrepDoc::onOption22() {notePad << _T("Option 22") << nCrlf; display(NotePadSrc);}
void GitPrepDoc::onOption23() {notePad << _T("Option 23") << nCrlf; display(NotePadSrc);}


void GitPrepDoc::OnTestEditBoxes() {display(NotePadSrc);}


// GitPrepDoc commands


void GitPrepDoc::OnTest() {
int          n;

  notePad.clear();  theApp.setTitle(_T("My Test"));

  notePad << nFFace(_T("Windsor BT")) << nFSize(14.5) << nBold;

  notePad << _T("Hello World") << nCrlf;

  notePad << nFont << nFont << nFont;

  n = options.orient == Landscape ? 10 : 8;

  notePad << nFFace(_T("Courier New")) << nFSize(12.0);   testLine(n);   notePad << nFont << nFont;

  testLine(n);   display(NotePadSrc);
  }


void GitPrepDoc::testLine(int n) {
int i;

  for (i = 0; i < n; i++) {

    if (!i) notePad << _T('|'); else notePad << i;

    notePad << _T("123456789");
    }

  notePad << _T('|') << nCrlf;
  }


void GitPrepDoc::wholePage() {
int    i;
int    j;
String s;

  notePad << nSetRTab(4) << nSetTab(6) << nSetTab(8) << nSetRTab(12) << nSetTab(14);

  for (i = 0; i < 100; i++) {
    s.format(_T("%3i:"), i);

    notePad << nTab << s << nTab << _T("X") << nTab << _T("Y") << nTab << i << nTab;

    for (j = i+1; j < i+68; j++) {s.format(_T("%i"), j);   s = s.substr(s.length()-1);  notePad << s;}

    notePad << nCrlf;
    }
  }


void GitPrepDoc::displayDataStore() {display(NotePadSrc);}

BOOL GitPrepDoc::OnNewDocument() {return CDocument::OnNewDocument();}

#endif
#ifdef Examples
  ON_COMMAND(ID_Test,          &OnTest)
  ON_COMMAND(ID_SelDataStr,    &displayDataStore)

  ON_COMMAND(ID_MyBtn,         &myButton)

  ON_CBN_SELCHANGE(ID_CB,      &OnComboBoxChng)
  ON_COMMAND(      ID_CB,      &OnComboBoxChng)

  ON_COMMAND(ID_EditBox,       &OnTBEditBox)
  ON_COMMAND(ID_MyBtn1,        &onOption1)
  ON_COMMAND(ID_Option1,       &onOption1)
  ON_COMMAND(ID_Option2,       &onOption2)
  ON_COMMAND(ID_Option3,       &onOption3)
  ON_COMMAND(ID_Btn2,          &onOption21)
  ON_COMMAND(ID_Option21,      &onOption21)
  ON_COMMAND(ID_Option22,      &onOption22)
  ON_COMMAND(ID_Option23,      &onOption23)
#endif

