//---------------------------------------------------------------------------

#ifndef PlayListH
#define PlayListH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
    TListBox *playListBox;
    TPopupMenu *PopupMenu1;
    TMenuItem *play;
    TMenuItem *del;
    TMenuItem *favorite;
    void __fastcall playListBoxDblClick(TObject *Sender);
    void __fastcall playClick(TObject *Sender);
    void __fastcall delClick(TObject *Sender);
    void __fastcall favoriteClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
