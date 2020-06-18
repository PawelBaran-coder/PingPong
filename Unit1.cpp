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

        int LP_points = 0;
        int RP_points = 0;

        AnsiString LPP, RPP, AB;

        int LP_ballNumber = 5;
        int RP_ballNumber = 5;
        //int all_balls =10;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        LPP = IntToStr(LP_points);
        RPP = IntToStr(RP_points);
        gameStatus -> Caption = LPP + " : " + RPP;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_ballTimer(TObject *Sender)
{
        ball -> Left += x;
        ball -> Top += y;

        //odbij od gornej sciany

        if (ball -> Top-5 <= tlo -> Top)   y = -y;

        //odbij od dolnej sciany

        if (ball -> Top + ball -> Height >= tlo -> Top + tlo -> Height) y = -y;

        // skucha lewego gracza

        if(ball -> Left + ball -> Width/2 < paddle_LP -> Left)
        {
                RP_points += 1;
                LP_ballNumber -= 1;
                //all_balls -= 1;
                //AB = IntToStr(all_balls);
                RPP = IntToStr(RP_points);
                gameStatus -> Caption = LPP + " : " + RPP;
                if (LP_ballNumber == 4)
                {
                        LP_ball5 -> Visible = false;
                }
                if (LP_ballNumber == 3)
                {
                        LP_ball4 -> Visible = false;
                }
                if (LP_ballNumber == 2)
                {
                        LP_ball3 -> Visible = false;
                }
                if (LP_ballNumber == 1)
                {
                        LP_ball2 -> Visible = false;
                }
                if (LP_ballNumber == 0)
                {
                        LP_ball1 -> Visible = false;
                        //Label1 ->  Caption = "GAME OVER";
                        //Label1 ->  Visible = true;
                }

                Timer_ball -> Enabled = false;
                ball -> Visible = false;
                Button1 -> Visible = true;
                Button1 -> Visible = true;
                Label1 ->  Caption = "Punkt dla prawicy!";
                Label1 ->  Visible = true;

        }

        //odbicie pilki od lewej paletki

        else if (ball -> Top > paddle_LP -> Top - ball -> Height/2 &&
                   ball -> Top < paddle_LP -> Top + paddle_LP -> Height &&
                   ball -> Left < paddle_LP -> Left + paddle_LP -> Width)
                   {
                        if (x < 0)
                        x = -x;
                   }

         // skucha prawego gracza
        if(ball -> Left + ball -> Width/2 > paddle_RP -> Left + paddle_RP -> Width)
        {
                LP_points += 1;
                RP_ballNumber -= 1;
                //all_balls -= 1;
                //AB = IntToStr(all_balls);
                LPP = IntToStr(LP_points);
                gameStatus -> Caption = LPP + " : " + RPP;

                if (RP_ballNumber == 4)
                {
                        RP_ball5 -> Visible = false;
                }
                if (RP_ballNumber == 3)
                {
                        RP_ball4 -> Visible = false;
                }
                if (RP_ballNumber == 2)
                {
                        RP_ball3 -> Visible = false;
                }
                if (RP_ballNumber == 1)
                {
                        RP_ball2 -> Visible = false;
                }
                if (RP_ballNumber == 0)
                {
                        RP_ball1 -> Visible = false;
                }


                Timer_ball -> Enabled = false;
                ball -> Visible = false;
                Button1 -> Visible = true;
                Label1 ->  Caption = "Punkt dla lewicy!";
                Label1 ->  Visible = true;


        //odbicie pilki od prawej paletki
        }  else if (ball -> Top > paddle_RP -> Top - ball -> Height/2 &&
                    ball -> Top < paddle_RP -> Top + paddle_RP -> Height &&
                    ball -> Left + ball -> Width > paddle_RP -> Left)
                   {
                        if (x > 0)
                        x = -x;
                   }
        if( LP_ballNumber ==0 || RP_ballNumber ==0)
        {
                Label1 ->  Caption = "GAME OVER";
                Label1 ->  Visible = true;
                Button1 -> Visible = false;
                Button2 -> Visible = true;
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


void __fastcall TForm1::gameStatusClick(TObject *Sender)
{

        LPP = IntToStr(LP_points);
        RPP = IntToStr(RP_points);
        gameStatus -> Caption = LPP + " : " + RPP;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        ball -> Left = 500;
        ball -> Top =300;

        ball -> Visible = true;
        x= -5;
        y= -5;
        Timer_ball -> Enabled = true;

        Button1 -> Visible = false;
        Label1 ->  Visible = false;
       
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
        ball -> Left = 500;
        ball -> Top =300;

        ball -> Visible = true;
        x= -5;
        y= -5;

        Button1 -> Visible = false;
        Button2 -> Visible = false;
        Label1 ->  Visible = false;

        LP_ballNumber = 5;
        RP_ballNumber = 5;
        Timer_ball -> Enabled = true;
        LP_points = 0;
        RP_points = 0;
        gameStatus -> Caption = "0 : 0";
        LP_ball1 -> Visible = true;
        LP_ball2 -> Visible = true;
        LP_ball3 -> Visible = true;
        LP_ball4 -> Visible = true;
        LP_ball5 -> Visible = true;
        RP_ball1 -> Visible = true;
        RP_ball2 -> Visible = true;
        RP_ball3 -> Visible = true;
        RP_ball4 -> Visible = true;
        RP_ball5 -> Visible = true;

}
//---------------------------------------------------------------------------

