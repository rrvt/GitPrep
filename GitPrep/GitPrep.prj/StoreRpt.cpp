// Store Report -- Template for such a report


#include "stdafx.h"
#include "StoreRpt.h"
#include "CScrView.h"
#include "Store.h"


void StoreRpt::onBeginPrinting(CScrView& vw) {printing = true;   vw.disablePrtWrap();   getPageAttr(vw);}


void StoreRpt::getData(CScrView& vw) {
DSIter iter(store);
Datum* datum;
int    i;

  if (store.lastModified == dateModified) return;

  dateModified = store.lastModified;   np.clear();

  for (i = 0, datum = iter(); datum; i++, datum = iter++) np << datum->get() << nCrlf;
  }


void StoreRpt::prtHeader(DevBase& dev, int pageNo) {
String s = store.date() + _T(" ") + store.time();

  dev << store.name << dRight << s << dCrlf << dCrlf;
  }


void StoreRpt::prtFooter(DevBase& dev, int pageN) {

  if (pageN > maxPages) maxPages = pageN;

  dev << dCenter << pageN << _T(" of ") << maxPages << dFlushFtr;
  }


