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
  AnsiString getFileName(void);
  void setBeginTime(void);
  void setOffset(double offset);
  void prtLrc(TTimer* timer);
  word getIndex(int index);
  int getSize(void);
  double getOffset(void);
  double getBeginTime(void);
private:
  vector<word> _lrc;
  int _index;
  double _beginTime;
  AnsiString _filePath;
  double _offset;

};

//---------------------------------------------------------------------------
#endif
