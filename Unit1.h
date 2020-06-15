//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TImage *ball;
        TTimer *Timer_ball;
        TImage *paddle_LP;
        TTimer *Timer_up1;
        TTimer *Timer_down1;
        TImage *paddle_RP;
        TTimer *Timer_up2;
        TTimer *Timer_down2;
        TLabel *gameStatus;
        TShape *LP_balls;
        TShape *RP_balls;
        void __fastcall Timer_ballTimer(TObject *Sender);
        void __fastcall Timer_up1Timer(TObject *Sender);
        void __fastcall Timer_down1Timer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Timer_up2Timer(TObject *Sender);
        void __fastcall Timer_down2Timer(TObject *Sender);
        void __fastcall gameStatusClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
