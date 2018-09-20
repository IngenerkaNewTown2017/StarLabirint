#include "TXLib.h"
#include "Lib\\lib.cpp"

int main()
    {
    txCreateWindow (1280,720);
    txSetFillColor(TX_WHITE);

    int x = 0;
    int y = 0;


    HDC golova = txLoadImage("pictures\\333.bmp");
    HDC fon = txLoadImage ("pictures\\fon.bmp");



    while (!GetAsyncKeyState('R')) {

        txClear();
        risovat_fon(fon);
        risovat_golova(golova,x,y);

        if (txMouseButtons() & 1 && // если нажата левая кнопка мыши
            txMouseX() >= 173 && // И мышь находится на кнопке...
            txMouseX() <= 351 &&
            txMouseY() <= 381 &&
            txMouseY() >= 256)
        {
            x=270;
        }

        if (txMouseButtons() & 1 && // если нажата левая кнопка мыши
            txMouseX() >= 934 && // И мышь находится на кнопке...
            txMouseX() <= 1083 &&
            txMouseY() <= 390 &&
            txMouseY() >= 294)
        {
            x=0;
        }

        if (txMouseButtons() & 1 && // если нажата левая кнопка мыши
            txMouseX() >= 470 && // И мышь находится на кнопке...
            txMouseX() <= 535 &&
            txMouseY() <= 716 &&
            txMouseY() >= 650)
        {
            x=530;
        }

        txSleep(10);
    }

    return 0;
}
