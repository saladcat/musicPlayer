//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PlayList.h"
#include "Init.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::playListBoxDblClick(TObject *Sender)
{
    int index = playListBox->ItemIndex;
    AnsiString fileName = playListBox->Items->Strings[index];
    AnsiString pathName = Form1->fileName2PathName[fileName];
    Form1->playMusic(pathName);
}
//---------------------------------------------------------------------------














void __fastcall TForm2::playClick(TObject *Sender)
{
    Form1->playMusic(Form1->fileName2PathName[playListBox->Items->Strings[playListBox->ItemIndex]]);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::delClick(TObject *Sender)
{
    playListBox->Items->Delete(playListBox->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::favoriteClick(TObject *Sender)
{
    AnsiString pathName = Form1->fileName2PathName[playListBox->Items->Strings[playListBox->ItemIndex]];
    push_song("myFavorite",pathName);
}
//---------------------------------------------------------------------------


