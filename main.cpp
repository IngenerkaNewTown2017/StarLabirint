#include "TXLib.h"

int uroven_tekushii = 1;
int uroven_staryi = 0;


int x_ball;
int y_ball;
int point_cuba;
int speed_ball = 35;
bool Exit = false;
bool StartGame = false;
int risovatCub1 = 0;
int risovatCub2 = 0;
int risovatCub3 = 0;
int x_1 = 212;
int x_2 = 312;
int x_3 = 412;
int x_4 = 512;
int x_5 = 612;
int x_6 = 712;
int x_7 = 812;
int x_8 = 912;
int x_9 = 1012;

int y_1 = 119;
int y_2 = 219;
int y_3 = 319;
int y_4 = 419;
int y_5 = 519;
//int y_6 = 619;

struct Button
{
    int x1;
    int x2;
    int y1;
    int y2;
    COLORREF color;
    const char* text;
};

struct Oblast
{
    int lx;
    int rx;
    int vy;
    int ny;
    int poloj;
    int min_poloj;
    int max_poloj;
};

void drawButton(Button btn1);
int KNOPKAClick (Button exitButton, int risovat);
int clickOnOblkast(Oblast obl1);

int main()
    {
    txCreateWindow (1280, 720);

    HDC main_menu = txLoadImage ("pictures\\main_menu.bmp");
    HDC proba = txLoadImage ("pictures\\proba.bmp");
    HDC vsecuby = txLoadImage ("pictures\\vsecuby.bmp");
    HDC kartaurovneya = txLoadImage ("kartaurovneya.bmp");

    //������� ��������
    Oblast obl1 = {212, 312, 119, 219, 1, 1, 4};
    Oblast obl2 = {312, 412, 119, 219, 5, 5, 6};


    Button btn1 = {0, 100,  0, 30, TX_RED, "red11111111111111111111111"};
    Button btn2 = {0, 100, 30, 60, TX_YELLOW, "yellow111111111111111111111111"};
    Button btn3 = {0, 100, 60, 90, TX_BLUE, "blue1111111111111111111111111111"};

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

        txBitBlt (txDC(), 0, 0, 1280, 720, kartaurovneya, 0, 0);

        while(uroven_staryi < uroven_tekushii)
        {
            if(txMouseButtons () &1 &&
                txMouseX () >= 76 &&
                txMouseX () <= 175 &&
                txMouseY () >= 115 &&
                txMouseY () <= 214)
            {
                uroven_staryi = uroven_tekushii;
            }
            txSleep(10);
        }

        uroven_tekushii = uroven_tekushii + 1;

        while(Exit == false)
        {

            txBegin();
            txBitBlt (txDC(), 0, 0, 1280, 720, proba, 0, 0);

            drawButton(btn1);
            drawButton(btn2);
            drawButton(btn3);

//������� ��������
            int coord1 = 0;
            if (obl1.poloj == 1)
            {
                coord1 = 10;
            }
            else if (obl1.poloj == 2)
            {
                coord1 = 129;
            }
            else if (obl1.poloj == 3)
            {
                coord1 = 248;
            }
            else if (obl1.poloj == 4)
            {
                coord1 = 366;
            }
            txBitBlt (txDC(), obl1.lx, obl1.vy, obl1.rx - obl1.lx, obl1.ny - obl1.vy, vsecuby, coord1, 10);
            //txBitBlt (txDC(), 315, 0, 100, 100, vsecuby, coord1, 10);
            //�/����� ������� ��������
            if (clickOnOblkast(obl1) == 1)
            {
                obl1.poloj = obl1.poloj + 1;
                if (obl1.poloj > obl1.max_poloj)
                {
                    obl1.poloj = obl1.min_poloj;
                }
            }


            if (risovatCub1 == 1)
            {
                txBitBlt (txDC(), 315, 0, 100, 100, vsecuby, 248, 10);
                txBitBlt (txDC(), 515, 0, 100, 100, vsecuby, 366, 10);
                txBitBlt (txDC(), 515, 200, 100, 100, vsecuby, 129, 10);
                txBitBlt (txDC(), 315, 200, 100, 100, vsecuby, 10, 10);
            }

            if (risovatCub2 == 1)
            {
                txBitBlt (txDC(), 415, 0, 100, 100, vsecuby, 483, 10);
                txBitBlt (txDC(), 415, 200, 100, 100, vsecuby, 483, 10);
            }

            if (risovatCub3 == 1)
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

            risovatCub1 = KNOPKAClick(btn1, risovatCub1);
            risovatCub2 = KNOPKAClick(btn2, risovatCub2);
            risovatCub3 = KNOPKAClick(btn3, risovatCub3);


            txSleep(10);
            txEnd();
        }
    }

    txDeleteDC(main_menu);
    txDeleteDC(proba);
    txDeleteDC(vsecuby);
    return 0;
}



