//---------------------------------------------------------------------------

#ifndef LrcHelperH
#define LrcHelperH

#pragma package(smart_init)

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include "musicHelper.h"

using namespace std;

vector<AnsiString> sepString(AnsiString str);

struct word {
  double time;
  AnsiString text;
};
vector<AnsiString> sepString(AnsiString str);
class LrcHelper {
public:
  LrcHelper(AnsiString pathName);
  ~LrcHelper();
  AnsiString getFileName(void);
  void setBeginTime(void);
  void prtLrc(TTimer* timer);
  vector<word> lrc;
  int index;
  double beginTime;
  AnsiString filePath;
  double offset;
  bool isFileExist;
  TTimer* lastTimer;
};

//---------------------------------------------------------------------------
#endif
