//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Init.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------





void __fastcall TForm1::btn_LoveMsClick(TObject *Sender)
{
    diaLoadMs->Execute();
    for (int i=0;i<diaLoadMs->Files->Count;i++){
        AnsiString song = diaChooseMusic->Files->Strings[i];
        if (cntMusic[song] == 0){
            musicList->Items->Add(takeFileName(song));
            cntMusic[song]++;
            fileName2PathName[takeFileName(song)] = song;
        }
    }
}
//---------------------------------------------------------------------------

