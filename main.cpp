#include "TXLib.h"
#include <iostream>
#include <string>
#include "dirent.h"
#include <fstream>
#include "lib\\Oblast.cpp"
#include "lib\\Buttons.cpp"
#include "lib\\shar.cpp"
#include "lib\\slconfig.cpp"
#include "XO\\krestiki.cpp"

struct LevelButton
{
    int x;
    int y;
    const char* text;
    COLORREF color1;
    COLORREF color2;
};


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
    txSelectFont("Arial Black", 50);
    txTextOut  (x + 38, y + 25, text);
}

int main()
{
    txCreateWindow (1280, 720);

    txSetColor(TX_YELLOW, 6);
    //+50 - ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½

    LevelButton levelButtons [20];

	levelButtons[0] = {76, 115, "1", RGB(34, 177, 76), RGB(181, 230, 29)};
	levelButtons[1] = {303, 127, "2", RGB(34, 177, 76), RGB(181, 230, 29)};
	levelButtons[2] = {191, 392, "3", RGB(34, 177, 76), RGB(181, 230, 29)};
	levelButtons[3] = {508, 151, "4", RGB(255, 127, 39), RGB(255, 201, 14)};
	levelButtons[4] = {953, 60, "5", RGB(255, 127, 39), RGB(255, 201, 14)};
	levelButtons[5] = {446, 419, "6", RGB(255, 127, 39), RGB(255, 201, 14)};
	levelButtons[6] = {1100, 150, "7", RGB(237, 28, 36), RGB(255, 127, 39)};
	levelButtons[7] = {530, 590, "8", RGB(237, 28, 36), RGB(255, 127, 39)};
	levelButtons[8] = {950, 400, "9", RGB(237, 28, 36), RGB(255, 127, 39)};


    //������ ������ ������� � ���������� Levels
    DIR *mydir;
    struct dirent *filename;
    int kolich_urovnei = 0;

    if ((mydir = opendir ("levels\\")) != NULL)
    {
        while ((filename = readdir (mydir)) != NULL)
        {
            if ((strcmp(".", filename->d_name) !=0) and (strcmp("..", filename->d_name) != 0))
            {
                char* levelmaker = new char[100];
                string str = filename->d_name;
                strcpy(levelmaker, str.substr(0, strlen(filename->d_name)-4).c_str());

                levelButtons[kolich_urovnei].text = levelmaker;

                kolich_urovnei++;
            }
        }
        closedir (mydir);
    }


	for (int n = 0; n < kolich_urovnei; n++)
	{
		if (n < kolich_urovnei - 1)
		{
			txSetColor(levelButtons[n].color2, 6);
			txLine( levelButtons[n].x + 50, levelButtons[n].y + 50, levelButtons[n + 1].x + 50, levelButtons[n + 1].y + 50);
		}

		drawLevelButton(levelButtons[n].x, levelButtons[n].y, levelButtons[n].text, levelButtons[n].color1, levelButtons[n].color2);
	}
    txSleep(100);


    HDC spraitzagruzki = txLoadImage ("pictures\\Labirint\\spraitzagruzki.bmp");
    HDC zagruzka =       txLoadImage ("pictures\\Labirint\\zagrulka.bmp");
    HDC main_menu =      txLoadImage ("pictures\\Labirint\\main_menu.bmp");
    HDC vsecuby =        txLoadImage ("pictures\\Labirint\\vsecuby.bmp");
    HDC kartaurovneya  = txLoadImage ("pictures\\Labirint\\kartaurovneya.bmp");
    HDC fonurovnya =     txLoadImage ("pictures\\Labirint\\fonurovnya.bmp");
    HDC spraitshara =    txLoadImage ("pictures\\Labirint\\spraitshara.bmp");

    Oblast obl[KOLVO_OBLASTEI];
    string file_adress = "";

    OblUr Lev[9];
    for (int n = 0; n < kolich_urovnei; n++)
    {
        char* imya_faila = new char[195];
        strcpy(imya_faila, "levels\\");
        strcat(imya_faila, levelButtons[n].text);
        strcat(imya_faila, ".txt");

        Lev[n] = {levelButtons[n].x, levelButtons[n].x + 100,
                  levelButtons[n].y, levelButtons[n].y + 100, imya_faila};
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

        if (checkClick(517, 705, 274, 370))
        {
            StartGame = true;
        }

        txSleep(10);
        txEnd();
    }

    while (StartGame == true)
    {
        //������ ������ �������
        txBitBlt (txDC(), 0, 0, 1280, 720, kartaurovneya, 0, 0);

		for (int n = 0; n < kolich_urovnei; n++)
		{
			if (n < kolich_urovnei - 1)
			{
				txSetColor(levelButtons[n].color2, 6);
				txLine(levelButtons[n].x + 50, levelButtons[n].y + 50, levelButtons[n + 1].x + 50, levelButtons[n + 1].y + 50);
			}

			drawLevelButton(levelButtons[n].x, levelButtons[n].y, levelButtons[n].text, levelButtons[n].color1, levelButtons[n].color2);
        }

        //�� ����� �� ������� �������� �����
        while(Start_level == false)
        {
            for (int n = 0; n < kolich_urovnei; n++)
            {
                if (checkClick(Lev[n].x, Lev[n].x1, Lev[n].y, Lev[n].y1))
                {
                    Start_level = true;
                    file_adress = Lev[n].adress;
                }
            }

            txSleep(10);
        }


        while(frame < 40)
        {
            txBitBlt (txDC(), 0, 0, 1280, 720, zagruzka, 0, 0);
            txBitBlt (txDC(), 1100, 530, 90, 90, spraitzagruzki, 90 * (frame % 4), 0);
            txSleep(50);
            frame = frame + 1;
        }


        ifstream file (file_adress);

        string poloj;
        int nomer_obl = 0;
        while(getline(file, poloj))//Ã¯Ã®ÃªÃ  Ã¿ Ã­Ã¥ Ã¤Ã®Ã¸Ã¥Ã« Ã¤Ã® ÃªÃ®Ã­Ã¶Ã  Ã´Ã Ã©Ã«Ã 
        {
            obl[nomer_obl] = {atoi(poloj.c_str())};//ÃªÃ®Ã­Ã¢Ã¥Ã°Ã²Ã Ã¶Ã¨Ã¿ Ã±Ã²Ã°Ã®ÃªÃ¨ Ã¢ Ã·Ã¨Ã±Ã«Ã®
            obl[nomer_obl].nomber_obl = nomer_obl;
            nomer_obl = nomer_obl + 1;
        }

        file.close();


        for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
        {
            //13%8 = 5, ÃƒÂ¯ÃƒÂ®ÃƒÂ²ÃƒÂ®ÃƒÂ¬ÃƒÂ³ ÃƒÂ·ÃƒÂ²ÃƒÂ® 13 = 8 * 1 + 5
            obl[nomer_oblasti].lx = get_min_x((nomer_oblasti % 8) + 1);
            obl[nomer_oblasti].rx = get_min_x((nomer_oblasti % 8) + 2);
            obl[nomer_oblasti].vy = get_min_y(nomer_oblasti / 8 + 1);
            obl[nomer_oblasti].ny = get_min_y(nomer_oblasti / 8 + 2);
            obl[nomer_oblasti].max_poloj = get_max_poloj(obl[nomer_oblasti].poloj);
            obl[nomer_oblasti].min_poloj = min_max_poloj(obl[nomer_oblasti].poloj);
        }

        //ÃƒÅ ÃƒÂ ÃƒÂª ÃƒÂ¯ÃƒÂ°ÃƒÂ®ÃƒÂ©ÃƒÂ²ÃƒÂ¨ ÃƒÂ¨ÃƒÂ£ÃƒÂ°ÃƒÂ³ / ÃƒÂ¢ÃƒÂ»ÃƒÂ©ÃƒÂ²ÃƒÂ¨ ÃƒÂ¨ÃƒÂ§ ÃƒÂ¨ÃƒÂ£ÃƒÂ°ÃƒÂ»? Exit ÃƒÂ¢ÃƒÂ¥ÃƒÂ¤ÃƒÂ¼ ÃƒÂ¢ÃƒÂ±ÃƒÂ¥ÃƒÂ£ÃƒÂ¤ÃƒÂ  == false
        while(Exit == false)
        {
            txBegin();
            txBitBlt (txDC(), 0, 0, 1280, 720, fonurovnya, 0, 0);

            txTransparentBlt(txDC(), 30, 330, 50, 50, spraitshara, 0, 0, TX_WHITE);


            //��������
            if (checkClick(1252, 1274, 3, 12))
            {
                igor();
            }


            bool povernuto = false;
            for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
            {
                //ÃƒË†ÃƒÂ¹ÃƒÂ¥ÃƒÂ¬ ÃƒÂªÃƒÂ®ÃƒÂ®ÃƒÂ°ÃƒÂ¤ÃƒÂ¨ÃƒÂ­ÃƒÂ ÃƒÂ²ÃƒÂ³ ÃƒÂ¤ÃƒÂ«ÃƒÂ¿ ÃƒÂ°ÃƒÂ¨ÃƒÂ±ÃƒÂ®ÃƒÂ¢ÃƒÂ ÃƒÂ­ÃƒÂ¨ÃƒÂ¿ ÃƒÂ­ÃƒÂ³ÃƒÂ¦ÃƒÂ­ÃƒÂ®ÃƒÂ£ÃƒÂ® ÃƒÂªÃƒÂ ÃƒÂ¤ÃƒÂ°ÃƒÂ 
                int coord1 = coord(obl[nomer_oblasti]);

                //ÃƒÂÃƒÂ°ÃƒÂ®ÃƒÂ¢ÃƒÂ¥ÃƒÂ°ÃƒÂ¿ÃƒÂ¥ÃƒÂ¬, ÃƒÂ·ÃƒÂ²ÃƒÂ® ÃƒÂªÃƒÂ ÃƒÂ¤ÃƒÂ° ÃƒÂ­ÃƒÂ¥ ÃƒÂ±ÃƒÂ«ÃƒÂ¨ÃƒÂ¸ÃƒÂªÃƒÂ®ÃƒÂ¬ ÃƒÂ¡ÃƒÂ®ÃƒÂ«ÃƒÂ¼ÃƒÂ¸ÃƒÂ®ÃƒÂ©
                if (clickOnOblkast(obl[nomer_oblasti]) == 1)
                {
                    povernuto = true;
                    obl[nomer_oblasti].poloj = obl[nomer_oblasti].poloj + 1;

                    if (obl[nomer_oblasti].poloj > obl[nomer_oblasti].max_poloj)
                    {
                        obl[nomer_oblasti].poloj = obl[nomer_oblasti].min_poloj;
                    }
                }

                txBitBlt (txDC(), obl[nomer_oblasti].lx, obl[nomer_oblasti].vy, obl[nomer_oblasti].rx - obl[nomer_oblasti].lx, obl[nomer_oblasti].ny - obl[nomer_oblasti].vy, vsecuby, coord1, 10);
            }

            if (povernuto)
            {
                txSleep(100);
            }

            //����� �������� ������
            if (checkClick(23, 97, 572, 645))
            {
                bool gameFinished = false;
                int nom_obl_shar = 16;

                int old_x = 0;
                int old_y = 0;

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
                    if (nom_obl_shar != 23)
                    {
                        txTransparentBlt(txDC(), x + 25, y + 25, 50, 50, spraitshara, 0, 0, TX_WHITE);
                    }

                    if (old_x != x + 100 and proverit_chto_mozhno_idti_suda(obl,   KOLVO_OBLASTEI,  x, y, x + 100, y) )
                    {
                        for(int old_x1 = x ; old_x1 <= x + 100; old_x1 += speed_ball)
                        {
                            txBegin();
                            txBitBlt (txDC(), 0, 0, 1280, 720, fonurovnya, 0, 0);
                            for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
                            {
                                txBitBlt (txDC(), obl[nomer_oblasti].lx, obl[nomer_oblasti].vy, obl[nomer_oblasti].rx - obl[nomer_oblasti].lx, obl[nomer_oblasti].ny - obl[nomer_oblasti].vy, vsecuby,  coord(obl[nomer_oblasti]), 10);
                            }
                            txTransparentBlt(txDC(), old_x1 + 25, y + 25, 50, 50, spraitshara, 0, 0, TX_WHITE);
                            txEnd();
                            txSleep(10);
                        }

                        nom_obl_shar = nom_obl_shar + 1;
                        old_x = x;
                        old_y = y;
                    }
                    else if (old_x != x - 100 and proverit_chto_mozhno_idti_suda(obl,   KOLVO_OBLASTEI,  x, y, x - 100, y) )
                    {
                        for(int old_x1 = x ; old_x1 >= x - 100; old_x1 -= speed_ball)
                        {
                            txBegin();
                            txBitBlt (txDC(), 0, 0, 1280, 720, fonurovnya, 0, 0);
                            for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
                            {
                                txBitBlt (txDC(), obl[nomer_oblasti].lx, obl[nomer_oblasti].vy, obl[nomer_oblasti].rx - obl[nomer_oblasti].lx, obl[nomer_oblasti].ny - obl[nomer_oblasti].vy, vsecuby,  coord(obl[nomer_oblasti]), 10);
                            }
                            txTransparentBlt(txDC(), old_x1 + 25, y + 25, 50, 50, spraitshara, 0, 0, TX_WHITE);
                            txEnd();
                            txSleep(10);
                        }

                        nom_obl_shar = nom_obl_shar - 1;
                        old_x = x;
                        old_y = y;
                    }
                    else if (old_y != y - 100 and proverit_chto_mozhno_idti_suda(obl,   KOLVO_OBLASTEI,  x, y, x, y - 100) )
                    {
                        for(int old_y1 = y ; old_y1 >= y- 100; old_y1 -= speed_ball)
                        {
                            txBegin();
                            txBitBlt (txDC(), 0, 0, 1280, 720, fonurovnya, 0, 0);
                            for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
                            {
                                txBitBlt (txDC(), obl[nomer_oblasti].lx, obl[nomer_oblasti].vy, obl[nomer_oblasti].rx - obl[nomer_oblasti].lx, obl[nomer_oblasti].ny - obl[nomer_oblasti].vy, vsecuby,  coord(obl[nomer_oblasti]), 10);
                            }
                            txTransparentBlt(txDC(), x + 25, old_y1 + 25, 50, 50, spraitshara, 0, 0, TX_WHITE);
                            txEnd();
                            txSleep(10);
                        }

                        nom_obl_shar = nom_obl_shar - 8;
                        old_x = x;
                        old_y = y;
                    }
                    else if (old_y != y + 100 and proverit_chto_mozhno_idti_suda(obl,   KOLVO_OBLASTEI,  x, y, x, y + 100) )
                    {
                        for(int old_y1 = y ; old_y1 <= y + 100; old_y1 += speed_ball)
                        {
                            txBegin();
                            txBitBlt (txDC(), 0, 0, 1280, 720, fonurovnya, 0, 0);
                            for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
                            {
                                txBitBlt (txDC(), obl[nomer_oblasti].lx, obl[nomer_oblasti].vy, obl[nomer_oblasti].rx - obl[nomer_oblasti].lx, obl[nomer_oblasti].ny - obl[nomer_oblasti].vy, vsecuby,  coord(obl[nomer_oblasti]), 10);
                            }
                            txTransparentBlt(txDC(), x + 25, old_y1 + 25, 50, 50, spraitshara, 0, 0, TX_WHITE);
                            txEnd();
                            txSleep(10);
                        }
                        nom_obl_shar = nom_obl_shar + 8;
                        old_x = x;
                        old_y = y;
                    }

                    //������ �������
                    if (nom_obl_shar == 23)
                    {
                        gameFinished = true;
                        Start_level = false;
                        Exit = true;
                        txTransparentBlt(txDC(), 1198, 337, 50, 50, spraitshara, 0, 0, TX_WHITE);
                        txSleep(3000);
                    }

                    //��������� � ������
                    if(nom_obl_shar == 16 && old_y > 0 && old_x > 0)
                    {
                        txSetColor(TX_RED);
                        txTextOut(240, 50, "�������� �����, ������.");
                        txSleep(4000);
                        gameFinished = true;
                        Start_level = false;
                        Exit = true;
                    }

                    //�������� �� �����
                    if(old_x != x || old_y != y)
                    {
                        txSetColor(TX_RED);
                        txTextOut(240, 50, "�������� �����, �� ����������� ������ �������.");
                        txSleep(4000);
                        gameFinished = true;
                        Start_level = false;
                        Exit = true;
                    }

                    txEnd();
                }
            }

            txSleep(10);
            txEnd();
        }

        Exit = false;
    }

    //������ � ������ ��������
    txDeleteDC(main_menu);
    txDeleteDC(vsecuby);
    txDeleteDC(spraitshara);
    txDeleteDC(fonurovnya);
    return 0;
}
