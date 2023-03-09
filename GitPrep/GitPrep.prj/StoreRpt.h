// Store Report -- Template for such a report


#pragma once
#include "ReportBase.h"


class StoreRpt : public ReportBase {

public:

  StoreRpt(NotePad& notePad) : ReportBase(notePad) { }
 ~StoreRpt() { }

  void onBeginPrinting(CScrView& vw);

  void prtHeader(DevBase& dev, int pageNo = 1);
  void prtFooter(DevBase& dev, int pageNo);

private:

  void getData(CScrView& vw);

  StoreRpt() : ReportBase(*(NotePad*)0) { }
  };




//  int  header(NotePad& np, bool printing);

