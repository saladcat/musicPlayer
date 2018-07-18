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

#include "musicHelper.h"
#include "SongList.h"
#include "Song.h"
#include "LrcHelper.h"
#include <Dialogs.hpp>

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
        TButton *btn_MsList1;
        TButton *btn_MsList2;
        TButton *btn_MsList3;
        TButton *btn_Figure;
        TGroupBox *grp_Init_MsList;
        TButton *btn_CreMsList;
        TButton *btn_MsList01;
        TButton *btn_MsList02;
        TButton *btn_MsList03;
        TGroupBox *grp_ConWins;
        TRadioButton *rbtn_WinMin;
        TRadioButton *rbtn_WinMax;
        TRadioButton *rbtn_WinClose;
        TGroupBox *grp_PreMs;
        TGroupBox *grp_Search;
        TEdit *txt_Search;
        TButton *btn_Search;
        TButton *btn_DressTrans;
        TGroupBox *grp_MsCon;
        TButton *btn_Play;
        TButton *btn_Pause;
        TButton *btn_Next;
        TButton *btn_Pre;
        TGroupBox *grp_Playig;
        TProgressBar *ProgressBar1;
    TOpenDialog *diaLoadMs;
    TEdit *Edit1;
    void __fastcall btn_LoveMsClick(TObject *Sender);
private:	// User declarations
    map<AnsiString,int> cntMusic;
    map<AnsiString,AnsiString> fileName2PathName;

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
