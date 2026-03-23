// SSL Folder, Keep Track of with a stack


#pragma once
#include "Expandable.h"


class isSSLfldr {

bool x;

public:

  isSSLfldr() { }
  isSSLfldr(isSSLfldr& f) {x = f.x;}
 ~isSSLfldr() { }

  bool operator() () {return x;}
  bool operator() (bool v) {return x = v;}
  isSSLfldr& operator= (isSSLfldr& f) {x = f.x;   return *this;}
  };


class SSLfolder {

int                      index{-1};
Expandable<isSSLfldr, 2> data;

public:

  SSLfolder() { }
 ~SSLfolder() { }

  bool push(TCchar* path);
  bool pop();

  bool is() {return index >= 0 ? data[index]() : false;
  }
  };

