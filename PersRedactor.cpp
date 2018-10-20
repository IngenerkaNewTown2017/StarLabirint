#include "TXLib.h"
#include "Lib\\lib.cpp"

const int VKLADKA_GOLOVA = 1;
const int VKLADKA_TELO = 2;
const int VKLADKA_LICO = 3;


bool checkClick(int MinX, int MaxX, int MinY, int MaxY)
{
    if (
        txMouseButtons() & 1 &&
        txMouseX() >= MinX &&
        txMouseX() <= MaxX &&
        txMouseY() <= MaxY &&
        txMouseY() >= MinY
        )
    {
        return true;
    }

    return false;
}

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

//Смена вкладки (сделай функцией). На выходе int, на входе ничего
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
    HDC telo  = txLoadImage ("pictures\\telo.bmp ");
    HDC kartinka = fon1;


    while (!GetAsyncKeyState('R')) {

        txBegin();
        txClear();

        risovat_fon(kartinka);
        if (nomer_vkladki == VKLADKA_GOLOVA)
        {
            txBitBlt (txDC(), 639, 120, 290, 185, golovy, 0, 0);
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


        if (x_bashki != -100)
        {
            risovat_golova(golova,x_bashki,y_bashki);
        }

        if (x_odejdi != -100)
        {
            risovat_telo(telo,x_odejdi,y_odejdi);
        }

        drawTabs();
        nomer_vkladki = changeTab(nomer_vkladki);

        if (checkClick(1185, 1240, 75, 121))
        {
            txDestroyWindow();
            return 0;
        }



        //Выбор головы. Почему бы не сделать функцией
        if (nomer_vkladki == VKLADKA_GOLOVA)
        //if (kartinka==fon_golovy)
        {
            if (checkClick(643, 783, 127, 255))
            {
                x_bashki = 3;
            }

            else if (checkClick(785, 925, 127, 255))
            {
                x_bashki = 221;
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
            if (checkClick(643, 825, 127, 300))
            {
                x_odejdi = 9;
            }

            else if (checkClick(820, 999, 127, 300))
            {
                x_odejdi = 205;
            }


        }

        if (checkClick(785, 1080, 655, 715))
        {

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
