//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Init.h"
#include "PlayList.h"
#include "LrcWin.h"
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
        AnsiString song = diaLoadMs->Files->Strings[i];
        if (cntMusic[song] == 0){
            Form2->playListBox->Items->Add(takeFileName(song));
            cntMusic[song]++;
            fileName2PathName[takeFileName(song)] = song;
        }
    }
}
//---------------------------------------------------------------------------
void TForm1::playMusic(AnsiString pathName){
    MediaPlayer->FileName=pathName;
    MediaPlayer->Open();
    MediaPlayer->Play();
    playingSongName->Caption = takeFileName(pathName);
    AnsiString lrcName = refMusic2Lrc(pathName);
    delete musicLrc;
    musicLrc=NULL;
    musicLrc= new LrcHelper(lrcName);
    musicLrc->prtLrc(lrcTimer);
}


void __fastcall TForm1::lrcTimerTimer(TObject *Sender)
{
    double nowTime = clock() * 1.0 / CLOCKS_PER_SEC - musicLrc->beginTime;
    if (nowTime > musicLrc->lrc[musicLrc->index].time) {
        Form3->lrcList->Lines->Add(musicLrc->lrc[musicLrc->index].text);
        musicLrc->index++;
    }
    if (musicLrc->index==musicLrc->lrc.size()-1){
          lrcTimer->Enabled=false;
          musicLrc->index=0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_openPlayListClick(TObject *Sender)
{
    if (Form2->Visible==false){
    Form2->Show();
    }else{
    Form2->Hide();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_openLrcClick(TObject *Sender)
{
    if (Form3->Visible==false){
        Form3->Show();
        //Form1->Hide();
    } else{
        Form3->Hide();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_PlayClick(TObject *Sender)
{
    MediaPlayer->Mode;
    MediaPlayer->Pause();
}
//---------------------------------------------------------------------------

