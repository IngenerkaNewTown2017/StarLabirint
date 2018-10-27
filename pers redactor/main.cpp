#include "TXLib.h"
#include <iostream>
#include <string>
#include <fstream>
#include "lib\\Oblast.cpp"
#include "lib\\Buttons.cpp"

int uroven_tekushii = 1;
int uroven_staryi = 0;


int x_ball;
int y_ball;
int point_cuba;
int speed_ball = 35;
bool Exit = false;
bool StartGame = false;
bool Start_level = false;


using namespace std;

int main()
    {
    txCreateWindow (1280, 720);

    HDC main_menu =     txLoadImage ("pictures\\Labirint\\main_menu.bmp");
    HDC proba =         txLoadImage ("pictures\\Labirint\\proba.bmp");
    HDC vsecuby =       txLoadImage ("pictures\\Labirint\\vsecuby.bmp");
    HDC kartaurovneya = txLoadImage ("pictures\\Labirint\\kartaurovneya.bmp");
    HDC fonurovnya =    txLoadImage ("pictures\\Labirint\\fonurovnya.bmp");

    int KOLVO_OBLASTEI = 40;
    Oblast obl[KOLVO_OBLASTEI];

    ifstream file ("levels\\1.txt");

    string poloj;
    int nomer_obl = 0;
    while(getline(file, poloj) )//���� � �� ����� �� ����� �����
    {
        obl[nomer_obl] = {atoi(poloj.c_str())};//����������� ������ � �����
        nomer_obl = nomer_obl + 1;
    }

    file.close();


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
                }

                txBitBlt (txDC(), obl[nomer_oblasti].lx, obl[nomer_oblasti].vy, obl[nomer_oblasti].rx - obl[nomer_oblasti].lx, obl[nomer_oblasti].ny - obl[nomer_oblasti].vy, vsecuby, coord1, 10);
            }

            txSleep(10);
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
