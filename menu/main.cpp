
#include "TXLib.h"
  void risovat_fon(HDC fon) {
    txBitBlt (txDC(),0, 0, 1280, 720,fon, 0, 0); }

int main()
    {
    txCreateWindow (1280,720);
    txSetFillColor(TX_WHITE);
    int x = 48;
    int y = 720;
   HDC fon = txLoadImage("000.bmp");





    while (!GetAsyncKeyState('R')) {
 txUpdateWindow (false);
        txClear();
        risovat_fon(fon);


        if (txMouseButtons() & 1 && // ���� ������ ����� ������ ����
            txMouseX() >= 13 && // � ���� ��������� �� ������...
            txMouseX() <= 190 &&
            txMouseY() <= 555 &&
            txMouseY() >= 515)
        {
 txSelectFont("Arial Narrow", x, 24, 1000);
        txDrawText(100, 100, 1280, y, "������ ������");
        x=x+5;
        if (x>205){
         y=y-100;
        }
        }

if (txMouseButtons() & 1 && // ���� ������ ����� ������ ����
            txMouseX() >= 17 && // � ���� ��������� �� ������...
            txMouseX() <= 185 &&
            txMouseY() <= 609 &&
            txMouseY() >= 570)
        {
        txDestroyWindow();
     return 0;


        }


        txSleep(10);
    }
    return 0;
}

