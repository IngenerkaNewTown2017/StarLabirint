#include "TXLib.h"
#include "Lib\\config.cpp"
#include "Lib\\lib.cpp"
#include "Lib\\PersStruct.cpp"
#include "Lib\\Buttons.cpp"
#include <string> // РїРѕРґРєР»СЋС‡Р°РµРј СЃС‚СЂРѕРєРё
#include <fstream>
#include <iostream>

#include "Lib\\save.cpp"
using namespace std;


void drawTabs()
{
    //Пусть остальные вкладки рисуются так же (через ректанглы)
    txSetTextAlign (TA_CENTER);
    txSelectFont("Arial", 45);
    txSetColor(TX_BLACK, 5);
    txRectangle(640, 80, 820, 120);
    txDrawText(640, 80, 820, 120, "Голова");
    txRectangle(825, 80, 1000, 120);
    txDrawText(825, 80, 1000, 120, "Тело");
    txRectangle(1000, 80, 1185, 120);
    txDrawText(1000, 80, 1185, 120, "Эмоции");
}



int changeTab(int tab)
{
    if (checkClick(645, 821, 77, 123))
    {
        tab = VKLADKA_GOLOVA;
    }
    else if (checkClick(825, 1000, 75, 121))
    {
       tab = VKLADKA_TELO;
    }
    else if (checkClick(1001, 1185, 75, 121))
    {
       tab = VKLADKA_LICO;
    }

    return tab;
}

int SizerX(HDC golova)
{
    HBITMAP hbm=(HBITMAP)Win32::GetCurrentObject(golova, OBJ_BITMAP);
    BITMAP bm;
    Win32::GetObject(hbm,sizeof(bm), (LPVOID)&bm);
    return bm.bmWidth;
}

int SizerY(HDC golova)
{
    HBITMAP hbm=(HBITMAP)Win32::GetCurrentObject(golova, OBJ_BITMAP);
    BITMAP bm;
    Win32::GetObject(hbm,sizeof(bm), (LPVOID)&bm);
    return bm.bmHeight;
}

int getAllParts(PersPartButton* bashka, int razmer_odnoi_chasti, int width_golov, int vysota_golov, int vysota_odnoi_bashki)
{
    int vsego_boshek = 0;
    int coordX = 0;
    int coordY = 0;
    int x_nachalo = 643;
    int y_nachalo = 127;
    while (coordY < vysota_golov)
    {
        coordX = 0;

        while (coordX < width_golov - razmer_odnoi_chasti)
        {
            bashka[vsego_boshek] = { x_nachalo +  vsego_boshek *      razmer_odnoi_chasti,
                                     x_nachalo + (vsego_boshek + 1) * razmer_odnoi_chasti,
                                     y_nachalo,
                                     y_nachalo + 127,
                                     (vsego_boshek % 3) * razmer_odnoi_chasti,
                                     y_nachalo - 127};
            vsego_boshek ++;
            coordX += razmer_odnoi_chasti;
        }

        x_nachalo = x_nachalo - coordX;
        y_nachalo = y_nachalo + vysota_odnoi_bashki;
        coordY = coordY + razmer_odnoi_chasti;
    }

    return vsego_boshek;
}

