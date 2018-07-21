//---------------------------------------------------------------------------

#ifndef IOHelperH
#define IOHelperH
//---------------------------------------------------------------------------
#include "musicHelper.h"
#include <fstream>

#define SAVE 1
#define READ 0
using namespace std;
class IOHelper{
public:
    IOHelper();
    AnsiString finderName;
    AnsiString fileName;
    fstream stream;
    void save(AnsiString saveString);
    AnsiString read(void);
    void open(int);
    void close();
};
#endif
