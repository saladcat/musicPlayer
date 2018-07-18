//---------------------------------------------------------------------------


#pragma hdrstop

#include "LrcHelper.h"
#include "musicHelper.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
vector<AnsiString> sepString(AnsiString str) {
    vector<AnsiString> res;
    int lPos = 1, rPos = 1, midPos = 1;
    while (str[lPos] != '[') {
        lPos++;
    }
    while (str[midPos] != ':') {
        midPos++;
    }
    while (str[rPos] != ']') {
        rPos++;
    }
    res.push_back(str.SubString(lPos + 1, midPos - lPos));
    res.push_back(str.SubString(midPos + 1, rPos - midPos));
    res.push_back(str.SubString(rPos + 1, str.Length() - rPos));
    return res;
}

LrcHelper::LrcHelper(AnsiString pathName) {
    _index=0;
    ifstream is(pathName.c_str());
    AnsiString line;
    string tem;
    while (getline(is, tem)) {
        line = str2Ansi(tem);
        vector<AnsiString> sepStr = sepString(line);
        if (sepStr[0] == "ti") {

        } else if (sepStr[0] == "ar") {

        } else if (sepStr[0] == "al") {

        } else if (sepStr[0] == "by") {

        } else if (sepStr[0] == "offset") {

        } else {
            double min = 0;
            double sec = 0;
            AnsiString text;
            min = atof(sepStr[0].c_str());
            sec = atof(sepStr[1].c_str());
            double total = min * 60 + sec;
            text = sepStr[2];
            word *ptr = new word;
            ptr->text = text;
            ptr->time = total;
            _lrc.push_back(*ptr);
        }
    }
}

void LrcHelper::prtLrc(TTimer* timer) {
    timer->Enabled = true;
    setBeginTime();
}
void LrcHelper::setBeginTime(void){
    clock_t begin = clock();
    double nowTime = (clock() - begin) * 1.0 / CLOCKS_PER_SEC;
    _beginTime = nowTime;
}
