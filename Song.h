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
    ~Song();
    AnsiString getPathName(void);
    AnsiString getFileName(void);
    AnsiString getLrcPathName(void);
    double getOffset(void);
    int getMood(int index);
    vector<double> getHighLight(void);
    void setLrcPathName(AnsiString);
    void setOffset(double);
    void setMoodAdd(int mood);
    void setHighLight(double begin,double end);
    
private:
    AnsiString _fileName;
    AnsiString _pathName;
    AnsiString _lrcPathName;
    vector<double> _highLight;
    vector<int> _mood;
    double _offset;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
