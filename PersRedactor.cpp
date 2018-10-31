#include "TXLib.h"
#include "Lib\\lib.cpp"
#include "Lib\\PersStruct.cpp"
#include "Lib\\Buttons.cpp"
#include <string> // РїРѕРґРєР»СЋС‡Р°РµРј СЃС‚СЂРѕРєРё
#include <fstream>
#include <iostream>

#include "Lib\\save.cpp"
using namespace std;

const int VKLADKA_GOLOVA = 1;
const int VKLADKA_TELO = 2;
const int VKLADKA_LICO = 3;


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

int main()
    {
    txCreateWindow (1280,720);
    txSetFillColor(TX_WHITE);

    int nomer_vkladki = 0;

    int x_bashki = -100;
    int y_bashki = 0;

    int x_odejdi = -100;
    int y_odejdi = 0;
    HDC golova = txLoadImage("pictures\\head.bmp");
    HDC fon = txLoadImage ("pictures\\fon.bmp");
    HDC fon1  = txLoadImage ("pictures\\fon11.bmp ");
    HDC golovy  = txLoadImage ("pictures\\face.bmp ");
    HDC rects  = txLoadImage ("pictures\\rects.bmp ");
    HDC FONtelo =  txLoadImage ("pictures\\1123456.bmp");
    HDC emodji = txLoadImage ("pictures\\123444.bmp");
    HDC teloPic  = txLoadImage ("pictures\\telo.bmp ");
    HDC kartinka = fon1;


    int vsego_boshek = 4;
    PersPartButton bashka[vsego_boshek];
    bashka[0] = { 643,  783, 127, 255,   3, 1};
    bashka[1] = { 785,  925, 127, 255, 221, 0};
    bashka[2] = {1055, 1190, 127, 255, 450, 3};//негр
    bashka[3] = { 930, 1060, 127, 255, 665, 0};//дедушка

    int vsego_tel = 4;
    PersPartButton telo[vsego_tel];
    telo[0] = { 643,  825, 127, 300,   5, 0};
    telo[1] = { 820,  999, 127, 300, 200, 0};
    telo[2] = {1000, 1180, 127, 300, 390, 0};
    telo[3] = { 635,  825, 300, 485, 570, 0};


    ifstream file("Lib\\2.txt"); // С„Р°Р№Р» РёР· РєРѕС‚РѕСЂРѕРіРѕ С‡РёС‚Р°РµРј (РґР»СЏ Р»РёРЅСѓРєСЃ РїСѓС‚СЊ Р±СѓРґРµС‚ РІС‹РіР»СЏРґРµС‚СЊ РїРѕ РґСЂСѓРіРѕРјСѓ)

    string stroka_golovy, stroka_tela;
    getline(file, stroka_golovy);
    x_bashki = {atoi(stroka_golovy.c_str())};
    getline(file, stroka_tela);
    x_odejdi = {atoi(stroka_tela.c_str())};
    file.close();

ofstream out;
out.open("Lib\\3.txt");
if (out.is_open())
{
out << x_bashki << std::endl;
}
out.close();

    while (!GetAsyncKeyState('R')) {

        txBegin();
        txClear();

        risovat_fon(kartinka);
        if (nomer_vkladki == VKLADKA_GOLOVA)
        {
            txBitBlt (txDC(), 639, 120, 600, 600, golovy, 0, 0);
            txBitBlt (txDC(), 640, 580, 600, 80, rects, 0, 0);
        }
        else if (nomer_vkladki == VKLADKA_TELO)
        {
            //Рисуем все варианты тел (но не весь фон меняем!!!)
            vkladka(FONtelo);
        }
        else if (nomer_vkladki == VKLADKA_LICO)
        {
            //Рисуем все варианты эмоций (но не весь фон меняем!!!)
             vkladka(emodji);
        }


        if (x_bashki != -100)   //450.660
        {
            risovat_golova(golova,x_bashki,y_bashki);
        }

        if (x_odejdi != -100)
        {
            risovat_telo(teloPic,x_odejdi,y_odejdi);
        }

        drawTabs();
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

        //СОхранение
        if (checkClick(785, 1080, 655, 715))
        {
             ScreenCapture(70, 155, 450, 450, "picture.bmp");
             return 0;
        }

        txSleep(10);
        txEnd();
    }



    //Что-то мне кажется. у тебя еще 100500 картинок, которые никто не удаляет
    txDeleteDC(golovy);
    txDeleteDC(rects);

    return 0;
}
