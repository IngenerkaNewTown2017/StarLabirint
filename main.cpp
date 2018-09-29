#include "TXLib.h"

int x_ball;
int y_ball;
int point_cuba;//èõ äîõèãà áóäåò    íå çàáóäü äàóí
int speed_ball = 35;
bool Exit = false;
bool StartGame = false;
bool risovatCub1 = false;
bool risovatCub2 = false;
bool risovatCub3 = false;
bool risovatCub4 = false;
bool risovatCub5 = false;
bool risovatCub6 = false;
bool risovatCub7 = false;
bool risovatCub8 = false;

int main()
    {
    txCreateWindow (1280, 720);

    HDC main_menu = txLoadImage ("main_menu.bmp");
    HDC proba = txLoadImage ("proba.bmp");
    HDC vsecuby = txLoadImage ("vsecuby.bmp");

    while(Exit == false && StartGame == false)
    {
        txBegin();
        txClear();
        txBitBlt (txDC(), 0, 0, 1280, 720, main_menu, 0, 0);

        if(txMouseButtons () == 1 &&
            txMouseX () >= 525 &&
            txMouseX () <= 689 &&
            txMouseY () >= 480 &&
            txMouseY () <= 580)
        {
            Exit = true;
        }
        if(txMouseButtons () == 1 &&
            txMouseX () >= 517 &&
            txMouseX () <= 704 &&
            txMouseY () >= 275 &&
            txMouseY () <= 368)
        {
            StartGame = true;
        }

        txSleep(10);
        txEnd();
    }

    if (StartGame == true)
    {
        while(Exit == false)
        {
            txBegin();
            txBitBlt (txDC(), 0, 0, 1280, 720, proba, 0, 0);

            txSetFillColor(TX_RED);
            txRectangle(0,0,100,30);
            txSetFillColor(TX_YELLOW);
            txRectangle(0,30,100,60);
            txSetFillColor(TX_BLUE);
            txRectangle(0,60,100,90);

            if (risovatCub1)
            {
                txBitBlt (txDC(), 315, 0, 100, 100, vsecuby, 248, 10);
                txBitBlt (txDC(), 515, 0, 100, 100, vsecuby, 366, 10);
                txBitBlt (txDC(), 515, 200, 100, 100, vsecuby, 129, 10);
                txBitBlt (txDC(), 315, 200, 100, 100, vsecuby, 10, 10);
            }

            if (risovatCub2)
            {
                txBitBlt (txDC(), 415, 0, 100, 100, vsecuby, 483, 10);
                txBitBlt (txDC(), 415, 200, 100, 100, vsecuby, 483, 10);
            }

            if (risovatCub3)
            {
                txBitBlt (txDC(), 315, 100, 100, 100, vsecuby, 602, 10);
                txBitBlt (txDC(), 515, 100, 100, 100, vsecuby, 602, 10);
            }




            if(txMouseButtons () == 1 &&
                txMouseX () >= 525 &&
                txMouseX () <= 689 &&
                txMouseY () >= 480 &&
                txMouseY () <= 580)
            {
                txBitBlt (txDC(), 400, 400, 1280, 720, proba, 0, 0);
            }

            if(txMouseButtons () == 1 &&
                txMouseX () >= 0 &&
                txMouseX () <= 100 &&
                txMouseY () >= 0 &&
                txMouseY () <= 30)
            {
                risovatCub1 = true;
            }

            if(txMouseButtons () == 1 &&
                txMouseX () >= 0 &&
                txMouseX () <= 100 &&
                txMouseY () >= 30 &&
                txMouseY () <= 60)
            {
                risovatCub2 = true;
            }

            if(txMouseButtons () == 1 &&
                txMouseX () >= 0 &&
                txMouseX () <= 100 &&
                txMouseY () >= 60 &&
                txMouseY () <= 90)
            {
                risovatCub3 = true;
            }

            txSleep(10);
            txEnd();
        }
    }

    txDeleteDC (main_menu);
    txDeleteDC (proba);
    txDeleteDC (vsecuby);
    return 0;
}


void move_ball_rigth()
{
/*ýòî äâèæåíèå øàðà âïðàâî */for(x_ball=point_cuba; x_ball<=/*äðóãîé*/point_cuba; x_ball++)
{
  x_ball=x_ball+speed_ball;
}
}

void move_ball_left()
{
/*ýòî äâèæåíèå øàðà âëåâî */for(x_ball=point_cuba; x_ball<=/*äðóãîé*/point_cuba; x_ball++)
{
 x_ball=x_ball-speed_ball;
}
}

void move_ball_up()
{
/*ýòî äâèæåíèå øàðà ââåðõ */for(y_ball=point_cuba; y_ball<=/*äðóãîé*/point_cuba; y_ball++)
{
 y_ball=y_ball+speed_ball;
}
}

void move_ball_down()
{
/*ýòî äâèæåíèå øàðà âíèç */for(y_ball=point_cuba; y_ball<=/*äðóãîé*/point_cuba; y_ball++)
{
 y_ball=y_ball-speed_ball;
}
}