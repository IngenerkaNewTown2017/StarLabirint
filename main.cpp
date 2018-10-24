#include "TXLib.h"
#include "lib\\oblast.cpp"

int uroven_tekushii = 1;
int uroven_staryi = 0;


int x_ball;
int y_ball;
int point_cuba;
int speed_ball = 35;
bool Exit = false;
bool StartGame = false;
bool Start_level = false;
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

void drawButton(Button btn1);
int KNOPKAClick (Button exitButton, int risovat);
int clickOnOblkast(Oblast obl1);

int get_max_poloj(int poloj);
int min_max_poloj(int poloj);

int main()
    {
    txCreateWindow (1280, 720);

    HDC main_menu = txLoadImage ("pictures\\main_menu.bmp");
    HDC proba = txLoadImage ("pictures\\proba.bmp");
    HDC vsecuby = txLoadImage ("pictures\\vsecuby.bmp");
    HDC kartaurovneya = txLoadImage ("kartaurovneya.bmp");
    HDC fonurovnya = txLoadImage ("fonurovnya.bmp");

    //Сделать массивом
    /*int KOLICH_KNOPOK = 5;
    Button btn[KOLICH_KNOPOK];
    btn[0] = {0, 100,   0,  90, TX_RED, "Кнопка 1"};
    btn[1] = {0, 100,  90, 180, TX_YELLOW, "Кнопка 2"};
    btn[2] = {0, 100, 180, 270, TX_BLUE, "Кнопка 3"};
    btn[3] = {0, 100, 270, 360, TX_YELLOW, "Кнопка 4"};
    btn[4] = {0, 100, 360, 450, TX_BLUE, "Кнопка 5"};*/

    int KOLVO_OBLASTEI = 40;
    Oblast obl[KOLVO_OBLASTEI];

    obl[0] =  {242,  342, 119, 219, 1};
    obl[1] =  {342,  442, 119, 219, 5};
    obl[2] =  {442,  542, 119, 219, 1};
    obl[3] =  {542,  642, 119, 219, 5};
    obl[4] =  {642,  742, 119, 219, 1};
    obl[5] =  {742,  842, 119, 219, 5};
    obl[6] =  {842,  942, 119, 219, 1};
    obl[7] =  {942, 1042, 119, 219, 5};

    obl[8] =  {242,  342, 219, 319, 1};
    obl[9] =  {342,  442, 219, 319, 5};
    obl[10] = {442,  542, 219, 319, 1};
    obl[11] = {542,  642, 219, 319, 5};
    obl[12] = {642,  742, 219, 319, 1};
    obl[13] = {742,  842, 219, 319, 5};
    obl[14] = {842,  942, 219, 319, 1};
    obl[15] = {942, 1042, 219, 319, 5};

    obl[16] = {242,  342, 319, 419, 1};
    obl[17] = {342,  442, 319, 419, 5};
    obl[18] = {442,  542, 319, 419, 1};
    obl[19] = {542,  642, 319, 419, 5};
    obl[20] = {642,  742, 319, 419, 1};
    obl[21] = {742,  842, 319, 419, 5};
    obl[22] = {842,  942, 319, 419, 1};
    obl[23] = {942, 1042, 319, 419, 5};

    obl[24] = {242,  342, 419, 519, 1};
    obl[25] = {342,  442, 419, 519, 5};
    obl[26] = {442,  542, 419, 519, 1};
    obl[27] = {542,  642, 419, 519, 5};
    obl[28] = {642,  742, 419, 519, 1};
    obl[29] = {742,  842, 419, 519, 5};
    obl[30] = {842,  942, 419, 519, 1};
    obl[31] = {942, 1042, 419, 519, 5};

    //Прикинь, теперь 6 и 7 цифры можно не писать
    //Но я хочу не писать и первые 4. Заметь, что они постоянно увеличиваются на 100
    //Попробуй для начала сделать функцию, у которой на вход номер ряда (5 в случае ниже),
    //а она автоматом выдаст минимальный и максимальный y. Можно 2 функции сделать
    obl[32] = {242,  342, 519, 619, 1};
    obl[33] = {342,  442, 519, 619, 5};
    obl[34] = {442,  542, 519, 619, 1};
    obl[35] = {542,  642, 519, 619, 5};
    obl[36] = {642,  742, 519, 619, 1};
    obl[37] = {742,  842, 519, 619, 5};
    obl[38] = {842,  942, 519, 619, 1};
    obl[39] = {942, 1042, 519, 619, 5};


    for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
    {
       obl[nomer_oblasti].max_poloj = get_max_poloj(obl[nomer_oblasti].poloj);
       obl[nomer_oblasti].min_poloj = min_max_poloj(obl[nomer_oblasti].poloj);
    }



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

        //Как пройти игру / выйти из игры? Exit ведь всегда == false
        while(Exit == false)
        {

            txBegin();
            txBitBlt (txDC(), 0, 0, 1280, 720, fonurovnya, 0, 0);

            /*for (int nomer_knopki = 0; nomer_knopki < KOLICH_KNOPOK; nomer_knopki++)
            {
                drawButton(btn[nomer_knopki]);
            }
*/
            bool pause = false;
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
                    //Не мешало бы сюда паузу добавить. А то очень тяжело кликом отловить нужное положение
                     pause = true;
                }

                txBitBlt (txDC(), obl[nomer_oblasti].lx, obl[nomer_oblasti].vy, obl[nomer_oblasti].rx - obl[nomer_oblasti].lx, obl[nomer_oblasti].ny - obl[nomer_oblasti].vy, vsecuby, coord1, 10);
            }

            {
                txSleep(100);
            }
/*


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
            risovatCub3 = KNOPKAClick(btn[2], risovatCub3);*/


            txSleep(10);
            txEnd();
        }
    }

    //Еще пару картинок забываешь удалить
    txDeleteDC(main_menu);
    txDeleteDC(proba);
    txDeleteDC(vsecuby);
    return 0;
}


int get_max_poloj(int poloj)
{
    int max_poloj = 0;
    if (poloj >= 1 and poloj <= 4)
    {
        max_poloj = 4;
    }
    else if (poloj >= 5 and poloj <=6)
    {
        max_poloj = 6;
    }

    return max_poloj;
}

int min_max_poloj(int poloj)
{
    int min_poloj = 0;
    if (poloj >= 1 and poloj <= 4)
    {
        min_poloj = 1;
    }
    else if (poloj >= 5 and poloj <=6)
    {
        min_poloj = 5;
    }

    return min_poloj;
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


