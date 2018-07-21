//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LrcWin.h"
#include "Init.h"
#include "PlayList.h"
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
    AnsiString nowPlayMusicPathName = Form1->MediaPlayer->FileName ;
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














void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
/*
    *btn_Pre=*Form1->btn_Pre;
    *btn_Play=*Form1->btn_Play;
    *btn_Next=*Form1->btn_Next;
    *btn_openLrc=*Form1->btn_openLrc;
    *processBarPro=*Form1->processBarPro;
    *processBarbar=*Form1->processBarbar;
    *volumeBarPro=*Form1->volumeBarPro;
    *volumeBar=*Form1->volumeBar;
*/
    if (Form1->MediaPlayer->FileName!=""){
        Song *curSong = Form1->pathName2Song[Form1->MediaPlayer->FileName];
        for (int i=0;i<curSong->labels.size();i++){
            bool isAppear=false;
            for (int j=0;j<list_Label->Count;j++){
                if (curSong->labels[i]==list_Label->Items->Strings[j]){
                    isAppear=true;
                }
            }
            if (!isAppear){
                list_Label->Items->Add(curSong->labels[i]);
            }
        }
        if (curSong->highLight[0]!= -1){
            beginTime->Caption=(AnsiString)"beginTime:"+double2String(curSong->highLight[0]);
        }else{
            beginTime->Caption="beginTime:no set";
        }
        if (curSong->highLight[1]!= -1){
            endTime->Caption=(AnsiString)"endTime:"+double2String(curSong->highLight[1]);
        }else{
            endTime->Caption="endTime:no set";
        }
    }

}
//---------------------------------------------------------------------------







void __fastcall TForm3::rbtn_WinMinClick(TObject *Sender)
{
    SendMessage(Application->Handle,WM_SYSCOMMAND,SC_MINIMIZE,0);    
}
//---------------------------------------------------------------------------

void __fastcall TForm3::rbtn_WinCloseClick(TObject *Sender)
{
    this->Close();    
}
//---------------------------------------------------------------------------


void __fastcall TForm3::btn_labelClick(TObject *Sender)
{
    AnsiString newLabel;
    if (InputQuery("提示:","请输入标签",newLabel)&& newLabel!=""){
        Song *curSong = Form1->pathName2Song[Form1->MediaPlayer->FileName];
        curSong->labels.push_front(newLabel);
        ShowMessage("添加成功");
    }else{
        ShowMessage("取消添加");
    }

}
//---------------------------------------------------------------------------





void __fastcall TForm3::btn_highLightClick(TObject *Sender)
{
    double nowTime = Form1->MediaPlayer->Position/1000;
    Song *curSong = Form1->pathName2Song[Form1->MediaPlayer->FileName];
    if (curSong->highLight[0]==-1){
        curSong->highLight[0]=nowTime;
        ShowMessage("高潮开始");
        return ;
    }
    if (curSong->highLight[1]==-1){
        curSong->highLight[1]=nowTime;
        ShowMessage("高潮结束");
        return ;
    }
    ShowMessage("重新设置高潮部分");
    curSong->highLight[0]=-1;
    curSong->highLight[1]=-1;
}
//---------------------------------------------------------------------------





void __fastcall TForm3::btn_openPlayListClick(TObject *Sender)
{
    if (Form2->Visible==false){
        Form2->Left=Form1->Left+Form1->Width;
        Form2->Top=Form1->Top + Form1->Height-Form2->Height;
        Form2->Show();
    }else{
        Form2->Hide();
    }        
}
//---------------------------------------------------------------------------


void __fastcall TForm3::btn_openLrcClick(TObject *Sender)
{
    Form1->btn_openLrcClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::btn_PreClick(TObject *Sender)
{
    Form1->btn_PreClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::btn_PlayClick(TObject *Sender)
{
    Form1->btn_PlayClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::btn_NextClick(TObject *Sender)
{
    Form1->btn_NextClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::btn_FigureClick(TObject *Sender)
{
    Form1->btn_FigureClick(Sender);    
}
//---------------------------------------------------------------------------

void __fastcall TForm3::btn_DressTransClick(TObject *Sender)
{
    Form1->btn_DressTransClick(Sender);    
}
//---------------------------------------------------------------------------

