#include "TXLib.h"

  int main()
{
 txCreateWindow(490,490);

HDC fon = txLoadImage ("крестикнолик.bmp");

HDC krestic = txLoadImage ("крестик.bmp");
txBitBlt (txDC(), 0, 0, 162, 163, krestic, 0, 0);

HDC nolic = txLoadImage ("нолик.bmp");
txBitBlt (txDC(), 0, 170, 162, 158, nolic, 0, 0);

    int x[5];
    int o[5];
    int nomer_X = 0;
    int nomer_O = 0;
	int figureX;
	int figureY;
    int figureO;
	int figureP;


    while (!GetAsyncKeyState('Q'))
    {
		txBegin();
        txBitBlt (txDC(), 0, 0, 500, 500, fon, 0, 0);

        if (txMouseButtons() & 1 )
		{
			x[nomer_X] = true;
			figureX = round(txMouseX() / 165) * 165;
			figureY = round(txMouseY() / 165) * 165;
			nomer_X = nomer_X + 1;
	    }


	    //для каждого икса из массива
	    //если его надо рисовать,
	    //то рисуем x[3]

		for (int counter = 0; counter < 5; counter++)
    {
     if (x)
    }
		{
            txTransparentBlt (txDC(), figureX, figureY, 162, 163, krestic, 0, 0, TX_WHITE);
		}

        if (txMouseButtons() & 2 )
		{
			o[nomer_O] = true;
			figureO = round(txMouseX() / 165) * 165;
			figureP = round(txMouseY() / 165) * 165;
			nomer_O = nomer_O + 1;
	    }

		if (nomer_O)
		{
            txTransparentBlt (txDC(), figureO, figureP, 162, 163, nolic, 0, 0, TX_WHITE);
		}
        txSleep(10);
		txEnd();
    }

  return 0;
}
