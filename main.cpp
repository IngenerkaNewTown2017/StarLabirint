#include "TXLib.h"
#include <iostream>
#include <string>
#include <fstream>
#include "lib\\Oblast.cpp"
#include "lib\\Buttons.cpp"
#include "lib\\shar.cpp"


struct OblUr
{
    int x;
    int x1;
    int y;
    int y1;
    const char* adress;
};

int uroven_tekushii = 1;
int uroven_staryi = 0;


int x_ball;
int y_ball;
int point_cuba;
int speed_ball = 5;
bool Exit = false;
bool StartGame = false;
bool Start_level = false;


using namespace std;

void drawLevelButton(int x, int y, const char* text, COLORREF backColor, COLORREF frontColor);
void drawLevelButton(int x, int y, const char* text, COLORREF backColor, COLORREF frontColor)
{
    //x = 76, y = 115
    txSetColor(TX_BLACK);
    txSetFillColor(backColor);
    txRectangle(x,      y,      x +  99, y +  99);

    txSetColor(frontColor);
    txSetFillColor(frontColor);
    txRectangle(x + 25, y -  5, x +  75, y + 104);
    txRectangle(x -  5, y + 24, x + 104, y +  84);

    txSetColor(TX_BLACK);
    txSelectFont("Bauhaus 93", 36);
    txTextOut  (x + 34, y + 15, text);
}


int main()
    {
    txCreateWindow (1280, 720);

    drawLevelButton(76, 115, "1", RGB(34, 177, 76), RGB(181, 230, 29));
    drawLevelButton(303, 127, "2", RGB(34, 177, 76), RGB(181, 230, 29));

    txSleep(2000);

    HDC spraitzagruzki =      txLoadImage ("spraitzagruzki.bmp");
    HDC zagruzka =      txLoadImage ("pictures\\Labirint\\zagrulka.bmp");
    HDC main_menu =     txLoadImage ("pictures\\Labirint\\main_menu.bmp");
    HDC proba =         txLoadImage ("pictures\\Labirint\\proba.bmp");
    HDC vsecuby =       txLoadImage ("pictures\\Labirint\\vsecuby.bmp");
    HDC kartaurovneya = txLoadImage ("pictures\\Labirint\\kartaurovneya.bmp");
    HDC fonurovnya =    txLoadImage ("pictures\\Labirint\\fonurovnya.bmp");

    int KOLVO_OBLASTEI = 40;
    Oblast obl[KOLVO_OBLASTEI];
    string file_adress = "";



    OblUr Lev1 = {76, 175, 115, 215, "levels\\1.txt"};
    OblUr Lev2 = {301, 401, 125, 225, "levels\\2.txt"};
    OblUr Lev3 = {191, 291, 392, 492, "levels\\3.txt"};
    OblUr Lev4 = {506, 606, 151, 251, "levels\\4.txt"};
    OblUr Lev5 = {1153, 1253, 15, 115, "levels\\5.txt"};
    OblUr Lev6 = {247, 347, 569, 669, "levels\\6.txt"};
    OblUr Lev7 = {1145, 1245, 240, 340, "levels\\7.txt"};
    OblUr Lev8 = {503, 603, 591, 691, "levels\\8.txt"};
    OblUr Lev9 = {1039, 1139, 438, 538, "levels\\9.txt"};



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

        if (checkClick(517, 705, 274, 370))
        {


            StartGame = true;
        }

        txSleep(10);
        txEnd();
    }

    if (StartGame == true)
    {
        txBitBlt (txDC(), 0, 0, 1280, 720, kartaurovneya, 0, 0);

        while(Start_level == false)
        {
            if(checkClick(Lev1.x, Lev1.x1, Lev1.y, Lev1.y1))
            {

                txBitBlt (txDC(), 0, 0, 1280, 720, zagruzka, 0, 0);
                 txSleep(5000);

                Start_level = true;
                file_adress = Lev1.adress;
            }

            else if(checkClick(Lev2.x, Lev2.x1, Lev2.y, Lev2.y1))
            {
                Start_level = true;
                file_adress = Lev2.adress;
            }

             else if(checkClick(Lev3.x, Lev3.x1, Lev3.y, Lev3.y1))
            {
                Start_level = true;
                file_adress = Lev3.adress;
            }

             else if(checkClick(Lev4.x, Lev4.x1, Lev4.y, Lev4.y1))
            {
                Start_level = true;
                file_adress = Lev4.adress;
            }

             else if(checkClick(Lev5.x, Lev5.x1, Lev5.y, Lev5.y1))
            {
                Start_level = true;
                file_adress = Lev5.adress;
            }

             else if(checkClick(Lev6.x, Lev6.x1, Lev6.y, Lev6.y1))
            {
                Start_level = true;
                file_adress = Lev6.adress;
            }

             else if(checkClick(Lev7.x, Lev7.x1, Lev7.y, Lev7.y1))
            {
                Start_level = true;
                file_adress = Lev7.adress;
            }

             else if(checkClick(Lev8.x, Lev8.x1, Lev8.y, Lev8.y1))
            {
                Start_level = true;
                file_adress = Lev8.adress;
            }

             else if(checkClick(Lev9.x, Lev9.x1, Lev9.y, Lev9.y1))
            {
                Start_level = true;
                file_adress = Lev9.adress;
            }







            txSleep(10);
        }


        ifstream file (file_adress);

        string poloj;
        int nomer_obl = 0;
        while(getline(file, poloj) )//���� � �� ����� �� ����� �����
        {
            obl[nomer_obl] = {atoi(poloj.c_str())};//����������� ������ � �����
            obl[nomer_obl].nomber_obl = nomer_obl;
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


        for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
        {
            int nomer_stolbca = (nomer_oblasti % 8) + 1;
            int nomer_stroki = (nomer_oblasti / 8) + 1;

            get_min_x(nomer_stolbca + 1);
            get_min_y(nomer_stroki);



            get_min_x(nomer_stolbca - 1);
            get_min_y(nomer_stroki);


            get_min_x(nomer_stolbca);
            get_min_y(nomer_stroki + 1);

            get_min_x(nomer_stolbca);
            get_min_y(nomer_stroki - 1);
        }
        /*if (proverit_chto_mozhno_idti_suda(obl,   KOLVO_OBLASTEI,
           obl[1].lx  ,obl[1].vy ,obl[2].lx  ,obl[2].vy) )
        {
            txTextOut(100, 100, "�����"   );
            txSleep(1000);

       }
        else
        {
            txTextOut(100, 100, "�� �����"   );
            txSleep(1000);

        } */




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

/*
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
*/
