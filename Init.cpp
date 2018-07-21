//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Init.h"
#include "PlayList.h"
#include "LrcWin.h"
#include "SongList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner),songListLabel(6),
        songListBtn(6),songListBtnFlag(6),songListPage(0),
        alarmOn(false),lrcWord(7)
{
    listName2SongList["myFavorite"]= new SongList();
    listName2SongList["myFavorite"]->name="myFavorite";
    listName2SongList["msHistory"]= new SongList();
    listName2SongList["msHistory"]->name="msHistory";
    songListLabel[0]=lb_song0;
    songListLabel[1]=lb_song1;
    songListLabel[2]=lb_song2;
    songListLabel[3]=lb_song3;
    songListLabel[4]=lb_song4;
    songListLabel[5]=lb_song5;
    songListBtn[0]=btn_song0;
    songListBtn[1]=btn_song1;
    songListBtn[2]=btn_song2;
    songListBtn[3]=btn_song3;
    songListBtn[4]=btn_song4;
    songListBtn[5]=btn_song5;
    playMode=3;
}
//---------------------------------------------------------------------------
void TForm1::nextPlay(void){
    if (playMode ==3){
        
    }
}




void __fastcall TForm1::btn_LoveMsClick(TObject *Sender)
{
    if (grp_SongList->Visible == false){
        grp_SongList->Visible = true;
        grp_PreMs->Visible = false;
    }else{
        if (nowOpenListName!="myFavorite"){
            grp_SongList->Visible = true;
            grp_PreMs->Visible = false;
        }else{
            grp_SongList->Visible = false;
            grp_PreMs->Visible = true;
            selectOn.clear();
        }
    }
    nowOpenListName="myFavorite";
}
//---------------------------------------------------------------------------
void TForm1::playMusic(AnsiString pathName){
    MediaPlayer->FileName=pathName;
    MediaPlayer->Open();
    MediaPlayer->Play();
    playingSongName->Caption = takeFileName(pathName);
    //高潮模式
    /*Song *curSong = pathName2Song[Form1->MediaPlayer->FileName];
    if (playMode ==3&& curSong->highLight[0]!=-1 && curSong->highLight[1] !=-1){
        MediaPlayer->Position = 1000*curSong->highLight[0];
    } */
    delete musicLrc;
    musicLrc=NULL;
    musicLrc= new LrcHelper(pathName);
    musicLrc->prtLrc(lrcTimer);
    Form3->txt_SongName->Caption = takeFileName(MediaPlayer->FileName);
    Form3->list_Label->Clear();
    //dsadsadas
}
void TForm1::push_front(AnsiString str){
    bool flag=false;
    int index=-1;
    for (int i=0;i<listName2SongList["msHistory"]->songs.size();i++){
        if (str == listName2SongList["msHistory"]->songs[i]){
            flag=true;
            index=i;
        }
    }
    if (flag==true){
        listName2SongList["msHistory"]->songs.erase(listName2SongList["msHistory"]->songs.begin() +index);
    }
    listName2SongList["msHistory"]->songs.push_front(str);
}

