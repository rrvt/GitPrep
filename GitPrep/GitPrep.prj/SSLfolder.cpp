// SSL Folder, Keep Track of with a stack


#include "pch.h"
#include "SSLfolder.h"
#include "FileName.h"


// push current state or two specific folder names

bool SSLfolder::push(TCchar* path) {
String dirName = getDirName(path);
bool   cur     = is();

  return data[++index](cur || dirName == _T("openssl.Win32") || dirName == _T("openssl.x64"));
  }


bool SSLfolder::pop() {return index >= 0 ? data[--index]() : false;}

