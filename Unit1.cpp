//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
        int x= +8;
        int y= +8;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_ballTimer(TObject *Sender)
{
        ball -> Left += x;
        ball -> Top += y;

        //odbij od gornej sciany

        if (ball -> Top-5 <= tlo -> Top) y = -y;

        //odbij od dolnej sciany

        if (ball -> Top + ball -> Height >= tlo -> Top + tlo -> Height) y = -y;
}
//---------------------------------------------------------------------------