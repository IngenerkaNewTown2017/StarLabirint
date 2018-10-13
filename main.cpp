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
int coord(Oblast obl1);

int main()
    {
    txCreateWindow (1280, 720);

    HDC main_menu = txLoadImage ("pictures\\main_menu.bmp");
    HDC proba = txLoadImage ("pictures\\proba.bmp");
    HDC vsecuby = txLoadImage ("pictures\\vsecuby.bmp");
    HDC kartaurovneya = txLoadImage ("kartaurovneya.bmp");

    //Сделать массивом
    int KOLICH_KNOPOK = 5;
    Button btn[KOLICH_KNOPOK];
    btn[0] = {0, 100,   0,  90, TX_RED, "Кнопка 1"};
    btn[1] = {0, 100,  90, 180, TX_YELLOW, "Кнопка 2"};
    btn[2] = {0, 100, 180, 270, TX_BLUE, "Кнопка 3"};
    btn[3] = {0, 100, 270, 360, TX_YELLOW, "Кнопка 4"};
    btn[4] = {0, 100, 360, 450, TX_BLUE, "Кнопка 5"};

    int KOLVO_OBLASTEI = 8;
    Oblast obl[KOLVO_OBLASTEI];
    /*1*/obl[0] = {212, 312, 119, 219, 1, 1, 4};
    /*1*/obl[1] = {312, 412, 119, 219, 5, 5, 6};
    /*1*/obl[2] = {412, 512, 119, 219, 1, 1, 4};
    /*1*/obl[3] = {512, 612, 119, 219, 5, 5, 6};
    /*1*/obl[4] = {612, 712, 119, 219, 1, 1, 4};
    /*1*/obl[5] = {712, 812, 119, 219, 5, 5, 6};
    /*1*/obl[6] = {812, 912, 119, 219, 1, 1, 4};
    /*1*/obl[7] = {912, 1012, 119, 219, 5, 5, 6};

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

            for (int nomer_knopki = 0; nomer_knopki < KOLICH_KNOPOK; nomer_knopki++)
            {
                drawButton(btn[nomer_knopki]);
            }

            for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
            {
                //Ищем координату для рисования нужного кадра
                int coord1 = coord(obl[nomer_oblasti]);

                //Проверяем, что кадр не слишком большой
                if (clickOnOblkast(obl[nomer_oblasti]) == 1)
                {
                    obl[nomer_oblasti].poloj = obl[nomer_oblasti].poloj + 1;
                    if (obl[nomer_oblasti].poloj > obl[nomer_oblasti].max_poloj)
                    {
                        obl[nomer_oblasti].poloj = obl[nomer_oblasti].min_poloj;
                    }
                }

                txBitBlt (txDC(), obl[nomer_oblasti].lx, obl[nomer_oblasti].vy, obl[nomer_oblasti].rx - obl[nomer_oblasti].lx, obl[nomer_oblasti].ny - obl[nomer_oblasti].vy, vsecuby, coord1, 10);
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

            risovatCub1 = KNOPKAClick(btn[0], risovatCub1);
            risovatCub2 = KNOPKAClick(btn[1], risovatCub2);
            risovatCub3 = KNOPKAClick(btn[2], risovatCub3);


            txSleep(10);
            txEnd();
        }
    }

    txDeleteDC(main_menu);
    txDeleteDC(proba);
    txDeleteDC(vsecuby);
    return 0;
}


int coord(Oblast obl1)
{
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
    else if (obl1.poloj == 5)
    {
        coord1 = 483;
    }
    else if (obl1.poloj == 6)
    {
        coord1 = 602;
    }

    return coord1;
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
    txSetFillColor(RGB(0, 0, 255));
    txRectangle   (btn1.x1, btn1.y1, btn1.x2, btn1.y2);
    txSetFillColor(RGB(0,0,0));
    txRectangle   (btn1.x1+5, btn1.y1+5, btn1.x2-5, btn1.y2-5);
    txDrawText    (btn1.x1, btn1.y1, btn1.x2, btn1.y2, btn1.text);
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


