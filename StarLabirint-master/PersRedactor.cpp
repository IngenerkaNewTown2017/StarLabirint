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

//����� ������� (������ ��������). �� ������ int, �� ����� ������
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

    int y = 0;
    int nomer_vkladki = 0;
    int koordinata_bashki = -100;
    int koordinata_odejdi = -100;
    HDC golova = txLoadImage("pictures\\head.bmp");
    HDC fon = txLoadImage ("pictures\\fon.bmp");
    HDC fon1  = txLoadImage ("pictures\\fon11.bmp ");
    //HDC fon_golovy  = txLoadImage ("pictures\\fon2.bmp ");
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
            //������ ��� �������� ��� (�� �� ���� ��� ������!!!)
            vkladka(FONtelo);
        }
        else if (nomer_vkladki == VKLADKA_LICO)
        {
            //������ ��� �������� ������ (�� �� ���� ��� ������!!!)
             vkladka(emodji);
        }


        if (koordinata_bashki != -100)
        {
            risovat_golova(golova,koordinata_bashki,y);
        }

        if (koordinata_odejdi != -100)
        {
            risovat_telo(telo,koordinata_odejdi,y);
        }

        nomer_vkladki = changeTab(nomer_vkladki);

        //����� ��������� ������� �������� ��� �� (����� ���������)
        txSetTextAlign (TA_CENTER);
        txSelectFont("Arial", 45);
        txSetColor(TX_BLACK, 5);
        txRectangle(640, 80, 820, 120);
        txDrawText(640, 80, 820, 120, "������");
        txRectangle(825, 80, 1000, 120);
        txDrawText(825, 80, 1000, 120, "����");
        txRectangle(1000, 80, 1185, 120);
        txDrawText(1000, 80, 1185, 120, "������");

        if (checkClick(1185, 1240, 75, 121))
        {
            txDestroyWindow();
            return 0;
        }



        //����� ������. ������ �� �� ������� ��������
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
                y=205;
            }
        }


        //����� ����. ������ �� �� ������� ��������
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

    //���-�� ��� �������. � ���� ��� 100500 ��������, ������� ����� �� �������
    txDeleteDC(golovy);
    txDeleteDC(rects);

    return 0;
}
