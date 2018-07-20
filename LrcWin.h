//---------------------------------------------------------------------------

#ifndef LrcWinH
#define LrcWinH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
    TMemo *lrcList;
    TSpeedButton *btn_backForm;
    TGroupBox *GroupBox1;
    TSpeedButton *btn_label;
    TSpeedButton *btn_addMyFa;
    TSpeedButton *btn_mood;
    TSpeedButton *btn_alarm;
    TSpeedButton *SpeedButton5;
    TSpeedButton *btn_highLight;
    TButton *btn_Figure;
    TButton *btn_DressTrans;
    TGroupBox *grp_ConWins;
    TRadioButton *rbtn_WinMin;
    TRadioButton *rbtn_WinClose;
    TGroupBox *grp_Playig;
    TLabel *playingSongName;
    TSpeedButton *btn_openPlayList;
    TSpeedButton *btn_openLrc;
    TImage *processBarbar;
    TProgressBar *ProgressBar1;
    TGroupBox *grp_MsCon;
    TImage *volumeBar;
    TLabel *Label1;
    TButton *btn_Play;
    TButton *btn_Next;
    TButton *btn_Pre;
    TTrackBar *TrackBar;
    TEdit *Edit1;
    TImage *Image1;
    TLabel *txt_SongName;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    void __fastcall btn_backFormClick(TObject *Sender);
    void __fastcall btn_addMyFaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
