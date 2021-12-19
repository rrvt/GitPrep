// GitPrepView.h : interface of the GitPrepView class


#pragma once
#include "CScrView.h"
#include "NotePadRpt.h"


class GitPrepDoc;


class GitPrepView : public CScrView {

NotePadRpt dspNote;
NotePadRpt prtNote;

protected: // create from serialization only

  GitPrepView() noexcept;

  DECLARE_DYNCREATE(GitPrepView)

public:

  virtual ~GitPrepView() { }

  virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

  virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
  virtual void onPrepareOutput(bool printing);

  virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
  virtual void printFooter(Device& dev, int pageNo);
  virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

  GitPrepDoc* GetDocument() const;

public:

#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

public:

  DECLARE_MESSAGE_MAP()

  afx_msg void OnSetFocus(CWnd* pOldWnd);
  };


#ifndef _DEBUG  // debug version in GitPrepView.cpp
inline GitPrepDoc* GitPrepView::GetDocument() const
   { return reinterpret_cast<GitPrepDoc*>(m_pDocument); }
#endif

