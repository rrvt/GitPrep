// Explore Git Looking for things to remove


#include "stdafx.h"
#include "Explore.h"
#include "FileIO.h"
#include "fileName.h"
#include "FileSrch.h"
#include <Shellapi.h>


static TCchar* NotExlorableDir[] = {_T(".git"), _T(".vs"), _T("Debug"), _T("Junk"), _T("obj")};
static TCchar* DeletableDir[]    = {_T("Data"), _T("Data01"), _T("Data02"), _T("Debug"),
                                    _T(".vs"),  _T("Junk"),   _T("obj"),    _T("bin")};
static TCchar* DeletableExt[]    = {_T("obj"), _T("idb"), _T("pdb"), _T("tlog"), _T("lastbuildstate"),
                                    _T("ilk"), _T("wixobj"), _T("log"), _T("tlh"), _T("tli"),
                                    _T("iobj"), _T("ipdb"), _T("vtg"), _T("lib"), _T("res"),
                                    _T("lastbuildstate"), _T("cache"), _T("wixpdb"),
                                    _T("accdb"), _T("xlsx"), _T("csv"), _T("eml")};


void Explore::forDeletables(TCchar* path) {data.clear(); subDirs(path);}


void Explore::subDirs(TCchar* path) {
FileSrch dirs;
String   dir;
String   name;

  dirs.findAllSubDirs(path);

  while (dirs.getName(dir)) {

    name = getDirName(dir);

    if (isDeletableDir(name)) {ExplDsc dsc;   dsc.set(dir, true);   data = dsc;   continue;}

    if (!isExplorableDir(name)) continue;

    findDeletables(dir);   subDirs(dir);
    }
  }


int Explore::findBigEntities(TCchar* path) {data.clear(); return findBigDirs(path);}


int Explore::findBigDirs(TCchar* path) {
FileSrch dirs;
String   dir;
String   name;
int      n = 0;

  dirs.findAllSubDirs(path);

  while (dirs.getName(dir)) {

    name = getDirName(dir);

    if (!isExplorableDir(name)) continue;

    n += findBigFiles(dir);    n += findBigDirs(dir);
    }

  return n;
  }



bool Explore::isExplorableDir(String& name) {
int n = noElements(NotExlorableDir);
int i;

  for (i = 0; i < n; i++) if (NotExlorableDir[i] == name) return false;

  return true;
  }


bool Explore::isDeletableDir(String& name) {
int n = noElements(DeletableDir);
int i;

  for (i = 0; i < n; i++) if (DeletableDir[i] == name) return true;

  return false;
  }


void Explore::findDeletables(TCchar* path) {
FileSrch files;
String   filePath;
String   name;

String   ext;

  files.findAllFiles(path);

  while (files.getName(filePath)) {

    name = removePath(filePath);

    ext = getExtension(name);

    if (isDeletableFile(ext))    {ExplDsc dsc;   dsc.set(filePath);   data = dsc;   continue;}
    if (isBackupFile(name, ext)) {ExplDsc dsc;   dsc.set(filePath);   data = dsc;}
    }
  }


int Explore::findBigFiles(TCchar* path) {
FileSrch files;
String   name;
String   ext;
int      n = 0;
int      lng;

  files.findAllFiles(path);

  while (files.getName(name)) {
    FileIO lu;    lng = lu.getLength(name);

    if (lng > 1000000)
      {ExplDsc dsc;   dsc.set(name); data = dsc;}
    }

  return n;
  }


bool Explore::isDeletableFile(String& ext) {
int n = noElements(DeletableExt);
int i;

  for (i = 0; i < n; i++) if (DeletableExt[i] == ext) return true;

  return false;
  }


bool Explore::isBackupFile(String& name, String& ext) {
int   lng = ext.length();   if (lng != 12) return false;
int   i;
Tchar ch;

  for (i = 0; i < lng; i++) {ch = ext[i]; if (ch < _T('0') || _T('9') < ch) return false;}

  i = name.find(_T('.')) + 1;   if (i < 0) return false;

  ch = name[i];   return ch < _T('0') || _T('9') < ch;
  }



void ExplDsc::set(TCchar* path, bool dir) {
FileIO lu;

  name = dir ? getDirName(path) : removePath(path);

  this->path = path;   directory = dir;

  if (!dir) size = lu.getLength(path);
  }



void Explore::display() {
ExplIter iter(*this);
ExplDsc* dsc;

  notePad << _T("Selected Entities") << nCrlf;
  notePad << nClrTabs << nSetRTab(30) << nSetTab(31);

  for (dsc = iter(); dsc; dsc = iter++) {

    notePad << dsc->name << nTab;
    if (dsc->directory) notePad << _T("Directory");
    else                notePad << dspSize(dsc->size);
    notePad << nTab << dsc->path << nCrlf;
    }
  }


String Explore::dspSize(int size) {
double v = size;
String s;

  if (size >= 1000000) return s.format(_T("%.2f Mb"), v /=  1000000);

  if (size >= 1000)    return s.format(_T("%.2f Kb"), v /= 1000);

                       return s.format(_T("%i"), size);
  }


int Explore::delEntities() {
ExplIter iter(*this);
ExplDsc* dsc;
int      n;

  for (dsc = iter(), n = 0; dsc; dsc = iter++) if (delEntity(dsc->path)) n++;

  return n;
  }



/*
typedef struct _SHFILEOPSTRUCT {
  HWND         hwnd;
  UINT         wFunc;
  PCZZTSTR     pFrom;
  PCZZTSTR     pTo;
  FILEOP_FLAGS fFlags;
  BOOL         fAnyOperationsAborted;
  LPVOID       hNameMappings;
  PCTSTR       lpszProgressTitle;
} SHFILEOPSTRUCT, *LPSHFILEOPSTRUCT;
*/


bool Explore::delEntity(TCchar* path) {
SHFILEOPSTRUCT sh;
Tchar          buf[MAX_PATH+1];
int            n = noElements(buf) - 1;
int            i;
Tchar          ch;

  sh.hwnd                  = 0;
  sh.wFunc                 = FO_DELETE;
  sh.pFrom                 = buf;
  sh.pTo                   = 0;
  sh.fFlags                = FOF_ALLOWUNDO | FOF_NO_UI;
  sh.fAnyOperationsAborted = 0;
  sh.hNameMappings         = 0;
  sh.lpszProgressTitle     = 0;

  for (i = 0, ch = path[i]; ch && i < n; ch = path[++i]) buf[i] = ch;    buf[i] = 0;   buf[++i] = 0;

  if (SHFileOperation(&sh)) {notePad << _T("An Error in Deleting: ") << path << nCrlf; return false;}

  return true;
  }

