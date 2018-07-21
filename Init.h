//---------------------------------------------------------------------------

#ifndef InitH
#define InitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <Graphics.hpp>
#include <MPlayer.hpp>
#include <CheckLst.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
#include <jpeg.hpp>
#include <Menus.hpp>

#include <algorithm>
#include "musicHelper.h"
#include "SongList.h"
#include "Song.h"
#include "LrcHelper.h"
#include <Dialogs.hpp>
#include <MPlayer.hpp>
#include <Buttons.hpp>
#include <Graphics.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *grp_Self;
        TButton *btn_LoveMs;
        TButton *btn_HisMs;
        TButton *btn_MoodMs;
        TButton *btn_AlarmMs;
        TButton *btn_LocalMs;
        TGroupBox *grp_MsList;
        TButton *btn_Figure;
        TGroupBox *grp_Init_MsList;
        TButton *btn_CreMsList;
        TButton *btn_MsList01;
        TButton *btn_MsList02;
        TButton *btn_MsList03;
        TGroupBox *grp_ConWins;
        TRadioButton *rbtn_WinMin;
        TRadioButton *rbtn_WinClose;
        TGroupBox *grp_PreMs;
        TGroupBox *grp_Search;
        TEdit *txt_Search;
        TButton *btn_Search;
        TButton *btn_DressTrans;
        TGroupBox *grp_MsCon;
        TButton *btn_Play;
        TButton *btn_Next;
        TButton *btn_Pre;
        TGroupBox *grp_Playig;
    TOpenDialog *diaLoadMs;
    TMediaPlayer *MediaPlayer;
    TLabel *playingSongName;
    TTimer *lrcTimer;
    TSpeedButton *btn_openPlayList;
    TSpeedButton *btn_openLrc;
    TImage *Image1;
    TImage *processBarbar;
    TSpeedButton *btn_hisMs1;
    TSpeedButton *btn_hisMs2;
    TSpeedButton *btn_hisMs3;
    TSpeedButton *btn_hisMs4;
    TGroupBox *grp_SongList;
    TTrackBar *TrackBar;
    TEdit *Edit1;
    TImage *volumeBar;
    TLabel *Label1;
    TTimer *globle_timer;
    TGroupBox *GroupBox1;
    TSpeedButton *btn_song5;
    TLabel *lb_song0;
    TSpeedButton *btn_song1;
    TLabel *lb_song1;
    TSpeedButton *SpeedButton3;
    TLabel *Label4;
    TSpeedButton *btn_song2;
    TLabel *lb_song2;
    TSpeedButton *btn_song3;
    TLabel *lb_song3;
    TSpeedButton *btn_song4;
    TLabel *lb_song4;
    TSpeedButton *btn_song0;
    TLabel *lb_song5;
    TSpeedButton *btn_nextSongListPage;
    TSpeedButton *btn_preSongListPage;
    TLabel *lb_SongListName;
    TSpeedButton *btn_PlaySelct;
    TSpeedButton *btn_delSongList;
    TSpeedButton *btn_sort;
    TEdit *txt_songListSearch;
    TSpeedButton *btn_SongListSearch;
    TSpeedButton *btn_selctAll;
    TListBox *songListList;
    TGroupBox *grp_processBar;
    TGroupBox *grp_volumeBar;
    TImage *processBarPro;
    TImage *volumeBarPro;
    TPopupMenu *PopupMenu1;
    TPopupMenu *PopupMenu2;
    TPopupMenu *PopupMenu3;
    TPopupMenu *PopupMenu4;
    TPopupMenu *PopupMenu5;
    TPopupMenu *PopupMenu6;
    TMenuItem *playMusic1;
    TMenuItem *addMyFav1;
    TMenuItem *del1;
    TMenuItem *playMusic2;
    TMenuItem *addMyFav2;
    TMenuItem *del2;
    TMenuItem *playMusic3;
    TMenuItem *addMyFav3;
    TMenuItem *del3;
    TMenuItem *playMusic4;
    TMenuItem *addMyFav4;
    TMenuItem *del4;
    TMenuItem *playMusic5;
    TMenuItem *addMyFav5;
    TMenuItem *del5;
    TMenuItem *playMusic6;
    TMenuItem *addMyFav6;
    TMenuItem *del6;
    void __fastcall btn_LoveMsClick(TObject *Sender);
    void __fastcall lrcTimerTimer(TObject *Sender);
    void __fastcall btn_openPlayListClick(TObject *Sender);
    void __fastcall btn_openLrcClick(TObject *Sender);
    void __fastcall btn_PlayClick(TObject *Sender);
    void __fastcall processBarbarMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
    void __fastcall btn_SearchClick(TObject *Sender);
    void __fastcall btn_LocalMsClick(TObject *Sender);
    void __fastcall btn_NextClick(TObject *Sender);
    void __fastcall btn_PreClick(TObject *Sender);
    void __fastcall TrackBarChange(TObject *Sender);
    void __fastcall volumeBarMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall rbtn_WinMinClick(TObject *Sender);
    void __fastcall rbtn_WinCloseClick(TObject *Sender);
    void __fastcall btn_CreMsListClick(TObject *Sender);
    void __fastcall globle_timerTimer(TObject *Sender);
    void __fastcall btn_HisMsClick(TObject *Sender);
    void __fastcall btn_nextSongListPageClick(TObject *Sender);
    void __fastcall btn_preSongListPageClick(TObject *Sender);
    void __fastcall btn_selctAllClick(TObject *Sender);
    void __fastcall btn_PlaySelctClick(TObject *Sender);
    void __fastcall btn_delSongListClick(TObject *Sender);
    void __fastcall btn_song0Click(TObject *Sender);
    void __fastcall btn_song1Click(TObject *Sender);
    void __fastcall btn_song2Click(TObject *Sender);
    void __fastcall btn_song3Click(TObject *Sender);
    void __fastcall btn_song4Click(TObject *Sender);
    void __fastcall btn_song5Click(TObject *Sender);
    void __fastcall songListListDblClick(TObject *Sender);
    void __fastcall btn_SongListSearchClick(TObject *Sender);
    void __fastcall btn_AlarmMsClick(TObject *Sender);
    void __fastcall playMusic1Click(TObject *Sender);
    void __fastcall playMusic2Click(TObject *Sender);
    void __fastcall playMusic3Click(TObject *Sender);
    void __fastcall playMusic4Click(TObject *Sender);
    void __fastcall playMusic5Click(TObject *Sender);
    void __fastcall playMusic6Click(TObject *Sender);
    void __fastcall del1Click(TObject *Sender);
    void __fastcall del2Click(TObject *Sender);
    void __fastcall del3Click(TObject *Sender);
    void __fastcall del4Click(TObject *Sender);
    void __fastcall del5Click(TObject *Sender);
    void __fastcall del6Click(TObject *Sender);
    void __fastcall addMyFav1Click(TObject *Sender);
    void __fastcall addMyFav2Click(TObject *Sender);
    void __fastcall addMyFav3Click(TObject *Sender);
    void __fastcall addMyFav4Click(TObject *Sender);
    void __fastcall addMyFav5Click(TObject *Sender);
    void __fastcall addMyFav6Click(TObject *Sender);
    void __fastcall btn_FigureClick(TObject *Sender);
    void __fastcall btn_DressTransClick(TObject *Sender);
private:	// User declarations

public:		// User declarations
    void playMusic(AnsiString pathName);
    void nextPlay(void);
    LrcHelper* musicLrc;
    __fastcall TForm1(TComponent* Owner);
    map<AnsiString,int> cntMusic;
    map<AnsiString,AnsiString> fileName2PathName;
    //deque<AnsiString> msHistory;
    void push_front(AnsiString);
    map<AnsiString,Song* > pathName2Song;
    map<AnsiString,SongList* > listName2SongList;
    int songListPage;
    vector<TLabel*> songListLabel;
    vector<TSpeedButton *> songListBtn;
    vector<bool> songListBtnFlag;
    vector<int> chosedMusic;
    AnsiString nowOpenListName;
    map<AnsiString,int> selectOn;
    bool alarmOn;
    double alarmEndTime;
    double alarmBeginTime;
    vector<TLabel* > lrcWord;
    int playMode;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
