
#include "TXLib.h"
#include "Lib\\lib.cpp"

int main()
    {
    txCreateWindow (1280,720);
    txSetFillColor(TX_WHITE);

    int x = 0;
    int y = 0;
    bool risovat_gol = false;
    bool risovat_gol2 = false;
    bool risovat_odej = false;
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

        if (risovat_gol)
        {
            risovat_golova(golova,3,y);
        }
        else if (risovat_gol2)
        {
            risovat_golova(golova,221,y);
        }

        if (risovat_odej)
        {
            risovat_telo(telo,9,y) ;
        }


        if (txMouseButtons()&& // ���� ������ ����� ������ ����
            txMouseX() >= 0 && // � ���� ��������� �� ������...
            txMouseX() <= 1280 &&
            txMouseY() <= 720 &&
            txMouseY() >= 0)
        {
           //kartinka = fon1;
        }


        if (txMouseButtons() & 1 && // ���� ������ ����� ������ ����
            txMouseX() >= 645 && // � ���� ��������� �� ������...
            txMouseX() <= 821 &&
            txMouseY() <= 123 &&
            txMouseY() >= 77)
        {
           kartinka = fon_golovy;
        }

        if (txMouseButtons() & 1 && // ���� ������ ����� ������ ����
            txMouseX() >= 825 && // � ���� ��������� �� ������...
            txMouseX() <= 1000 &&
            txMouseY() <= 121 &&
            txMouseY() >= 75)
        {
           kartinka = fon_tela;
        }

        if (txMouseButtons() & 1 && // ���� ������ ����� ������ ����
            txMouseX() >= 1001 && // � ���� ��������� �� ������...
            txMouseX() <= 1185 &&
            txMouseY() <= 121 &&
            txMouseY() >= 75)
        {
           kartinka = fon4;
        }

        if (txMouseButtons() & 1 && // ���� ������ ����� ������ ����
            txMouseX() >= 1185 && // � ���� ��������� �� ������...
            txMouseX() <= 1240 &&
            txMouseY() <= 121 &&
            txMouseY() >= 75)
        {
             txDestroyWindow();
            return 0;
        }

         if (kartinka==fon_golovy)
         {

            if (txMouseButtons() & 1 && // ���� ������ ����� ������ ����
                txMouseX() >= 643 && // � ���� ��������� �� ������...
                txMouseX() <= 783 &&
                txMouseY() <= 255 &&
                txMouseY() >= 127)
            {
                risovat_gol = true;
                risovat_gol2 = false;
                //risovat_odej = false;
            }

            if (txMouseButtons() & 1 && // ���� ������ ����� ������ ����
                txMouseX() >= 785 && // � ���� ��������� �� ������...
                txMouseX() <= 925 &&
                txMouseY() <= 255 &&
                txMouseY() >= 125)
            {
                risovat_gol = false;
                risovat_gol2 = true;
                //risovat_odej = false;

            }
        }


         if (kartinka==fon_tela)
         {

            if (txMouseButtons() & 1 && // ���� ������ ����� ������ ����
                txMouseX() >= 645 && // � ���� ��������� �� ������...
                txMouseX() <= 825 &&
                txMouseY() <= 303 &&
                txMouseY() >= 120)
            {
                risovat_odej = true;
                //risovat_gol = false;
                //risovat_gol2 = false;
            }

        }
        txSleep(10);
    }
    return 0;
}

