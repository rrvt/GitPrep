// GitPrepView.h : interface of the GitPrepView class


#pragma once
#include "CScrView.h"
#include "ReportNtPd.h"


class GitPrepDoc;


class GitPrepView : public CScrView {
protected: // create from serialization only

  GitPrepView() noexcept;

  DECLARE_DYNCREATE(GitPrepView)

public:

  virtual     ~GitPrepView() { }

  virtual void       initNoteOrietn() { }
  virtual void       saveNoteOrietn() { }
  virtual void       initRptOrietn()  { }
  virtual void       saveRptOrietn()  { }
  virtual PrtrOrient getOrientation() {return prtNote.prtrOrietn;}

  virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

  virtual void OnInitialUpdate();

  virtual void onDisplayOutput();

  virtual void onPreparePrinting(CPrintInfo* info) {prtNote.onPreparePrinting(info);}
  virtual void onBeginPrinting();

  virtual void printFooter(DevStream& dev, int pageNo);
  virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

  GitPrepDoc*  GetDocument() const;

public:

#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

public:

  DECLARE_MESSAGE_MAP()

  afx_msg void onOptions();
  afx_msg void onRptOrietn();
  afx_msg void OnSetFocus(CWnd* pOldWnd);
  };


#ifndef _DEBUG  // debug version in GitPrepView.cpp
inline GitPrepDoc* GitPrepView::GetDocument() const
                                               {return reinterpret_cast<GitPrepDoc*>(m_pDocument);}
#endif

