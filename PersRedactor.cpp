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

    int x = 0;
    int y = 0;
    int nomer_vkladki = 0;
    const int VKLADKA_LICO = 1;
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
        if (nomer_vkladki == VKLADKA_LICO)
        {
            txBitBlt (txDC(), 639, 120, 290, 185, golovy, x, y);
            txBitBlt (txDC(), 640, 580, 600, 80, rects, x, y);
        }


        if (koordinata_bashki != -100)
        {
            risovat_golova(golova,koordinata_bashki,y);
        }


        if (koordinata_odejdi != -100)
        {
            risovat_telo(telo,koordinata_odejdi,y);
        }



        if (checkClick(645, 821, 77, 123))
        {
           kartinka = fon1;
           nomer_vkladki = VKLADKA_LICO;
        }
        else if (checkClick(825, 1000, 75, 121))
        {
           kartinka = fon_tela;
           nomer_vkladki = 0;
        }
        else if (checkClick(1001, 1185, 75, 121))
        {
           kartinka = fon4;
           nomer_vkladki = 0;
        }

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



        if (nomer_vkladki == VKLADKA_LICO)
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
                y=205;
            }
        }


        if (kartinka==fon_tela)
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

        txSleep(10);
        txEnd();
    }

    txDeleteDC(golovy);
    txDeleteDC(rects);

    return 0;
}
