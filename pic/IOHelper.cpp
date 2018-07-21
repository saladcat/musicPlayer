//---------------------------------------------------------------------------


#pragma hdrstop

#include "IOHelper.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

IOHelper::IOHelper(){
    
}
void IOHelper::save(AnsiString saveString){
    string tem = ansi2Str(saveString);
    stream << tem <<endl;
}

AnsiString IOHelper::read(void){
    string tem;
    stream >> tem;
    AnsiString res = str2Ansi(tem); 
    return res;
}

void IOHelper::open(int mode){
    string pathName = ansi2Str(finderName+fileName);
    if (mode == 0){
        stream.open(pathName.c_str(),ios::in);
    }else{
        stream.open(pathName.c_str(),ios::out|ios::trunc);
    }
}

void IOHelper::close(){
    stream.close();
}