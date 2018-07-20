//---------------------------------------------------------------------------

#ifndef musicHelperH
#define musicHelperH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <MPlayer.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>

#include <sstream>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <deque>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

AnsiString takeFileName (AnsiString filePath);
vector<AnsiString> sepStringBy(char* files, char* sepChar);
AnsiString refMusic2Lrc(AnsiString pathName);
AnsiString str2Ansi(string str);
string ansi2Str(AnsiString str);
void push_song(AnsiString songListName,AnsiString pathName);
//---------------------------------------------------------------------------
#endif
