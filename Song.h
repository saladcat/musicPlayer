//---------------------------------------------------------------------------

#ifndef SongH
#define SongH
#include "musicHelper.h"
#define SAD 0
#define GLAD 1
#define SGIN 2


class Song{
public:
    Song(AnsiString pathName);
    AnsiString fileName;
    AnsiString pathName;
    vector<double> highLight;
    vector<int> mood;
    deque<AnsiString> labels;
    double offset;    
private:

};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
