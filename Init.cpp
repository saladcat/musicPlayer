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

    delete musicLrc;
    musicLrc=NULL;
    musicLrc= new LrcHelper(pathName);
    musicLrc->prtLrc(lrcTimer);
    //dsadsadas
    if (msHistory.size()>3){
        btn_hisMs1->Caption = takeFileName(msHistory[3]);
    }
    if (msHistory.size()>2){
        btn_hisMs2->Caption = takeFileName(msHistory[2]);
    }
    if (msHistory.size()>1){
        btn_hisMs3->Caption = takeFileName(msHistory[1]);
    }
    if (msHistory.size()>0){
        btn_hisMs4->Caption = takeFileName(msHistory[0]);
    }
}
void TForm1::push_front(AnsiString str){
    bool flag=false;
    int index=-1;
    for (int i=0;i<msHistory.size();i++){
        if (str == msHistory[i]){
            flag=true;
            index=i;
        }
    }
    if (flag==true){
        msHistory.erase(msHistory.begin() +index);
    }
    msHistory.push_front(str);
}

void __fastcall TForm1::lrcTimerTimer(TObject *Sender)
{
    double nowTime = MediaPlayer->Position/1000;
    double songLength = MediaPlayer->Length/1000;
    double lrcTime = nowTime + musicLrc->offset;


    int leftPos=128;
    int rightPos=128+287;
    int curPos=nowTime/songLength*(rightPos-leftPos)+leftPos;
    processBarbar->Left=curPos;
    if (musicLrc->isFileExist){
        if (lrcTime > musicLrc->lrc[musicLrc->index].time) {
            Form3->lrcList->Lines->Add(musicLrc->lrc[musicLrc->index].text);
            musicLrc->index++;
        }
        if (MediaPlayer->Position>=MediaPlayer->Length){
              lrcTimer->Enabled=false;
              musicLrc->index=0;
        }
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
    if (MediaPlayer->Wait){
        MediaPlayer->Play();
    }else{
        MediaPlayer->Pause();
    }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::processBarbarMouseMove(TObject *Sender,
TShiftState Shift, int X, int Y){
    if (musicLrc!=NULL){
        if(Shift.Contains(ssLeft)){
            int moveX=X;
            processBarbar->Left += moveX;
            MediaPlayer->Position=MediaPlayer->Length*(processBarbar->Left-128)/(128+287-128);
            MediaPlayer->Play();
            if(moveX<0){
                musicLrc->index=0;
            }
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_SearchClick(TObject *Sender)
{
    AnsiString str = txt_Search->Text;
    if (fileName2PathName[str]!=""){
        playMusic(fileName2PathName[str]);
    }else{
        playingSongName->Caption = "can't find the music";
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::btn_LocalMsClick(TObject *Sender)
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

void __fastcall TForm1::btn_NextClick(TObject *Sender)
{
    int index = Form2->playListBox->ItemIndex;
    if (index >= Form2->playListBox->Count-1){
        index=0;
    }else{
        index++;
    }
    Form2->playListBox->ItemIndex = index;
    AnsiString pathName = fileName2PathName[Form2->playListBox->Items->Strings[index]];
    playMusic(pathName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_PreClick(TObject *Sender)
{
    int index = Form2->playListBox->ItemIndex;
    if (index <= 0){
        index= Form2->playListBox->Count-1;
    }else{
        index--;
    }
    Form2->playListBox->ItemIndex = index;
    AnsiString pathName = fileName2PathName[Form2->playListBox->Items->Strings[index]];
    playMusic(pathName);
}
//---------------------------------------------------------------------------

