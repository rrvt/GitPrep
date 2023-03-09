// GitPrepDoc.h : interface of the GitPrepDoc class


#pragma once
#include "CDoc.h"
#include "Explore.h"
#include "MainFrame.h"


enum DataSource {NotePadSrc};


class GitPrepDoc : public CDoc {

PathDlgDsc  pathDlgDsc;
Explore     explore;

DataSource  dataSource;

protected: // create from serialization only

  GitPrepDoc() noexcept;

  DECLARE_DYNCREATE(GitPrepDoc)

public:

  DataSource   dataSrc() {return dataSource;}
  void         display(DataSource ds);

  virtual void serialize(Archive& ar);

// Implementation
public:

  virtual ~GitPrepDoc();

#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

private:

  void testLine(int n);
  void wholePage();

// Generated message map functions

protected:

  DECLARE_MESSAGE_MAP()

public:

  afx_msg void onFileOpen();
  afx_msg void onExplore();
  afx_msg void onCommit();
  afx_msg void onFindBig();
  afx_msg void onFileSave();
  };





