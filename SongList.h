//---------------------------------------------------------------------------

#ifndef SongListH
#define SongListH
//---------------------------------------------------------------------------

#include "Song.h"

class SongList{
public:
    SongList();

    void sort(int isAsc);
    AnsiString name;
    deque<AnsiString> songs;
    AnsiString sortKey;
    int getIndex(AnsiString str);

};

//---------------------------------------------------------------------------
#endif