void move_ball_rigth()
{
for(x_ball=point_cuba; x_ball<=point_cuba; x_ball++)
{
  x_ball=x_ball+speed_ball;
}
}

void move_ball_left()
{
for(x_ball=point_cuba; x_ball<=point_cuba; x_ball++)
{
 x_ball=x_ball-speed_ball;
}
}

void move_ball_up()
{
for(y_ball=point_cuba; y_ball<=point_cuba; y_ball++)
{
 y_ball=y_ball+speed_ball;
}
}

void move_ball_down()
{
for(y_ball=point_cuba; y_ball<=point_cuba; y_ball++)
{
 y_ball=y_ball-speed_ball;
}
}

void drawButton(Button btn1)
{
    txSetFillColor(btn1.color);
    txRectangle   (btn1.x1, btn1.y1, btn1.x2, btn1.y2);
    txTextOut     (btn1.x1, btn1.y1, btn1.text);
}

int KNOPKAClick (Button exitButton, int risovat)
{
    if (txMouseX() > exitButton.x1  &&
        txMouseX() < exitButton.x2 &&
        txMouseY() > exitButton.y1  &&
        txMouseY() < exitButton.y2 &&
        txMouseButtons() & 1)
    {
        return 1;
    }

    return risovat;
}

int clickOnOblkast(Oblast obl1)
{
    if (txMouseButtons () == 1 &&
        txMouseX () >= obl1.lx &&
        txMouseX () <= obl1.rx &&
        txMouseY () >= obl1.vy &&
        txMouseY () <= obl1.ny)
     {
        return 1;
     }
     return 0;
}

void oblast_cubov_1()
{
 /* if(txMouseButtons () == 1 &&
     txMouseX () >= obl1.lx &&
     txMouseX () <= obl1.rx &&
     txMouseY () >= obl1.vy &&
     txMouseY () <= obl1.ny)
     {

     }     */

   if(txMouseButtons () == 1 &&
//      txMouseX () >= obl1.lx &&
      txMouseX () <= x_2 &&
      txMouseY () >= y_2 &&
      txMouseY () <= y_3)
      {

      }

      if(txMouseButtons () == 1 &&
      txMouseX () >= x_1 &&
      txMouseX () <= x_2 &&
      txMouseY () >= y_3 &&
      txMouseY () <= y_4)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_1 &&
      txMouseX () <= x_2 &&
      txMouseY () >= y_4 &&
      txMouseY () <= y_5)
      {

      }



}

void oblast_cubov_2()
{
   if(txMouseButtons () == 1 &&
     txMouseX () >= x_2 &&
     txMouseX () <= x_3 &&
     txMouseY () >= y_1 &&
     txMouseY () <= y_2)
     {

     }

   if(txMouseButtons () == 1 &&
      txMouseX () >= x_2 &&
      txMouseX () <= x_3 &&
      txMouseY () >= y_2 &&
      txMouseY () <= y_3)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_2 &&
      txMouseX () <= x_3 &&
      txMouseY () >= y_3 &&
      txMouseY () <= y_4)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_2 &&
      txMouseX () <= x_3 &&
      txMouseY () >= y_4 &&
      txMouseY () <= y_5)
      {

      }
}

