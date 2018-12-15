/*!
\mainpage ��� ��������� �������� �������� ������� ������������� .
\file
\brief main ����� ����


\authors StarLabirint�
\version 1.0.0 beta
\date 11.12.2018
\name ������� ��������� �����

*/

#include "TXLib.h"
#include <iostream>
#include <string>
#include <fstream>
#include "lib\\Oblast.cpp"
#include "lib\\Buttons.cpp"
#include "lib\\LevelButtons.cpp"
#include "lib\\shar.cpp"
#include "lib\\slconfig.cpp"
#include "XO\\krestiki.cpp"



struct OblUr
{
    int x;              /// \brief  ��������� �
    int x1;             /// \brief  ��������� x1
    int y;              /// \brief  ��������� y
    int y1;             /// \brief  ��������� y1
    const char* adress; /// \brief ����� ��������
};

int uroven_tekushii = 1;
int uroven_staryi = 0;

int frame = 0;
int x_ball;
int y_ball;
bool Exit = false;
bool StartGame = false;
bool Start_level = false;
bool Game = false;


using namespace std;

void YES_StartGame(LevelButton* levelButtons, HDC kartaurovneya)
{
    txBitBlt(txDC(), 0, 0, 1280, 720, kartaurovneya, 0, 0);

    //������� ��������
    for (int n = 0; n < kolich_urovnei; n++)
    {
        if (n < kolich_urovnei - 1)
        {
            txSetColor(levelButtons[n].color2, 6);
            txLine(levelButtons[n].x + 50, levelButtons[n].y + 50, levelButtons[n + 1].x + 50, levelButtons[n + 1].y + 50);
        }

        drawLevelButton(levelButtons[n].x, levelButtons[n].y, levelButtons[n].text, levelButtons[n].color1, levelButtons[n].color2);
     }
}

void NO_StartGame(HDC main_menu, bool* Exit, bool* StartGame)
{
    txBitBlt (txDC(), 0, 0, 1280, 720, main_menu, 0, 0);

    if (checkClick(525, 689, 480, 580))
    {
        *Exit = true;
    }

    //StartGame = (checkClick(517, 705, 274, 370));
    if (checkClick(517, 705, 274, 370))
    {
        *StartGame = true;
    }

    txSleep(10);
}


