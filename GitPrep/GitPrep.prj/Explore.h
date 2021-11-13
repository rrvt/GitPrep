// Explore Git Looking for things to remove


#pragma once
#include "ExpandableP.h"
#include "IterT.h"
#include "NotePad.h"


class ExplDsc {
public:

String name;
String path;
int    size;
bool   directory;

  ExplDsc() : directory(false), size(0) { }
  ExplDsc(ExplDsc& dsc) {copy(dsc);}
 ~ExplDsc() { }

  void set(TCchar* path, bool dir=false);

  ExplDsc& operator= (ExplDsc& dsc) {copy(dsc); return *this;}

  bool operator== (ExplDsc& dsc) {return path == dsc.path;}
  bool operator>= (ExplDsc& dsc) {return path >= dsc.path;}

private:

  void copy(ExplDsc& dsc) {name = dsc.name; path = dsc.path; size = dsc.size; directory = dsc.directory;}
  };


class Explore;
typedef RcdPtrT<ExplDsc> ExplDscP;
typedef IterT<Explore, ExplDsc> ExplIter;


class Explore {

ExpandableP<ExplDsc, ExplDscP, 2> data;

public:

  Explore() { }
 ~Explore() { }

  void   forDeletables(TCchar* path);

  int    delEntities();
  int    findBigEntities(TCchar* path);

  void   display();

private:

  void   subDirs(TCchar* path);
  void   findDeletables(TCchar* path);
  bool   delEntity(TCchar* path);

  int    findBigDirs( TCchar* path);
  int    findBigFiles(TCchar* path);


  bool   isDeletableDir( String& name);
  bool   isExplorableDir(String& name);
  bool   isDeletableFile(String& ext);
  int    getSize(String& path);
  String dspSize(int size);

  // returns either a pointer to data (or datum) at index i in array or zero

  ExplDsc* datum(int i) {return 0 <= i && i < nData() ? data[i].p : 0;}

  int      nData()      {return data.end();}                  // returns number of data items in array

  void     removeDatum(int i) {if (0 <= i && i < nData()) data.del(i);}

  friend typename ExplIter;
  };

