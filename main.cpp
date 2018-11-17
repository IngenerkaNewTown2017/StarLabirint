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

int frame = 0;
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
    txRectangle(x -  5, y + 24, x + 105, y +  76);

    txSetColor(TX_BLACK);
    txSelectFont("Bauhaus 93", 36);
    txTextOut  (x + 34, y + 15, text);


}



int main()
    {
    txCreateWindow (1280, 720);

    txSetColor(TX_YELLOW, 6);
    //+50 - ��� ������
    txLine( 76 + 50, 115 + 50, 303 + 50, 127 + 50);
    txLine(303 + 50, 127 + 50, 191 + 50, 392 + 50);

    drawLevelButton(76, 115, "1", RGB(34, 177, 76), RGB(181, 230, 29));
    drawLevelButton(303, 127, "2", RGB(34, 177, 76), RGB(181, 230, 29));
    drawLevelButton(191, 392, "3", RGB(34, 177, 76), RGB(181, 230, 29));
    drawLevelButton(508, 151, "4", RGB(255, 127, 39), RGB(255, 201, 14));
    drawLevelButton(1153, 16, "5", RGB(255, 127, 39), RGB(255, 201, 14));
    drawLevelButton(246, 569, "6", RGB(255, 127, 39), RGB(255, 201, 14));
    drawLevelButton(1146, 241, "7", RGB(237, 28, 36), RGB(255, 201, 14));
    drawLevelButton(530, 590, "8", RGB(237, 28, 36), RGB(255, 201, 14));
	drawLevelButton(1039, 438, "9", RGB(237, 28, 36), RGB(255, 201, 14));


	txSleep(20000);

    HDC spraittzagruzki = txLoadImage ("pictures\\Labirint\\spraitzagruzki.bmp");
    HDC zagruzka =       txLoadImage ("pictures\\Labirint\\zagrulka.bmp");
    HDC main_menu =      txLoadImage ("pictures\\Labirint\\main_menu.bmp");
    HDC vsecuby =        txLoadImage ("pictures\\Labirint\\vsecuby.bmp");
    HDC kartaurovneya =  txLoadImage ("pictures\\Labirint\\kartaurovneya.bmp");
    HDC fonurovnya =     txLoadImage ("pictures\\Labirint\\fonurovnya.bmp");
    HDC spraitshara =    txLoadImage ("pictures\\Labirint\\spraitshara.bmp");

    int KOLVO_OBLASTEI = 40;
    Oblast obl[KOLVO_OBLASTEI];
    string file_adress = "";



    OblUr Lev[9];
    Lev[0] = {76, 175, 115, 215, "levels\\1.txt"};
    Lev[1] = {301, 401, 125, 225, "levels\\2.txt"};
    Lev[2] = {191, 291, 392, 492, "levels\\3.txt"};
    Lev[3] = {506, 606, 151, 251, "levels\\4.txt"};
    Lev[4] = {1153, 1253, 15, 115, "levels\\5.txt"};
    Lev[5] = {247, 347, 569, 669, "levels\\6.txt"};
    Lev[6] = {1145, 1245, 240, 340, "levels\\7.txt"};
    Lev[7] = {503, 603, 591, 691, "levels\\8.txt"};
    Lev[8] = {1039, 1139, 438, 538, "levels\\9.txt"};



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
            //What about for???

            if(checkClick(Lev[0].x, Lev[0].x1, Lev[0].y, Lev[0].y1))
            {
                Start_level = true;
                file_adress = Lev[0].adress;
            }

            else if(checkClick(Lev[1].x, Lev[1].x1, Lev[1].y, Lev[1].y1))
            {
                Start_level = true;
                file_adress = Lev[1].adress;
            }

            else if(checkClick(Lev[2].x, Lev[2].x1, Lev[2].y, Lev[2].y1))
            {
                Start_level = true;
                file_adress = Lev[2].adress;
            }

            else if(checkClick(Lev[3].x, Lev[3].x1, Lev[3].y, Lev[3].y1))
            {
                Start_level = true;
                file_adress = Lev[3].adress;
            }

            else if(checkClick(Lev[4].x, Lev[4].x1, Lev[4].y, Lev[4].y1))
            {
                Start_level = true;
                file_adress = Lev[4].adress;
            }

            else if(checkClick(Lev[5].x, Lev[5].x1, Lev[5].y, Lev[5].y1))
            {
                Start_level = true;
                file_adress = Lev[5].adress;
            }

            else if(checkClick(Lev[6].x, Lev[6].x1, Lev[6].y, Lev[6].y1))
            {
                Start_level = true;
                file_adress = Lev[6].adress;
            }

             else if(checkClick(Lev[7].x, Lev[7].x1, Lev[7].y, Lev[7].y1))
            {
                Start_level = true;
                file_adress = Lev[7].adress;
            }

             else if(checkClick(Lev[8].x, Lev[8].x1, Lev[8].y, Lev[8].y1))
            {
                Start_level = true;
                file_adress = Lev[8].adress;
            }

            txSleep(10);
        }


        while(frame < 40)
        {
            txBitBlt (txDC(), 0, 0, 1280, 720, zagruzka, 0, 0);
            //txBitBlt (txDC(), 1100, 530, 90, 90, spraitzagruzki, 90 * (frame % 4), 0);
            txSleep(100);
            frame = frame + 1;
        }


        ifstream file (file_adress);

        string poloj;
        int nomer_obl = 0;
        while(getline(file, poloj) )//ïîêà ÿ íå äîøåë äî êîíöà ôàéëà
        {
            obl[nomer_obl] = {atoi(poloj.c_str())};//êîíâåðòàöèÿ ñòðîêè â ÷èñëî
            obl[nomer_obl].nomber_obl = nomer_obl;
            nomer_obl = nomer_obl + 1;
        }

        file.close();


        for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
        {
            //13%8 = 5, Ã¯Ã®Ã²Ã®Ã¬Ã³ Ã·Ã²Ã® 13 = 8 * 1 + 5
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

            /*get_min_x(nomer_stolbca + 1);
            get_min_y(nomer_stroki);



            get_min_x(nomer_stolbca - 1);
            get_min_y(nomer_stroki);


            get_min_x(nomer_stolbca);
            get_min_y(nomer_stroki + 1);

            get_min_x(nomer_stolbca);
            get_min_y(nomer_stroki - 1);    */
        }

       /* if (proverit_chto_mozhno_idti_suda(obl,   KOLVO_OBLASTEI,
           obl[16].lx  ,obl[16].vy ,obl[8].lx  ,obl[8].vy) )
        {
            txTextOut(100, 100, "Mozhno");
            txSleep(1000);
       }
        else
        {
            txTextOut(100, 100, "Ne mozhno");
            txSleep(1000);
        }*/



        //ÃŠÃ Ãª Ã¯Ã°Ã®Ã©Ã²Ã¨ Ã¨Ã£Ã°Ã³ / Ã¢Ã»Ã©Ã²Ã¨ Ã¨Ã§ Ã¨Ã£Ã°Ã»? Exit Ã¢Ã¥Ã¤Ã¼ Ã¢Ã±Ã¥Ã£Ã¤Ã  == false
        while(Exit == false)
        {

            txBegin();
            txBitBlt (txDC(), 0, 0, 1280, 720, fonurovnya, 0, 0);
            txTransparentBlt(txDC(), 30, 330, 50, 50, spraitshara, 0, 0, TX_WHITE);


            for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
            {
                //ÃˆÃ¹Ã¥Ã¬ ÃªÃ®Ã®Ã°Ã¤Ã¨Ã­Ã Ã²Ã³ Ã¤Ã«Ã¿ Ã°Ã¨Ã±Ã®Ã¢Ã Ã­Ã¨Ã¿ Ã­Ã³Ã¦Ã­Ã®Ã£Ã® ÃªÃ Ã¤Ã°Ã 
                int coord1 = coord(obl[nomer_oblasti]);

                //ÃÃ°Ã®Ã¢Ã¥Ã°Ã¿Ã¥Ã¬, Ã·Ã²Ã® ÃªÃ Ã¤Ã° Ã­Ã¥ Ã±Ã«Ã¨Ã¸ÃªÃ®Ã¬ Ã¡Ã®Ã«Ã¼Ã¸Ã®Ã©
                if (clickOnOblkast(obl[nomer_oblasti]) == 1)
                {
                    obl[nomer_oblasti].poloj = obl[nomer_oblasti].poloj + 1;
                    if (obl[nomer_oblasti].poloj > obl[nomer_oblasti].max_poloj)
                    {
                        obl[nomer_oblasti].poloj = obl[nomer_oblasti].min_poloj;
                    }
                    //ÃÃ¥ Ã¬Ã¥Ã¸Ã Ã«Ã® Ã¡Ã» Ã±Ã¾Ã¤Ã  Ã¯Ã Ã³Ã§Ã³ Ã¤Ã®Ã¡Ã Ã¢Ã¨Ã²Ã¼. Ã€ Ã²Ã® Ã®Ã·Ã¥Ã­Ã¼ Ã²Ã¿Ã¦Ã¥Ã«Ã® ÃªÃ«Ã¨ÃªÃ®Ã¬ Ã®Ã²Ã«Ã®Ã¢Ã¨Ã²Ã¼ Ã­Ã³Ã¦Ã­Ã®Ã¥ Ã¯Ã®Ã«Ã®Ã¦Ã¥Ã­Ã¨Ã¥
                }

                txBitBlt (txDC(), obl[nomer_oblasti].lx, obl[nomer_oblasti].vy, obl[nomer_oblasti].rx - obl[nomer_oblasti].lx, obl[nomer_oblasti].ny - obl[nomer_oblasti].vy, vsecuby, coord1, 10);
            }

            if(txMouseButtons () == 1 &&
            txMouseX () <= 97 &&
            txMouseX () >= 23 &&
            txMouseY () >= 572 &&
            txMouseY () <= 645)
            {

                bool gameFinished = false;
                int nom_obl_shar = 16;

                int old_x = 0;

                while (!gameFinished)
                {
                    txBegin();
                    txBitBlt (txDC(), 0, 0, 1280, 720, fonurovnya, 0, 0);

                    for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
                    {
                        txBitBlt (txDC(), obl[nomer_oblasti].lx, obl[nomer_oblasti].vy, obl[nomer_oblasti].rx - obl[nomer_oblasti].lx, obl[nomer_oblasti].ny - obl[nomer_oblasti].vy, vsecuby,  coord(obl[nomer_oblasti]), 10);
                    }

                    int x = obl[nom_obl_shar].lx;
                    int y = obl[nom_obl_shar].vy;
                    txTransparentBlt(txDC(), x + 25, y + 25, 50, 50, spraitshara, 0, 0, TX_WHITE);

                    txSleep(100);

                    if (old_x != x + 100 and proverit_chto_mozhno_idti_suda(obl,   KOLVO_OBLASTEI,  x, y, x + 100, y) )
                    {
                        old_x = x;
                        nom_obl_shar = nom_obl_shar + 1;
                    }
                    else if (old_x != x - 100 and proverit_chto_mozhno_idti_suda(obl,   KOLVO_OBLASTEI,  x, y, x - 100, y) )
                    {
                        old_x = x;
                        nom_obl_shar = nom_obl_shar - 1;
                    }
                    else if (old_x != y - 100 and proverit_chto_mozhno_idti_suda(obl,   KOLVO_OBLASTEI,  x, y, x, y - 100) )
                    {
                        nom_obl_shar = nom_obl_shar - 8;
                    }
                    else if (old_x != y + 100 and proverit_chto_mozhno_idti_suda(obl,   KOLVO_OBLASTEI,  x, y, x, y + 100) )
                    {
                        nom_obl_shar = nom_obl_shar + 8;
                    }

                    txEnd();
                }

            }




            txSleep(10);
            txEnd();
        }


    }

    //Ã…Ã¹Ã¥ Ã¯Ã Ã°Ã³ ÃªÃ Ã°Ã²Ã¨Ã­Ã®Ãª Ã§Ã Ã¡Ã»Ã¢Ã Ã¥Ã¸Ã¼ Ã³Ã¤Ã Ã«Ã¨Ã²Ã¼
    txDeleteDC(main_menu);
    txDeleteDC(vsecuby);
    txDeleteDC(spraitshara);

    return 0;
}
