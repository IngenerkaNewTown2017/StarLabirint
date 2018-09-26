
#include "TXLib.h"

int x_ball;
int y_ball;
int point_cuba;//их дохига будет    не забудь даун
int speed_ball = 35;
bool Exit = false;
bool StartGame = false;

int main()
    {
    txCreateWindow (1280, 720);

    HDC main_menu = txLoadImage ("main_menu.bmp");
    HDC proba = txLoadImage ("proba.bmp");


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



            if(txMouseButtons () == 1 &&
                txMouseX () >= 525 &&
                txMouseX () <= 689 &&
                txMouseY () >= 480 &&
                txMouseY () <= 580)
            {
                txBitBlt (txDC(), 400, 400, 1280, 720, proba, 0, 0);
            }
            txSleep(10);
            txEnd();
        }
    }

    txDeleteDC (main_menu);
    txDeleteDC (proba);
    return 0;
}


void move_ball_rigth()
{
/*это движение шара вправо */for(x_ball=point_cuba; x_ball<=/*другой*/point_cuba; x_ball++)
{
  x_ball=x_ball+speed_ball;
}
}

void move_ball_left()
{
/*это движение шара влево */for(x_ball=point_cuba; x_ball<=/*другой*/point_cuba; x_ball++)
{
 x_ball=x_ball-speed_ball;
}
}

void move_ball_up()
{
/*это движение шара вверх */for(y_ball=point_cuba; y_ball<=/*другой*/point_cuba; y_ball++)
{
 y_ball=y_ball+speed_ball;
}
}

void move_ball_down()
{
/*это движение шара вниз */for(y_ball=point_cuba; y_ball<=/*другой*/point_cuba; y_ball++)
{
 y_ball=y_ball-speed_ball;
}
}








