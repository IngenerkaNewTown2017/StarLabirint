#include "TXLib.h"
#include "Lib\\lib.cpp"

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

int main()
    {
    txCreateWindow (1280,720);
    txSetFillColor(TX_WHITE);

    int y = 0;
    int nomer_vkladki = 0;
    const int VKLADKA_GOLOVA = 1;
    const int VKLADKA_TELO = 2;
    const int VKLADKA_LICO = 3;
    int koordinata_bashki = -100;
    int koordinata_odejdi = -100;
    HDC golova = txLoadImage("pictures\\head.bmp");
    HDC fon = txLoadImage ("pictures\\fon.bmp");
    HDC fon1  = txLoadImage ("pictures\\fon1.bmp ");
    //HDC fon_golovy  = txLoadImage ("pictures\\fon2.bmp ");
    HDC golovy  = txLoadImage ("pictures\\face.bmp ");
    HDC rects  = txLoadImage ("pictures\\rects.bmp ");
    HDC fon_tela  = txLoadImage ("pictures\\fon3.bmp ");
    HDC fon4  = txLoadImage ("pictures\\fon4.bmp ");
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
        }
        else if (nomer_vkladki == VKLADKA_LICO)
        {
            //Рисуем все варианты эмоций (но не весь фон меняем!!!)
        }


        if (koordinata_bashki != -100)
        {
            risovat_golova(golova,koordinata_bashki,y);
        }

        if (koordinata_odejdi != -100)
        {
            risovat_telo(telo,koordinata_odejdi,y);
        }


        //Смена вкладки (сделай функцией). На выходе int, на входе ничего
        if (checkClick(645, 821, 77, 123))
        {
            kartinka = fon1;
            nomer_vkladki = VKLADKA_GOLOVA;
        }
        else if (checkClick(825, 1000, 75, 121))
        {
            //А потом картинка не должна меняться (Меняем не весь фон, а только фрагмент со всеми телами)
            kartinka = fon_tela;
            nomer_vkladki = VKLADKA_TELO;
        }
        else if (checkClick(1001, 1185, 75, 121))
        {
            kartinka = fon4;
            nomer_vkladki = VKLADKA_LICO;
        }

        //Пусть остальные вкладки рисуются так же (через ректанглы)
        txSetColor(TX_BLACK, 5);
        txRectangle(640, 80, 820, 120);
        txSetTextAlign (TA_CENTER);
        txSelectFont("Arial", 45);
        txDrawText(640, 80, 820, 120, "Голова");


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
                koordinata_bashki = 3;
            }

            else if (checkClick(785, 925, 127, 255))
            {
                koordinata_bashki = 221;
            }

            //640 580 1240 660
            if (koordinata_bashki == 3 &&  checkClick( 640, 700, 580, 660))
            {
                //y=205;
            }
        }


        //Выбор тела. Почему бы не сделать функцией
        if (nomer_vkladki == VKLADKA_TELO)
        {
            if (checkClick(643, 825, 127, 300))
            {
                koordinata_odejdi = 9;
            }

            else if (checkClick(820, 999, 127, 300))
            {
                koordinata_odejdi = 205;
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
