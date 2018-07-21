//---------------------------------------------------------------------------


#pragma hdrstop

#include "Song.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Song::Song(AnsiString pathName):highLight(2,-1) {
    this->pathName=pathName;
}
