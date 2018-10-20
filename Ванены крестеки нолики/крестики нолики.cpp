#include "TXLib.h"

  int jopa()
{
 //txCreateWindow(490,490);

HDC fon = txLoadImage ("крестикинолики.bmp");

HDC krestic = txLoadImage ("крестик.bmp");
txBitBlt (txDC(), 0, 0, 162, 163, krestic, 0, 0);

HDC nolic = txLoadImage ("нолик.bmp");
txBitBlt (txDC(), 0, 170, 162, 158, nolic, 0, 0);

    int x[5];
    int o[5];
    int nomer_X = 0;
    int nomer_O = 0;
	int figureX[5];
	int figureY[5];
    int figureO[5];
	int figureP[5];


    while (!GetAsyncKeyState(VK_ESCAPE))
    {
		txBegin();
        txClear();
        txBitBlt (txDC(), 0, 0, 500, 500, fon, 0, 0);

        if (txMouseButtons() & 1 ) //крестики
		{
			x[nomer_X] = true;
			figureX[nomer_X] = round(txMouseX() / 165) * 165;
			figureY[nomer_X] = round(txMouseY() / 165) * 165;

            for (int counter = 0; counter < nomer_X; counter++)
            {
                if (figureX[nomer_X] == figureX[counter] and figureY[nomer_X] == figureY[counter]
                )
                {
                    nomer_X = nomer_X - 1;
                }
            }

            if (figureX[nomer_X]  < 495)
            {
                nomer_X = nomer_X + 1;
            }
	    }


        if (txMouseButtons() & 2 ) //нолики
		{
			o[nomer_O] = true;
			figureO[nomer_O] = round(txMouseX() / 165) * 165;
			figureP[nomer_O] = round(txMouseY() / 165) * 165;

            for (int counter = 0; counter < nomer_O; counter++)
            {
                if (figureO[nomer_O] == figureO[counter] and
                figureP[nomer_O] == figureP[counter]

                )

                {
                    nomer_O = nomer_O - 1;
                }
            }
                  nomer_O = nomer_O + 1;
	    }


		for (int counter = 0; counter < nomer_X; counter++)
        {
            txSetColor(TX_RED);
            char str[100];
            sprintf(str, "%d", figureX[counter]);
            txTextOut(500, 100 +30 * counter, str);

            if (x[counter]  == true)
            {
                txTransparentBlt (txDC(), figureX[counter], figureY[counter], 162, 163, krestic, 0, 0, TX_WHITE);
            }
            if (o[counter]  == true)
            {
                txTransparentBlt (txDC(), figureO[counter], figureP[counter], 158,158, nolic, 0, 0, TX_WHITE);
            }
        }



     txSleep(10);
		txEnd();
   }

  return 0;
}
