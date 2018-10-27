#include "TXLib.h"
#include "lib\\Oblast.cpp"

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

void drawLevelButton(int x, int y, const char* text, COLORREF backColor, COLORREF frontColor);
void drawLevelButton(int x, int y, const char* text, COLORREF backColor, COLORREF frontColor)
{
    //x = 76, y = 115
    txSetColor(TX_BLACK);
    txSetFillColor(backColor);
    txRectangle(76 - 76 + x, 115 - 115 + y, 175 - 76 + x, 214 - 115 + y);

    txSetColor(frontColor);
    txSetFillColor(frontColor);
    txRectangle(101 - 76 + x, 110 - 115 + y, 151 - 76 + x, 219 - 115 + y);
    txRectangle(71 - 76 + x, 139 - 115 + y, 180 - 76 + x, 189 - 115 + y);

    txSetColor(TX_BLACK);
    txSelectFont("Bauhaus 93", 72);
    txTextOut(120 - 76 + x, 160 - 115 + y, text);
}


int main()
    {
    txCreateWindow (1280, 720);

    drawLevelButton(76, 115, "1", RGB(34, 177, 76), RGB(181, 230, 29));
    drawLevelButton(303, 127, "2", RGB(34, 177, 76), RGB(181, 230, 29));

    txSleep(100000);

    HDC main_menu = txLoadImage ("pictures\\main_menu.bmp");
    HDC proba = txLoadImage ("pictures\\proba.bmp");
    HDC vsecuby = txLoadImage ("pictures\\vsecuby.bmp");
    HDC kartaurovneya = txLoadImage ("kartaurovneya.bmp");
    HDC fonurovnya = txLoadImage ("fonurovnya.bmp");

    //Ñäåëàòü ìàññèâîì
    /*int KOLICH_KNOPOK = 5;
    Button btn[KOLICH_KNOPOK];
    btn[0] = {0, 100,   0,  90, TX_RED, "Êíîïêà 1"};
    btn[1] = {0, 100,  90, 180, TX_YELLOW, "Êíîïêà 2"};
    btn[2] = {0, 100, 180, 270, TX_BLUE, "Êíîïêà 3"};
    btn[3] = {0, 100, 270, 360, TX_YELLOW, "Êíîïêà 4"};
    btn[4] = {0, 100, 360, 450, TX_BLUE, "Êíîïêà 5"};*/

    int KOLVO_OBLASTEI = 40;
    Oblast obl[KOLVO_OBLASTEI];

    obl[0] =  {1};
    obl[1] =  {5};
    obl[2] =  {1};
    obl[3] =  {5};
    obl[4] =  {1};
    obl[5] =  {5};
    obl[6] =  {1};
    obl[7] =  {5};

    obl[8] =  {1};
    obl[9] =  {5};
    obl[10] = {1};
    obl[11] = {5};
    obl[12] = {1};
    obl[13] = {5};
    obl[14] = {1};
    obl[15] = {5};

    obl[16] = {1};
    obl[17] = {5};
    obl[18] = {1};
    obl[19] = {5};
    obl[20] = {1};
    obl[21] = {5};
    obl[22] = {1};
    obl[23] = {5};

    obl[24] = {1};
    obl[25] = {5};
    obl[26] = {1};
    obl[27] = {5};
    obl[28] = {1};
    obl[29] = {5};
    obl[30] = {1};
    obl[31] = {5};

    obl[32] = {1};
    obl[33] = {5};
    obl[34] = {1};
    obl[35] = {5};
    obl[36] = {1};
    obl[37] = {5};
    obl[38] = {1};
    obl[39] = {5};

    for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
    {
        //13%8 = 5, ïîòîìó ÷òî 13 = 8 * 1 + 5
        obl[nomer_oblasti].lx = get_min_x((nomer_oblasti % 8) + 1);
        obl[nomer_oblasti].rx = get_min_x((nomer_oblasti % 8) + 2);
        obl[nomer_oblasti].vy = get_min_y(nomer_oblasti / 8 + 1);
        obl[nomer_oblasti].ny = get_min_y(nomer_oblasti / 8 + 2);
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

        //Êàê ïðîéòè èãðó / âûéòè èç èãðû? Exit âåäü âñåãäà == false
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
                //Èùåì êîîðäèíàòó äëÿ ðèñîâàíèÿ íóæíîãî êàäðà
                int coord1 = coord(obl[nomer_oblasti]);

                //Ïðîâåðÿåì, ÷òî êàäð íå ñëèøêîì áîëüøîé
                if (clickOnOblkast(obl[nomer_oblasti]) == 1)
                {
                    obl[nomer_oblasti].poloj = obl[nomer_oblasti].poloj + 1;
                    if (obl[nomer_oblasti].poloj > obl[nomer_oblasti].max_poloj)
                    {
                        obl[nomer_oblasti].poloj = obl[nomer_oblasti].min_poloj;
                    }
                    //Íå ìåøàëî áû ñþäà ïàóçó äîáàâèòü. À òî î÷åíü òÿæåëî êëèêîì îòëîâèòü íóæíîå ïîëîæåíèå
                    pause = true;
                }

                txBitBlt (txDC(), obl[nomer_oblasti].lx, obl[nomer_oblasti].vy, obl[nomer_oblasti].rx - obl[nomer_oblasti].lx, obl[nomer_oblasti].ny - obl[nomer_oblasti].vy, vsecuby, coord1, 10);
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


            txSleep(100);
            txEnd();
        }
    }

    //Åùå ïàðó êàðòèíîê çàáûâàåøü óäàëèòü
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
