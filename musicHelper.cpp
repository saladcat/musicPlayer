//---------------------------------------------------------------------------


#pragma hdrstop

#include "musicHelper.h"
//---------------------------------------------------------------------------
#include "Init.h"
#pragma package(smart_init)

AnsiString takeFileName(AnsiString filePath){
        int startIndex = filePath.LastDelimiter("\\");
        int endIndex = filePath.LastDelimiter(".");
        int stringLength = endIndex-startIndex-1;
        AnsiString fileName = filePath.SubString(startIndex+1,stringLength);
        return fileName;
}

vector<AnsiString> sepStringBy(char* files, char* sepChar){
        vector<AnsiString> res;
        char* pch = strtok (files,sepChar);
        while (pch != NULL)
        {
                res.push_back(pch);
                pch = strtok (NULL,sepChar);
        }
        return res;
}

AnsiString refMusic2Lrc(AnsiString pathName){
        int index = pathName.LastDelimiter(".");
        AnsiString res = pathName;
        res[index+1]='l';
        res[index+2]='r';
        res[index+3]='c';
        //res[index+4]='\0';
        return res;
}
AnsiString str2Ansi(string str){
    AnsiString ret=str.c_str();
    return ret;
}
string ansi2Str(AnsiString str){
    string ret(str.c_str());
    return ret;
}

void push_song(AnsiString songListName,AnsiString pathName){
    bool flag=false;
    int index=0;
    for (int i=0;i< Form1->listName2SongList[songListName]->songs.size();i++){
        if (pathName==Form1->listName2SongList[songListName]->songs[i]){
            flag=true;
            index=i;
        }
    }
    if (flag==true){
        Form1->listName2SongList[songListName]->songs.erase(Form1->listName2SongList[songListName]->songs.begin()+index);
    }
    Form1->listName2SongList[songListName]->songs.push_back(pathName);

}


