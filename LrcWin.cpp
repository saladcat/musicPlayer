//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LrcWin.h"
#include "Init.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------





void __fastcall TForm3::btn_backFormClick(TObject *Sender)
{
    if (Form1->Visible == false){
        Form1->Visible =true;
        Form1->Left=Form3->Left;
        Form1->Top=Form3->Top;
        Form3->Visible=false;
    }    
}
//---------------------------------------------------------------------------

void __fastcall TForm3::btn_addMyFaClick(TObject *Sender)
{
    AnsiString nowPlayMusicPathName = Form1->MediaPlayer->FileName;
    bool flag=false;
    int index=0;
    for (int i=0;i< Form1->listName2SongList["myFavorite"]->songs.size();i++){
        if (nowPlayMusicPathName==Form1->listName2SongList["myFavorite"]->songs[i]){
            flag=true;
            index=i;
        }
    }
    if (flag==true){
        Form1->listName2SongList["myFavorite"]->songs.erase(Form1->listName2SongList["myFavorite"]->songs.begin()+index);
    }
    Form1->listName2SongList["myFavorite"]->songs.push_back(nowPlayMusicPathName);

}
//---------------------------------------------------------------------------