int main()
    {
    txCreateWindow (1280,720);
    txSetFillColor(TX_WHITE);

    COLORREF face_color = TX_WHITE;

    int nomer_vkladki = 0;

    int x_bashki = -100;
    int y_bashki = 0;

    int x_odejdi = -100;
    int y_odejdi = 0;

    int x_lico = -100;
    int y_lico = 0;

    bool antivor = false;

    HDC fon = txLoadImage ("pictures\\fon.bmp");
    HDC fon1  = txLoadImage ("pictures\\fon11.bmp");

    HDC golova = txLoadImage("pictures\\head3.bmp");
    int width_golov = SizerX(golova);
    int vysota_golov = SizerY(golova);
    HDC teloPic  = txLoadImage ("pictures\\telo2.bmp ");
    int width_tel = SizerX(teloPic);
    int vysota_tel = SizerY(teloPic);
    HDC rects  = txLoadImage ("pictures\\rects.bmp");
    //HDC FONtelo =  txLoadImage ("pictures\\1123456.bmp");
    HDC emodji = txLoadImage ("pictures\\5.bmp");
    HDC lico1 = txLoadImage ("pictures\\eye.bmp");
    HDC kartinka = fon1;

    PersPartButton bashka[100];
    int vsego_boshek = getAllParts(bashka, RAZMER_KARTINKI_GOLOVY, width_golov, vysota_golov, 150);
    PersPartButton telo[100];
    int vsego_tel = getAllParts(telo, RAZMER_KARTINKI_TELA, width_tel, vysota_tel, 220);

    int vsego_emoj = 4;
    PersPartButton lico[vsego_emoj];
    lico[0] = { 640, 783,3,250,   5, 0};
    lico[1] = { 785,  925,3, 250, 200, 0};
    lico[2] = {1055, 350,3, 250, 390, 0};
    lico[3] = {931, 1060,3, 2, 570, 0};

    ifstream file("Lib\\2.txt"); // С„Р°Р№Р» РёР· РєРѕС‚РѕСЂРѕРіРѕ С‡РёС‚Р°РµРј (РґР»СЏ Р»РёРЅСѓРєСЃ РїСѓС‚СЊ Р±СѓРґРµС‚ РІС‹РіР»СЏРґРµС‚СЊ РїРѕ РґСЂСѓРіРѕРјСѓ)

    string stroka_golovy, stroka_tela,stroka_lico;
    getline(file, stroka_golovy);
    x_bashki = {atoi(stroka_golovy.c_str())};
    getline(file, stroka_tela);
    x_odejdi = {atoi(stroka_tela.c_str())};
    getline(file, stroka_lico);
    x_lico = {atoi(stroka_lico.c_str())};
    file.close();


    ofstream out;
    out.open("Lib\\3.txt");
    if (out.is_open())
    {
    out << x_bashki << std::endl;
    }
    out.close();

    bool isExit = false;
    while (!GetAsyncKeyState('R') && !isExit) {

        txBegin();
        txSetFillColor(TX_WHITE);
        txClear();

        drawTabs();

        risovat_fon(kartinka);
        if (nomer_vkladki == VKLADKA_GOLOVA)
        {
            txBitBlt (txDC(), 639, 120, 600, 600, golova, 0, 0);
            txBitBlt (txDC(), 640, 580, 600, 80, rects, 0, 0);
        }
        else if (nomer_vkladki == VKLADKA_TELO)
        {
            txBitBlt (txDC(), 639, 120, 600, 600, teloPic, 0, 0);
        }
        else if (nomer_vkladki == VKLADKA_LICO)
        {
            //Рисуем все варианты эмоций (но не весь фон меняем!!!)
             vkladka(emodji);
        }


        if (x_bashki != -100)   //450.660
        {
            risovat_golova(golova,x_bashki,y_bashki);

            txSetFillColor(face_color);
            txFloodFill(220,220);
        }

        if (x_odejdi != -100)
        {
            risovat_telo(teloPic,x_odejdi,y_odejdi);
        }

        if (x_lico != -100)
        {
            //risovat_lico(lico1,x_lico,y_lico);
        }
        nomer_vkladki = changeTab(nomer_vkladki);

        //f (checkClick(1185, 1240, 75, 121))
        {
            //txDestroyWindow();
           // return 0;
        }



        //Выбор головы. Почему бы не сделать функцией
        if (nomer_vkladki == VKLADKA_GOLOVA)
        {
            for (int nomer_bashki = 0; nomer_bashki < vsego_boshek; nomer_bashki++)
            {
                if (checkClick(bashka[nomer_bashki].x1, bashka[nomer_bashki].x2, bashka[nomer_bashki].y1, bashka[nomer_bashki].y2))
                {
                    x_bashki = bashka[nomer_bashki].part_x;
                    y_bashki = bashka[nomer_bashki].part_y;
                }

            }


            //640 580 1240 660
            if (checkClick( 640, 700, 580, 660))
            {
                y_bashki = 205;
            }


            if (checkClick(100,200, 100, 200))
            {
                face_color = TX_RED;
            }
        }


        //Выбор тела. Почему бы не сделать функцией
        if (nomer_vkladki == VKLADKA_TELO)
        {
            for (int nomer_tela = 0; nomer_tela < vsego_tel; nomer_tela++)
            {
                if (checkClick(telo[nomer_tela].x1, telo[nomer_tela].x2, telo[nomer_tela].y1, telo[nomer_tela].y2))
                {
                    x_odejdi = telo[nomer_tela].part_x;
                    y_odejdi = telo[nomer_tela].part_y;
                }

            }
        }


        /*if (nomer_vkladki == VKLADKA_LICO)
        {
            for (int nomer_lico = 0; nomer_lico < vsego_emoj; nomer_lico++)
            {
                if (checkClick(lico[nomer_lico].x1, telo[nomer_lico].x2, lico[nomer_lico].y1, lico[nomer_lico].y2))
                {
                    x_lico = lico[nomer_lico].part_x;
                    y_lico = lico[nomer_lico].part_y;
                }

            }
        }
*/
        if (GetAsyncKeyState('B'))
        {
            antivor= true;
        }

        if (antivor == false )
        {
            txSelectFont("Arial", 85);
            txSetColor(TX_RED, 5);
            txDrawText(150,350, 500,500, "туть");
        }

        if (antivor == false && checkClick(785, 1080, 655, 715) )
        {
            int xtext = 10;
            txSetTextAlign (TA_CENTER);
            txSelectFont("Arial", 150);
            txSetColor(TX_RED, 5);
            txDrawText(xtext, 50, 1000,1000, "buy full version");
            txSleep (50);
            xtext = xtext+30;
            txSetColor(TX_BLUE, 5);
            txDrawText(xtext, 0, 1000,1000, "buy full version");
            txSleep (50);
            xtext = xtext+30;
            txSetColor(TX_RED, 5);
            txDrawText(xtext, 10, 1000,1000, "buy full version");
            txSleep (50);
            xtext = xtext+30;

            xtext = xtext+30;
            txSetColor(TX_GREEN, 5);
            txDrawText(xtext, 25, 1000,1000, "buy full version");
            xtext = xtext+30;
            txSleep(30);
        }

        //СОхранение
        if (checkClick(785, 1080, 655, 715))
        {

             ScreenCapture(70, 120, 450, 450, "picture.jpg");
             txSelectFont("Arial", 150);
    txSetColor(TX_BLACK, 5);
    txDrawText(0, 10, 1000,1280, "ава сохранена");
    txSleep (2000);

            isExit = true;
        }

        txEnd();
        txSleep (50);

		  //при выполнении программы

    }






    //Что-то мне кажется. у тебя еще 100500 картинок, которые никто не удаляет
    txDeleteDC(golova);
    txDeleteDC(rects);

    return 0;
}
