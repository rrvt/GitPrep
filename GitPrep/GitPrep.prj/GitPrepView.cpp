// GitPrepView.cpp : implementation of the GitPrepView class


#include "stdafx.h"
#include "GitPrepView.h"
#include "GitPrep.h"
#include "GitPrepDoc.h"
#include "OptionsDlg.h"
#include "Resource.h"
#include "Resources.h"
#include "RptOrientDlgOne.h"


// GitPrepView

IMPLEMENT_DYNCREATE(GitPrepView, CScrView)

BEGIN_MESSAGE_MAP(GitPrepView, CScrView)
  ON_COMMAND(ID_Options,     &onOptions)
  ON_COMMAND(ID_Orientation, &onRptOrietn)
END_MESSAGE_MAP()




GitPrepView::GitPrepView() noexcept {
ResourceData res;
String       pn;
  if (res.getProductName(pn)) prtNote.setTitle(pn);
  }


BOOL GitPrepView::PreCreateWindow(CREATESTRUCT& cs) {

  return CScrView::PreCreateWindow(cs);
  }


void GitPrepView::OnInitialUpdate() {
  CScrView::OnInitialUpdate();
  }


void GitPrepView::onOptions() {
OptionsDlg dlg;

  if (printer.name.isEmpty()) printer.load(0);

  if (dlg.DoModal() == IDOK) pMgr.setFontScale(printer.scale);
  }


void GitPrepView::onRptOrietn() {
RptOrietnDlg dlg;

  dlg.lbl00 = _T("Media:");

  dlg.ntpd = printer.toStg(prtNote.prtrOrietn);

  if (dlg.DoModal() == IDOK) {prtNote.prtrOrietn = printer.toOrient(dlg.ntpd);   saveNoteOrietn();}
  }


// Perpare output (i.e. report) then start the output with the call to SCrView

void GitPrepView::onBeginPrinting() {prtNote.onBeginPrinting(*this);}


void GitPrepView::onDisplayOutput() {dspNote.display(*this);}


// The footer is injected into the printed output, so the output goes directly to the device.
// The output streaming functions are very similar to NotePad's streaming functions so it should not
// be a great hardship to construct a footer.

void GitPrepView::printFooter(DevBase& dev, int pageNo) {
  switch(doc()->dataSrc()) {
    case NotePadSrc : prtNote.prtFooter(dev, pageNo);  break;
    }
  }



void GitPrepView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo) {

  CScrView::OnEndPrinting(pDC, pInfo);

  switch(doc()->dataSrc()) {
    case NotePadSrc : break;
    }
  }


void GitPrepView::OnSetFocus(CWnd* pOldWnd) {

  CScrView::OnSetFocus(pOldWnd);

  switch(doc()->dataSrc()) {
    case NotePadSrc : break;

    }
  }


// GitPrepView diagnostics

#ifdef _DEBUG

void GitPrepView::AssertValid() const {CScrollView::AssertValid();}

void GitPrepView::Dump(CDumpContext& dc) const {CScrollView::Dump(dc);}
                                             // non-debug version is inline
GitPrepDoc* GitPrepView::GetDocument() const
  {ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(GitPrepDoc))); return (GitPrepDoc*)m_pDocument;}

#endif //_DEBUG
