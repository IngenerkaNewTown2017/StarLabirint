#include "TXLib.h"
<<<<<<< HEAD
#include "lib\\Oblast.cpp"
=======
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
    int x;
    int x1;
    int y;
    int y1;
    const char* adress;
};
>>>>>>> ef11593e479479ccbd3feb52ee2a05b50f1d54ff

int uroven_tekushii = 1;
int uroven_staryi = 0;

<<<<<<< HEAD

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
=======
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
>>>>>>> ef11593e479479ccbd3feb52ee2a05b50f1d54ff
}


int main()
<<<<<<< HEAD
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
=======
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
>>>>>>> ef11593e479479ccbd3feb52ee2a05b50f1d54ff
