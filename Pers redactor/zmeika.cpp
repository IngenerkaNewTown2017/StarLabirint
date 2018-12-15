#include "TXLib.h"

int main()
{
    txCreateWindow (700,600);

    int xone = 0;
    int yone = 0;

    HDC fon = txLoadImage ("Pictures\\Zmeika\\ito fon.bmp");
    HDC pers = txLoadImage ("Pictures\\Zmeika\\korabl.bmp");

    while(!GetAsyncKeyState('W'))
     {
        txBitBlt (txDC(), 0, 0, 700, 600, fon, 0, 0);
        txTransparentBlt (txDC(), xone, yone, 123, 80, pers, 0, 0,TX_WHITE );

        if (GetAsyncKeyState(VK_LEFT))
        {
            xone =  xone - 2;
        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {
            xone =  xone + 2;
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            yone =  yone - 2;
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            yone =  yone +2;
        }

        txSleep(1);
     }

    txDeleteDC(fon);
    txDeleteDC(pers);
}
