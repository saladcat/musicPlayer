//---------------------------------------------------------------------------

#ifndef SongListH
#define SongListH
//---------------------------------------------------------------------------

#ifndef SongListH
#define SongListH

#include "Song.h"

class SongList{
public:
    SongList();
    int getSize(void);
    Song* getIndex(int Index);
    AnsiString getSortKey(void);
    void setSortKey(AnsiString str);
    void add(Song* song);
    void del(Song* song);

    void sort(int isAsc);
private:
    AnsiString _name;
    vector<AnsiString> _songs;
    AnsiString _sortKey;

};
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------
#endif
