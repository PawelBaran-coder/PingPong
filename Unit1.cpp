//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
        int x= -3;
        int y= -3;

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

        // skucha lewego gracza

        if(ball -> Left + ball -> Width < paddle_LP -> Left)
        {
           Timer_ball -> Enabled = false;
           ball -> Visible = false;
        //odbicie pilki od lewej paletki
        } else if (ball -> Top > paddle_LP -> Top - ball -> Height/2 &&
                   ball -> Top < paddle_LP -> Top + paddle_LP -> Height &&
                   ball -> Left < paddle_LP -> Left + paddle_LP -> Width)
                   {
                        if (x < 0)
                        x = -x;
                   }

         // skucha prawego gracza
        if(ball -> Left + ball -> Width + 5 >= tlo -> Width)
        {
           Timer_ball -> Enabled = false;
           ball -> Visible = false;
        //odbicie pilki od prawej paletki
        }  else if (ball -> Top > paddle_RP -> Top - ball -> Height/2 &&
                    ball -> Top < paddle_RP -> Top + paddle_RP -> Height &&
                    ball -> Left + ball -> Width > paddle_RP -> Left)
                   {
                        if (x > 0)
                        x = -x;
                   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_up1Timer(TObject *Sender)
{
     if(paddle_LP -> Top >10) paddle_LP -> Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_down1Timer(TObject *Sender)
{
       if(paddle_LP -> Top + paddle_LP -> Height < tlo -> Height - 10)
       paddle_LP -> Top += 10;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
       if(Key == 65) Timer_up1 -> Enabled = true;
       if(Key == 90) Timer_down1 -> Enabled = true;
       if(Key == VK_UP) Timer_up2 -> Enabled = true;
       if(Key == VK_DOWN) Timer_down2 -> Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
       if(Key == 65) Timer_up1 -> Enabled = false;
       if(Key == 90) Timer_down1 -> Enabled = false;
       if(Key == VK_UP) Timer_up2 -> Enabled = false;
       if(Key == VK_DOWN) Timer_down2 -> Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer_up2Timer(TObject *Sender)
{
        if(paddle_RP -> Top >10) paddle_RP -> Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_down2Timer(TObject *Sender)
{
       if(paddle_RP -> Top + paddle_RP -> Height < tlo -> Height - 10)
       paddle_RP -> Top += 10;
}
//---------------------------------------------------------------------------

