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
    int koordinata_bashki = -100;
    int koordinata_odejdi = -100;
    HDC golova = txLoadImage("pictures\\head.bmp");
    HDC fon = txLoadImage ("pictures\\fon.bmp");
    HDC fon1  = txLoadImage ("pictures\\fon1.bmp ");
    HDC fon_golovy  = txLoadImage ("pictures\\fon2.bmp ");
    HDC fon_tela  = txLoadImage ("pictures\\fon3.bmp ");
    HDC fon4  = txLoadImage ("pictures\\fon4.bmp ");
    HDC telo  = txLoadImage ("pictures\\telo.bmp ");
    HDC kartinka = fon1;


    while (!GetAsyncKeyState('R')) {

        txClear();

        risovat_fon(kartinka);

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
           kartinka = fon_golovy;
        }
        else if (checkClick(825, 1000, 75, 121))
        {
           kartinka = fon_tela;
        }
        else if (checkClick(1001, 1185, 75, 121))
        {
           kartinka = fon4;
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


        if (kartinka==fon_golovy)
         {
            if (checkClick(643, 783, 127, 255))
            {
                koordinata_bashki = 3;
            }

            else if (checkClick(785, 925, 127, 255))
            {
                koordinata_bashki = 221;
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
    }
    return 0;
}

