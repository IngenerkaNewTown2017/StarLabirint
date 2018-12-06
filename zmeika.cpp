#include "TXLib.h"

int main()
{
    txCreateWindow (700,600);

    HDC fon = txLoadImage ("Pictures\\Zmeika\\ito fon.bmp");
    txBitBlt (txDC(), 0, 0, 700, 600, fon, 0, 0);
    HDC pers = txLoadImage ("Pictures\\Zmeika\\korabl.bmp");
    txBitBlt (txDC(), 0, 0, 100, 300, pers, 0, 0);

    txDeleteDC(fon);
}
