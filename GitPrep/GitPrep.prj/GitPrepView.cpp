// GitPrepView.cpp : implementation of the GitPrepView class


#include "stdafx.h"
#include "GitPrepView.h"
#include "GitPrep.h"
#include "GitPrepDoc.h"
#include "Options.h"
#include "Resources.h"


// GitPrepView

IMPLEMENT_DYNCREATE(GitPrepView, CScrView)

BEGIN_MESSAGE_MAP(GitPrepView, CScrView)
END_MESSAGE_MAP()


GitPrepView::GitPrepView() noexcept :
                                    #ifdef Examples
                                      dspStore(dMgr.getNotePad()), prtStore(pMgr.getNotePad()),
                                    #endif
                                    dspNote( dMgr.getNotePad()), prtNote( pMgr.getNotePad()) {
ResourceData res;
String       pn;
  if (res.getProductName(pn)) prtNote.setTitle(pn);
  }


BOOL GitPrepView::PreCreateWindow(CREATESTRUCT& cs) {

  return CScrView::PreCreateWindow(cs);
  }


void GitPrepView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) {
uint   x;
double topMgn   = options.topMargin.stod(x);
double leftMgn  = options.leftMargin.stod(x);
double rightMgn = options.rightMargin.stod(x);
double botMgn   = options.botMargin.stod(x);

  setMgns(leftMgn,  topMgn,  rightMgn, botMgn, pDC);   CScrView::OnPrepareDC(pDC, pInfo);
  }


// Perpare output (i.e. report) then start the output with the call to SCrView

void GitPrepView::onPrepareOutput(bool printing) {
DataSource ds = doc()->dataSrc();

  if (printing)
    switch(ds) {
      case NotePadSrc : prtNote.print(*this);  break;
#ifdef Examples
      case StoreSrc   : prtStore.print(*this); break;
#endif
      }

  else
    switch(ds) {
      case NotePadSrc : dspNote.display(*this);  break;
#ifdef Examples
      case StoreSrc   : dspStore.display(*this); break;
#endif
      }


  CScrView::onPrepareOutput(printing);
  }


void GitPrepView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo) {

  switch(doc()->dataSrc()) {
    case NotePadSrc : setOrientation(options.orient); break;    // Setup separate Orientation?
    }
  setPrntrOrient(theApp.getDevMode(), pDC);   CScrView::OnBeginPrinting(pDC, pInfo);
  }


// The footer is injected into the printed output, so the output goes directly to the device.
// The output streaming functions are very similar to NotePad's streaming functions so it should not
// be a great hardship to construct a footer.

void GitPrepView::printFooter(Device& dev, int pageNo) {
  switch(doc()->dataSrc()) {
    case NotePadSrc : prtNote.footer(dev, pageNo);  break;
#ifdef Examples
    case StoreSrc   : prtStore.footer(dev, pageNo); break;
#endif
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