int main()
{
    txCreateWindow (1280, 720);

    //Game == true;

    LevelButton levelButtons [20];
    download_all_level_buttoms(levelButtons);


    //������ ������� �� ���������� Levels. ������� ��������
    chtenie_txt_1(levelButtons);

    //��� ������� ��������� ������� ������ �� ����� ��������
    levelButtons[kolich_urovnei - 1].y = levelButtons[8].y;
    levelButtons[kolich_urovnei - 1].x = levelButtons[8].x;


    HDC option =         txLoadImage ("pictures\\Labirint\\option.bmp");
    HDC pauza =          txLoadImage ("pictures\\Labirint\\Pauza.bmp");
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


    while (Exit == false && StartGame == false)
    {
        txBegin();
        txClear();
        NO_StartGame(main_menu, &Exit, &StartGame);
        txEnd();

		if (checkClick(469, 745, 386, 476))
		{
            txBitBlt (txDC(), 0, 0, 1280, 720, option, 0, 0);
			txSleep(1000);
		}
    }

    while (StartGame == true)
    {
		YES_StartGame(levelButtons, kartaurovneya);

        //Ïî êëèêó íà óðîâåíü íà÷èíàåì íîâûé
        while (Start_level == false && Exit == false)
        {
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                Exit = true;
                StartGame = false;
            }

            for (int n = 0; n < kolich_urovnei; n++)
            {
                if (checkClick(Lev[n].x, Lev[n].x1, Lev[n].y, Lev[n].y1))
                {
                    Start_level = true;
                    file_adress = Lev[n].adress;
                    uroven_tekushii = n;
                }
            }

            if (checkClick(612, 643, 0, 34))
            {

                Exit = true;
                StartGame = false;
                //NO_StartGame(main_menu, &Exit, &StartGame);
            }

            txSleep(10);
        }

        if (Exit == false)
        {
            while (frame < 40)
            {
                txBitBlt (txDC(), 0, 0, 1280, 720, zagruzka, 0, 0);
                txBitBlt (txDC(), 1100, 530, 90, 90, spraitzagruzki, 90 * (frame % 4), 0);
                txSleep(50);
                frame = frame + 1;
            }


            ifstream file (file_adress);
            string poloj;
            int nomer_obl = 0;
            while(getline(file, poloj))//ÃƒÂ¯ÃƒÂ®ÃƒÂªÃƒÂ  ÃƒÂ¿ ÃƒÂ­ÃƒÂ¥ ÃƒÂ¤ÃƒÂ®ÃƒÂ¸ÃƒÂ¥ÃƒÂ« ÃƒÂ¤ÃƒÂ® ÃƒÂªÃƒÂ®ÃƒÂ­ÃƒÂ¶ÃƒÂ  ÃƒÂ´ÃƒÂ ÃƒÂ©ÃƒÂ«ÃƒÂ 
            {
                obl[nomer_obl] = {atoi(poloj.c_str())};//ÃƒÂªÃƒÂ®ÃƒÂ­ÃƒÂ¢ÃƒÂ¥ÃƒÂ°ÃƒÂ²ÃƒÂ ÃƒÂ¶ÃƒÂ¨ÃƒÂ¿ ÃƒÂ±ÃƒÂ²ÃƒÂ°ÃƒÂ®ÃƒÂªÃƒÂ¨ ÃƒÂ¢ ÃƒÂ·ÃƒÂ¨ÃƒÂ±ÃƒÂ«ÃƒÂ®
                obl[nomer_obl].nomber_obl = nomer_obl;
                nomer_obl = nomer_obl + 1;
            }
            file.close();

            vichislit_obl(obl);

            //������������ ������
            while (Exit == false)
            {
                txBegin();

                //��������
                if (checkClick(1252, 1274, 3, 12))
                {
                    igor();
                }

                bool povernuto = GetPovernuto(obl);
                drawFonOblastiIShar(obl, fonurovnya, vsecuby, spraitshara, 30, 330, 0);
                if (povernuto)
                {
                    txSleep(100);
                }

                //����� �������� ������
                if (checkClick(23, 97, 572, 645))
                {
                    bool gameFinished = false;
                    int nom_obl_shar = obl_start;

                    int old_x = 0;
                    int old_y = 0;

                    while (!gameFinished)
                    {
                        txBegin();

                        int x = obl[nom_obl_shar].lx;
                        int y = obl[nom_obl_shar].vy;
                        drawFonOblastiIShar(obl, fonurovnya, vsecuby, spraitshara, x, y, nom_obl_shar);

                        if (old_x != x + 100 and proverit_chto_mozhno_idti_suda(obl,   KOLVO_OBLASTEI,  x, y, x + 100, y) )
                        {
                            for(int old_x1 = x ; old_x1 <= x + 100; old_x1 += speed_ball)
                            {
                                drawFonOblastiIShar(obl, fonurovnya, vsecuby, spraitshara, old_x1, y, nom_obl_shar);
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
                                drawFonOblastiIShar(obl, fonurovnya, vsecuby, spraitshara, old_x1, y, nom_obl_shar);
                                txSleep(10);
                            }

                            nom_obl_shar = nom_obl_shar - 1;
                            old_x = x;
                            old_y = y;
                        }
                        else if (old_y != y - 100 and proverit_chto_mozhno_idti_suda(obl,   KOLVO_OBLASTEI,  x, y, x, y - 100) )
                        {
                            for (int old_y1 = y ; old_y1 >= y- 100; old_y1 -= speed_ball)
                            {
                                drawFonOblastiIShar(obl, fonurovnya, vsecuby, spraitshara, x, old_y1, nom_obl_shar);
                                txSleep(10);
                            }

                            nom_obl_shar = nom_obl_shar - 8;
                            old_x = x;
                            old_y = y;
                        }
                        else if (old_y != y + 100 and proverit_chto_mozhno_idti_suda(obl,   KOLVO_OBLASTEI,  x, y, x, y + 100) )
                        {
                            for (int old_y1 = y ; old_y1 <= y + 100; old_y1 += speed_ball)
                            {
                                drawFonOblastiIShar(obl, fonurovnya, vsecuby, spraitshara, x, old_y1, nom_obl_shar);
                                txSleep(10);
                            }
                            nom_obl_shar = nom_obl_shar + 8;
                            old_x = x;
                            old_y = y;
                        }

                        //������ �������
                        if (proshli(nom_obl_shar, spraitshara))
                        {
                            gameFinished = true;
                            Start_level = false;
                            //Exit = true;

							if (uroven_tekushii >= kolich_urovnei - 1)
							{
								gameFinished = true;
								Start_level = false;
								Exit = true;
							}
							else
							{
								uroven_tekushii = uroven_tekushii + 1;
								ifstream file ( Lev[uroven_tekushii].adress);
								string poloj;
								int nomer_obl = 0;

								while(getline(file, poloj))//ÃƒÂ¯ÃƒÂ®ÃƒÂªÃƒÂ  ÃƒÂ¿ ÃƒÂ­ÃƒÂ¥ ÃƒÂ¤ÃƒÂ®ÃƒÂ¸ÃƒÂ¥ÃƒÂ« ÃƒÂ¤ÃƒÂ® ÃƒÂªÃƒÂ®ÃƒÂ­ÃƒÂ¶ÃƒÂ  ÃƒÂ´ÃƒÂ ÃƒÂ©ÃƒÂ«ÃƒÂ 
								{
									obl[nomer_obl] = {atoi(poloj.c_str())};//ÃƒÂªÃƒÂ®ÃƒÂ­ÃƒÂ¢ÃƒÂ¥ÃƒÂ°ÃƒÂ²ÃƒÂ ÃƒÂ¶ÃƒÂ¨ÃƒÂ¿ ÃƒÂ±ÃƒÂ²ÃƒÂ°ÃƒÂ®ÃƒÂªÃƒÂ¨ ÃƒÂ¢ ÃƒÂ·ÃƒÂ¨ÃƒÂ±ÃƒÂ«ÃƒÂ®
									obl[nomer_obl].nomber_obl = nomer_obl;
									nomer_obl = nomer_obl + 1;
								}
								file.close();

							vichislit_obl(obl);
                           }
                        }

                        //��������� � ������
                        if (checkReturnToStart(nom_obl_shar, old_x, old_y))
                        {
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

						//�����
						bool Restart = false;
						bool Return = false;
						if (checkClick(600, 643, 0, 23))
						{
							txSleep(1000);
							while (!Restart and !Return)
							{
								txBitBlt (txDC(), 198, 93, 873, 536, pauza, 0, 0);
								txSleep(10);

                                if (checkClick(600, 643, 0, 23))
                                {
                                    Return = true;
                                }
                                //�������
                                if (checkClick(800, 934, 442, 577))
                                {
                                    nom_obl_shar = obl_start;
                                    Restart = true;
                                    gameFinished = true;
                                    Exit = false;
                                }
                            }
						}

                        txEnd();
                    }
                }

                txSleep(10);
                txEnd();
            }

            Exit = false;
        }
    }

    //Óäàëÿé è äðóãèå êàðòèíêè
    txDeleteDC(main_menu);
    txDeleteDC(vsecuby);
    txDeleteDC(spraitshara);
    txDeleteDC(fonurovnya);
    return 0;
}