void __fastcall TForm1::lrcTimerTimer(TObject *Sender)
{
    double nowTime = MediaPlayer->Position/1000;
    double songLength = MediaPlayer->Length/1000;
    double lrcTime = nowTime + musicLrc->offset;


    int leftPos=24;
    int rightPos=272;
    int curPos=nowTime/songLength*(rightPos-leftPos)+leftPos;
    processBarbar->Left=curPos;
    processBarPro->Width=curPos-processBarPro->Left;
    //播放歌词
    if (musicLrc->isFileExist){
        int index=musicLrc->lrc.size()-1;
        for (int i=0;i < musicLrc->lrc.size();i++){
            if (lrcTime <= musicLrc->lrc[i].time){
                index=i-1;
                break;
            }
        }
        for (int i=0;i <7;i++){
            if (index-3+i<0 || index-3+i>=musicLrc->lrc.size() ){
                 lrcWord[i]->Caption = " ";
            }else{
                lrcWord[i]->Caption = musicLrc->lrc[index-3+i].text;
            }
        }
    }else{
        for (int i=0;i<7;i++){
            lrcWord[i]->Caption = (AnsiString)" ";
        }
        lrcWord[3]->Caption = (AnsiString)"No .Lrc File";
    }
    Song *curSong = pathName2Song[Form1->MediaPlayer->FileName];
    if (MediaPlayer->Position>=MediaPlayer->Length){
        lrcTimer->Enabled=false;
        musicLrc->index=0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_openPlayListClick(TObject *Sender)
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

void __fastcall TForm1::btn_openLrcClick(TObject *Sender)
{
    if (Form3->Visible==false){
        Form3->Left=Form1->Left;
        Form3->Top=Form1->Top;
        Form3->Show();
        Form1->Hide();
    } else{
        Form1->Left=Form3->Left;
        Form1->Top=Form3->Top;
        Form3->Hide();
        Form1->Show();
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
            int pos = MediaPlayer->Length*(processBarbar->Left-24)/(272-24);

            if (pos>=MediaPlayer->Length){
                MediaPlayer->Position=MediaPlayer->Length;
            }else{
                MediaPlayer->Position=pos;
            }
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
            Song *ptr = new Song(song);
            pathName2Song[song]=ptr;
        }
        playMusic(song);
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


















void __fastcall TForm1::TrackBarChange(TObject *Sender)
{
    int volume = TrackBar->Position* TrackBar->Position *(65535/100);
    waveOutSetVolume(0,MAKELONG(volume,volume));
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::volumeBarMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y){
      int startX=33;
      int endX=105;

    if(Shift.Contains(ssLeft)){
        int moveX=X;
        volumeBar->Left += moveX;
        if (volumeBar->Left < startX){
            volumeBar->Left=startX;
        }else if (volumeBar->Left>endX){
            volumeBar->Left=endX;
        }
        volumeBarPro->Width=volumeBar->Left-volumeBarPro->Left;
        TrackBar->Position = 10*(volumeBar->Left-startX)/(endX-startX);
    }
}
//---------------------------------------------------------------------------







void __fastcall TForm1::rbtn_WinMinClick(TObject *Sender)
{
    SendMessage(Application->Handle,WM_SYSCOMMAND,SC_MINIMIZE,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rbtn_WinCloseClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------




void __fastcall TForm1::btn_CreMsListClick(TObject *Sender)
{

    AnsiString songListName;
    InputQuery("提示：", "输入你的歌单名：", songListName);  // s是引用传入
    if (listName2SongList[songListName]==NULL){
        listName2SongList[songListName]=new SongList();
        listName2SongList[songListName]->name = songListName;
        listName2SongList[songListName]->sortKey = "name";
        ShowMessage(songListName+"创建成功");
    }else{
        ShowMessage("歌单名重复");
    }
    Label1->Caption = listName2SongList.size();
}
//---------------------------------------------------------------------------





void __fastcall TForm1::globle_timerTimer(TObject *Sender)
{
    //init Lrc pointer;
    lrcWord[0]=Form3->lbl_lrc0;
    lrcWord[1]=Form3->lbl_lrc1;
    lrcWord[2]=Form3->lbl_lrc2;
    lrcWord[3]=Form3->lbl_lrc3;
    lrcWord[4]=Form3->lbl_lrc4;
    lrcWord[5]=Form3->lbl_lrc5;
    lrcWord[6]=Form3->lbl_lrc6;
    for (int i=0;i<7;i++){
        lrcWord[i]->Alignment = taCenter;
        lrcWord[i]->Layout= tlCenter;
    }
    //end init
    //维护整体
    //msHistory=listName2SongList["msHistory"]->songs;
    // 定时关机
    if (alarmOn && clock()/CLOCKS_PER_SEC > alarmEndTime){
        this->Close();
    }
    // 定时关机结束
    btn_hisMs1->Caption=" ";
    btn_hisMs2->Caption=" ";
    btn_hisMs3->Caption=" ";
    btn_hisMs4->Caption=" ";
    if (listName2SongList["msHistory"]->songs.size()>3){
        btn_hisMs1->Caption = takeFileName(listName2SongList["msHistory"]->songs[3]);
    }
    if (listName2SongList["msHistory"]->songs.size()>2){
        btn_hisMs2->Caption = takeFileName(listName2SongList["msHistory"]->songs[2]);
    }
    if (listName2SongList["msHistory"]->songs.size()>1){
        btn_hisMs3->Caption = takeFileName(listName2SongList["msHistory"]->songs[1]);
    }
    if (listName2SongList["msHistory"]->songs.size()>0){
        btn_hisMs4->Caption = takeFileName(listName2SongList["msHistory"]->songs[0]);
    }
    lb_SongListName->Caption = nowOpenListName;
    for (int i=0;i<6;i++){
        songListLabel[i]->Visible=false;
        songListLabel[i]->Caption="空   ";
        songListBtn[i]->Visible=false;
        btn_selctAll->Visible=false;
    }
    map<AnsiString,SongList*>::iterator item =listName2SongList.begin();
    while (item!=listName2SongList.end()){
        //输出所有歌单在songListList
        bool isExsist=false;
        for (int i=0;i<songListList->Count ;i++){
            if (songListList->Items->Strings[i] ==item->first){
                isExsist = true;
            }
        }
        if (!isExsist){
            songListList->Items->Add(item->first);
        }
        //结束输出
        if (item->second->name==nowOpenListName){//找到打开的歌单
            for (int i=0;i<item->second->songs.size();i++){
                if (6*songListPage<=i && i<6*songListPage+6){
                    btn_selctAll->Visible=true;
                    songListLabel[i%6]->Visible=true;
                    songListLabel[i%6]->Caption=takeFileName(item->second->songs[i]);
                    songListBtn[i%6]->Visible=true;
                    songListBtn[i%6]->Caption = selectOn[item->second->songs[i]];
                }
            }
            btn_preSongListPage->Visible=false;
            btn_nextSongListPage->Visible=true;
            if (songListPage==0){
                btn_preSongListPage->Visible=false;

            }
            if(songListPage == item->second->songs.size()/ 6){
                btn_nextSongListPage->Visible=false;
            }
        }
        item++;
    }

}
//---------------------------------------------------------------------------
















void __fastcall TForm1::btn_HisMsClick(TObject *Sender)
{
    if (grp_SongList->Visible == false){
        grp_SongList->Visible = true;
        grp_PreMs->Visible = false;
    }else{
        if (nowOpenListName!="msHistory"){
            grp_SongList->Visible = true;
            grp_PreMs->Visible = false;
        }else{
            grp_SongList->Visible = false;
            grp_PreMs->Visible = true;
        }
    }
    nowOpenListName="msHistory";
}
//---------------------------------------------------------------------------





void __fastcall TForm1::btn_nextSongListPageClick(TObject *Sender)
{
    songListPage++;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_preSongListPageClick(TObject *Sender)
{
    songListPage--;    
}
//---------------------------------------------------------------------------










void __fastcall TForm1::btn_selctAllClick(TObject *Sender)
{
    SongList *ptr = listName2SongList[nowOpenListName];
    for (int i=0;i<ptr->songs.size();i++){
        if (selectOn[ptr->songs[i]]>0){

        }else{
            selectOn[ptr->songs[i]]++;
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_PlaySelctClick(TObject *Sender)
{
    map<AnsiString,int>::iterator item = selectOn.begin();
    while (item!=selectOn.end()){
        if (item->second > 0){
            AnsiString song = item->first;
            if (cntMusic[song] == 0){
                Form2->playListBox->Items->Add(takeFileName(song));
                cntMusic[song]++;
                fileName2PathName[takeFileName(song)] = song;
                Song *ptr = new Song(song);
                pathName2Song[song]=ptr;
            }
            playMusic(song);
        }
        item++;
    }

    selectOn.clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_delSongListClick(TObject *Sender)
{
    map<AnsiString,int>::iterator item = selectOn.begin();
    SongList *ptr = listName2SongList[nowOpenListName];
    while (item!=selectOn.end()){
        if (item->second > 0){
            int index=ptr->getIndex(item->first);
            if (index!=-1){
                ptr->songs.erase(ptr->songs.begin()+index);
            }
        }
        item++;
    }
    selectOn.clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::btn_song0Click(TObject *Sender)
{
    SongList* ptr = listName2SongList[nowOpenListName];
    if (selectOn[ptr->songs[songListPage*6+0]]>0){
        selectOn[ptr->songs[songListPage*6+0]]--;
    }else{
        selectOn[ptr->songs[songListPage*6+0]]++;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_song1Click(TObject *Sender)
{
    SongList* ptr = listName2SongList[nowOpenListName];
    if (selectOn[ptr->songs[songListPage*6+1]]>0){
        selectOn[ptr->songs[songListPage*6+1]]--;
    }else{
        selectOn[ptr->songs[songListPage*6+1]]++;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_song2Click(TObject *Sender)
{
    SongList* ptr = listName2SongList[nowOpenListName];
    if (selectOn[ptr->songs[songListPage*6+2]]>0){
        selectOn[ptr->songs[songListPage*6+2]]--;
    }else{
        selectOn[ptr->songs[songListPage*6+2]]++;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_song3Click(TObject *Sender)
{
    SongList* ptr = listName2SongList[nowOpenListName];

    if (selectOn[ptr->songs[songListPage*6+3]]>0){
        selectOn[ptr->songs[songListPage*6+3]]--;
    }else{
        selectOn[ptr->songs[songListPage*6+3]]++;
    }    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_song4Click(TObject *Sender)
{
    SongList* ptr = listName2SongList[nowOpenListName];
    if (ptr==NULL){
        return;
    }
    if (selectOn[ptr->songs[songListPage*6+4]]>0){
        selectOn[ptr->songs[songListPage*6+4]]--;
    }else{
        selectOn[ptr->songs[songListPage*6+4]]++;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_song5Click(TObject *Sender)
{
    SongList* ptr = listName2SongList[nowOpenListName];
    if (ptr==NULL){
        return;
    }
    if (selectOn[ptr->songs[songListPage*6+5]]>0){
        selectOn[ptr->songs[songListPage*6+5]]--;
    }else{
        selectOn[ptr->songs[songListPage*6+5]]++;
    }
}
//---------------------------------------------------------------------------








void __fastcall TForm1::songListListDblClick(TObject *Sender)
{
    int index = songListList->ItemIndex;
    nowOpenListName = songListList->Items->Strings[index];
    if (grp_SongList->Visible == false){
        grp_SongList->Visible = true;
        grp_PreMs->Visible = false;
    }
}
//---------------------------------------------------------------------------




void __fastcall TForm1::btn_SongListSearchClick(TObject *Sender)
{
    AnsiString searchStr = txt_songListSearch->Text;
    SongList *ptr = listName2SongList[nowOpenListName];
    int index=-1;
    for (int i=0;i< ptr->songs.size();i++){
        if (searchStr == takeFileName(ptr->songs[i])){
            index = i;
        }
    }
    if (index==-1){
        ShowMessage((AnsiString)"Can't find "+searchStr+" in "+nowOpenListName);
    }else{
        songListPage=index/6;
        selectOn[ptr->songs[index]]++;
    }
    
}
//---------------------------------------------------------------------------


void __fastcall TForm1::btn_AlarmMsClick(TObject *Sender)
{
    AnsiString inputStr;
    if (alarmOn==false){
        if (InputQuery("提示：", "设定在多少分钟后关闭播放器，例:60", inputStr)){
            alarmBeginTime = clock()/CLOCKS_PER_SEC;
            alarmEndTime = atof(inputStr.c_str())*60+alarmBeginTime;
            alarmOn=true;
        }
    }else{
        double nowTime = clock()/CLOCKS_PER_SEC;
        double duringTime =(alarmEndTime-nowTime)/60;
        ostringstream strs;
        strs << duringTime;
        string str = strs.str();
        AnsiString duringTimeString = str.c_str();
        if (InputQuery("提示：", "设定在"+ duringTimeString+"分钟后关闭播放器，请问要修改至多少分钟？则点击取消关闭闹钟", inputStr)) {
            alarmBeginTime = clock()/CLOCKS_PER_SEC;
            alarmEndTime = atof(inputStr.c_str())*60+alarmBeginTime;
            alarmOn=true;
        }else{
            alarmOn=false;
        }
    }
}
//---------------------------------------------------------------------------









void __fastcall TForm1::playMusic1Click(TObject *Sender)
{
    SongList* ptr = listName2SongList[nowOpenListName];
    AnsiString song = ptr->songs[songListPage*6+0];
    if (cntMusic[song] == 0){
        Form2->playListBox->Items->Add(takeFileName(song));
        cntMusic[song]++;
        fileName2PathName[takeFileName(song)] = song;
        Song *ptr = new Song(song);
        pathName2Song[song]=ptr;
    }
    playMusic(song);    
}
//---------------------------------------------------------------------------



void __fastcall TForm1::playMusic2Click(TObject *Sender)
{
    SongList* ptr = listName2SongList[nowOpenListName];
    AnsiString song = ptr->songs[songListPage*6+1];
    if (cntMusic[song] == 0){
        Form2->playListBox->Items->Add(takeFileName(song));
        cntMusic[song]++;
        fileName2PathName[takeFileName(song)] = song;
        Song *ptr = new Song(song);
        pathName2Song[song]=ptr;
    }
    playMusic(song);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::playMusic3Click(TObject *Sender)
{
    SongList* ptr = listName2SongList[nowOpenListName];
    AnsiString song = ptr->songs[songListPage*6+2];
    if (cntMusic[song] == 0){
        Form2->playListBox->Items->Add(takeFileName(song));
        cntMusic[song]++;
        fileName2PathName[takeFileName(song)] = song;
        Song *ptr = new Song(song);
        pathName2Song[song]=ptr;
    }
    playMusic(song);    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::playMusic4Click(TObject *Sender)
{
    SongList* ptr = listName2SongList[nowOpenListName];
    AnsiString song = ptr->songs[songListPage*6+3];
    if (cntMusic[song] == 0){
        Form2->playListBox->Items->Add(takeFileName(song));
        cntMusic[song]++;
        fileName2PathName[takeFileName(song)] = song;
        Song *ptr = new Song(song);
        pathName2Song[song]=ptr;
    }
    playMusic(song);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::playMusic5Click(TObject *Sender)
{
    SongList* ptr = listName2SongList[nowOpenListName];
    AnsiString song = ptr->songs[songListPage*6+4];
    if (cntMusic[song] == 0){
        Form2->playListBox->Items->Add(takeFileName(song));
        cntMusic[song]++;
        fileName2PathName[takeFileName(song)] = song;
        Song *ptr = new Song(song);
        pathName2Song[song]=ptr;
    }
    playMusic(song);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::playMusic6Click(TObject *Sender)
{
    SongList* ptr = listName2SongList[nowOpenListName];
    AnsiString song = ptr->songs[songListPage*6+5];
    if (cntMusic[song] == 0){
        Form2->playListBox->Items->Add(takeFileName(song));
        cntMusic[song]++;
        fileName2PathName[takeFileName(song)] = song;
        Song *ptr = new Song(song);
        pathName2Song[song]=ptr;
    }
    playMusic(song);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::del1Click(TObject *Sender)
{
    SongList *ptr = listName2SongList[nowOpenListName];
    AnsiString song = ptr->songs[songListPage*6+0];
    int index=ptr->getIndex(song);
    if (index!=-1){
        ptr->songs.erase(ptr->songs.begin()+index);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::del2Click(TObject *Sender)
{
    SongList *ptr = listName2SongList[nowOpenListName];
    AnsiString song = ptr->songs[songListPage*6+1];
    int index=ptr->getIndex(song);
    if (index!=-1){
        ptr->songs.erase(ptr->songs.begin()+index);
    }    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::del3Click(TObject *Sender)
{
    SongList *ptr = listName2SongList[nowOpenListName];
    AnsiString song = ptr->songs[songListPage*6+2];
    int index=ptr->getIndex(song);
    if (index!=-1){
        ptr->songs.erase(ptr->songs.begin()+index);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::del4Click(TObject *Sender)
{
    SongList *ptr = listName2SongList[nowOpenListName];
    AnsiString song = ptr->songs[songListPage*6+3];
    int index=ptr->getIndex(song);
    if (index!=-1){
        ptr->songs.erase(ptr->songs.begin()+index);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::del5Click(TObject *Sender)
{
    SongList *ptr = listName2SongList[nowOpenListName];
    AnsiString song = ptr->songs[songListPage*6+4];
    int index=ptr->getIndex(song);
    if (index!=-1){
        ptr->songs.erase(ptr->songs.begin()+index);
    }    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::del6Click(TObject *Sender)
{
    SongList *ptr = listName2SongList[nowOpenListName];
    AnsiString song = ptr->songs[songListPage*6+5];
    int index=ptr->getIndex(song);
    if (index!=-1){
        ptr->songs.erase(ptr->songs.begin()+index);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::addMyFav1Click(TObject *Sender)
{
    SongList *ptr = listName2SongList[nowOpenListName];
    AnsiString curMusicPathName = ptr->songs[songListPage*6+0];
    bool flag=false;
    int index=0;
    for (int i=0;i< Form1->listName2SongList["myFavorite"]->songs.size();i++){
        if (curMusicPathName==Form1->listName2SongList["myFavorite"]->songs[i]){
            flag=true;
            index=i;
        }
    }
    if (flag==true){
        Form1->listName2SongList["myFavorite"]->songs.erase(Form1->listName2SongList["myFavorite"]->songs.begin()+index);
    }
    Form1->listName2SongList["myFavorite"]->songs.push_back(curMusicPathName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::addMyFav2Click(TObject *Sender)
{
    SongList *ptr = listName2SongList[nowOpenListName];
    AnsiString curMusicPathName = ptr->songs[songListPage*6+1];
    bool flag=false;
    int index=0;
    for (int i=0;i< Form1->listName2SongList["myFavorite"]->songs.size();i++){
        if (curMusicPathName==Form1->listName2SongList["myFavorite"]->songs[i]){
            flag=true;
            index=i;
        }
    }
    if (flag==true){
        Form1->listName2SongList["myFavorite"]->songs.erase(Form1->listName2SongList["myFavorite"]->songs.begin()+index);
    }
    Form1->listName2SongList["myFavorite"]->songs.push_back(curMusicPathName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::addMyFav3Click(TObject *Sender)
{
    SongList *ptr = listName2SongList[nowOpenListName];
    AnsiString curMusicPathName = ptr->songs[songListPage*6+2];
    bool flag=false;
    int index=0;
    for (int i=0;i< Form1->listName2SongList["myFavorite"]->songs.size();i++){
        if (curMusicPathName==Form1->listName2SongList["myFavorite"]->songs[i]){
            flag=true;
            index=i;
        }
    }
    if (flag==true){
        Form1->listName2SongList["myFavorite"]->songs.erase(Form1->listName2SongList["myFavorite"]->songs.begin()+index);
    }
    Form1->listName2SongList["myFavorite"]->songs.push_back(curMusicPathName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::addMyFav4Click(TObject *Sender)
{
    SongList *ptr = listName2SongList[nowOpenListName];
    AnsiString curMusicPathName = ptr->songs[songListPage*6+3];
    bool flag=false;
    int index=0;
    for (int i=0;i< Form1->listName2SongList["myFavorite"]->songs.size();i++){
        if (curMusicPathName==Form1->listName2SongList["myFavorite"]->songs[i]){
            flag=true;
            index=i;
        }
    }
    if (flag==true){
        Form1->listName2SongList["myFavorite"]->songs.erase(Form1->listName2SongList["myFavorite"]->songs.begin()+index);
    }
    Form1->listName2SongList["myFavorite"]->songs.push_back(curMusicPathName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::addMyFav5Click(TObject *Sender)
{
    SongList *ptr = listName2SongList[nowOpenListName];
    AnsiString curMusicPathName = ptr->songs[songListPage*6+4];
    bool flag=false;
    int index=0;
    for (int i=0;i< Form1->listName2SongList["myFavorite"]->songs.size();i++){
        if (curMusicPathName==Form1->listName2SongList["myFavorite"]->songs[i]){
            flag=true;
            index=i;
        }
    }
    if (flag==true){
        Form1->listName2SongList["myFavorite"]->songs.erase(Form1->listName2SongList["myFavorite"]->songs.begin()+index);
    }
    Form1->listName2SongList["myFavorite"]->songs.push_back(curMusicPathName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::addMyFav6Click(TObject *Sender)
{
    SongList *ptr = listName2SongList[nowOpenListName];
    AnsiString curMusicPathName = ptr->songs[songListPage*6+5];
    bool flag=false;
    int index=0;
    for (int i=0;i< Form1->listName2SongList["myFavorite"]->songs.size();i++){
        if (curMusicPathName==Form1->listName2SongList["myFavorite"]->songs[i]){
            flag=true;
            index=i;
        }
    }
    if (flag==true){
        Form1->listName2SongList["myFavorite"]->songs.erase(Form1->listName2SongList["myFavorite"]->songs.begin()+index);
    }
    Form1->listName2SongList["myFavorite"]->songs.push_back(curMusicPathName);
}
//---------------------------------------------------------------------------