void oblast_cubov_3()
{
   if(txMouseButtons () == 1 &&
     txMouseX () >= x_3 &&
     txMouseX () <= x_4 &&
     txMouseY () >= y_1 &&
     txMouseY () <= y_2)
     {

     }

   if(txMouseButtons () == 1 &&
      txMouseX () >= x_3 &&
      txMouseX () <= x_4 &&
      txMouseY () >= y_2 &&
      txMouseY () <= y_3)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_3 &&
      txMouseX () <= x_4 &&
      txMouseY () >= y_3 &&
      txMouseY () <= y_4)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_3 &&
      txMouseX () <= x_4 &&
      txMouseY () >= y_4 &&
      txMouseY () <= y_5)
      {

      }
}

void oblast_cubov_4()
{
   if(txMouseButtons () == 1 &&
     txMouseX () >= x_4 &&
     txMouseX () <= x_5 &&
     txMouseY () >= y_1 &&
     txMouseY () <= y_2)
     {

     }

   if(txMouseButtons () == 1 &&
      txMouseX () >= x_4 &&
      txMouseX () <= x_5 &&
      txMouseY () >= y_2 &&
      txMouseY () <= y_3)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_4 &&
      txMouseX () <= x_5 &&
      txMouseY () >= y_3 &&
      txMouseY () <= y_4)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_4 &&
      txMouseX () <= x_5 &&
      txMouseY () >= y_4 &&
      txMouseY () <= y_5)
      {

      }
}

void oblast_cubov_5()
{
   if(txMouseButtons () == 1 &&
     txMouseX () >= x_5 &&
     txMouseX () <= x_6 &&
     txMouseY () >= y_1 &&
     txMouseY () <= y_2)
     {

     }

   if(txMouseButtons () == 1 &&
      txMouseX () >= x_5 &&
      txMouseX () <= x_6 &&
      txMouseY () >= y_2 &&
      txMouseY () <= y_3)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_5 &&
      txMouseX () <= x_6 &&
      txMouseY () >= y_3 &&
      txMouseY () <= y_4)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_5 &&
      txMouseX () <= x_6 &&
      txMouseY () >= y_4 &&
      txMouseY () <= y_5)
      {

      }
}

void oblast_cubov_6()
{
   if(txMouseButtons () == 1 &&
     txMouseX () >= x_6 &&
     txMouseX () <= x_7 &&
     txMouseY () >= y_1 &&
     txMouseY () <= y_2)
     {

     }

   if(txMouseButtons () == 1 &&
      txMouseX () >= x_6 &&
      txMouseX () <= x_7 &&
      txMouseY () >= y_2 &&
      txMouseY () <= y_3)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_6 &&
      txMouseX () <= x_7 &&
      txMouseY () >= y_3 &&
      txMouseY () <= y_4)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_6 &&
      txMouseX () <= x_7 &&
      txMouseY () >= y_4 &&
      txMouseY () <= y_5)
      {

      }
}

void oblast_cubov_7()
{
   if(txMouseButtons () == 1 &&
     txMouseX () >= x_7 &&
     txMouseX () <= x_8 &&
     txMouseY () >= y_1 &&
     txMouseY () <= y_2)
     {

     }

   if(txMouseButtons () == 1 &&
      txMouseX () >= x_7 &&
      txMouseX () <= x_8 &&
      txMouseY () >= y_2 &&
      txMouseY () <= y_3)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_7 &&
      txMouseX () <= x_8 &&
      txMouseY () >= y_3 &&
      txMouseY () <= y_4)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_7 &&
      txMouseX () <= x_8 &&
      txMouseY () >= y_4 &&
      txMouseY () <= y_5)
      {

      }
}

void oblast_cubov_8()
{
   if(txMouseButtons () == 1 &&
     txMouseX () >= x_8 &&
     txMouseX () <= x_9 &&
     txMouseY () >= y_1 &&
     txMouseY () <= y_2)
     {

     }

   if(txMouseButtons () == 1 &&
      txMouseX () >= x_8 &&
      txMouseX () <= x_9 &&
      txMouseY () >= y_2 &&
      txMouseY () <= y_3)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_8 &&
      txMouseX () <= x_9 &&
      txMouseY () >= y_3 &&
      txMouseY () <= y_4)
      {

      }

    if(txMouseButtons () == 1 &&
      txMouseX () >= x_8 &&
      txMouseX () <= x_9 &&
      txMouseY () >= y_4 &&
      txMouseY () <= y_5)
      {

      }
}


