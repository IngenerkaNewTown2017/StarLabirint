#include "TXLib.h"
#include "slconfig.cpp"

struct Oblast
{
    int poloj;
    int lx;
    int rx;
    int vy;
    int ny;
    int max_poloj;
    int min_poloj;
    int nomber_obl;
};

int clickOnOblkast(Oblast obl1);
int coord(Oblast obl1);

int get_max_poloj(int poloj);
int min_max_poloj(int poloj);
int get_min_y(int nomer_stroki);
int get_min_x(int nomer_stolbca);

bool checkReturnToStart(int nom_obl_shar, int old_x, int old_y);
bool proshli(int nom_obl_shar, HDC spraitshara);

void drawFonOblastiIShar(Oblast* obl, HDC fon, HDC vsecuby, HDC spraitshara, int x, int y, int nom_obl_shar);


int get_min_y(int nomer_stroki)
{
    int min_y = 11 + 100 * nomer_stroki;
    return min_y;
}

int get_min_x(int nomer_stolbca)
{
    int min_x = 138 + 100 * nomer_stolbca;
    return min_x;
}

int get_max_poloj(int poloj)
{
    int max_poloj = 0;
    if (poloj >= 1 and poloj <= 4)
    {
        max_poloj = 4;
    }
    else if (poloj >= 5 and poloj <=6)
    {
        max_poloj = 6;
    }

    return max_poloj;
}

int min_max_poloj(int poloj)
{
    int min_poloj = 0;
    if (poloj >= 1 and poloj <= 4)
    {
        min_poloj = 1;
    }
    else if (poloj >= 5 and poloj <=6)
    {
        min_poloj = 5;
    }

    return min_poloj;
}

int coord(Oblast obl1)
{
    int coord1 = 0;
    if (obl1.poloj == 1)
    {
        coord1 = 10;
    }
    else if (obl1.poloj == 2)
    {
        coord1 = 129;
    }
    else if (obl1.poloj == 3)
    {
        coord1 = 248;
    }
    else if (obl1.poloj == 4)
    {
        coord1 = 366;
    }
    else if (obl1.poloj == 5)
    {
        coord1 = 483;
    }
    else if (obl1.poloj == 6)
    {
        coord1 = 602;
    }

    return coord1;
}

int clickOnOblkast(Oblast obl1)
{
    if (txMouseButtons () == 1 &&
        txMouseX () >= obl1.lx &&
        txMouseX () <= obl1.rx &&
        txMouseY () >= obl1.vy &&
        txMouseY () <= obl1.ny)
     {
        return 1;
     }
     return 0;
}

bool checkReturnToStart(int nom_obl_shar, int old_x, int old_y)
{
    if(nom_obl_shar == 16 && old_y > 0 && old_x > 0)
    {
        txSetColor(TX_RED);
        txTextOut(240, 50, "Простите мисье, ошибка.");
        txSleep(4000);
        return true;
    }
    return false;
}

bool proshli(int nom_obl_shar, HDC spraitshara)
{
    if (nom_obl_shar == obl_end)
    {
        txTransparentBlt(txDC(), 1198, 337, 50, 50, spraitshara, 0, 0, TX_WHITE);
        txSleep(3000);
        return true;
    }
    return false;
}

bool GetPovernuto(Oblast* obl)
{
    bool povernuto = false;
    for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
    {
        int coord1 = coord(obl[nomer_oblasti]);

        if (clickOnOblkast(obl[nomer_oblasti]) == 1)
        {
            povernuto = true;
            obl[nomer_oblasti].poloj = obl[nomer_oblasti].poloj + 1;

            if (obl[nomer_oblasti].poloj > obl[nomer_oblasti].max_poloj)
            {
                obl[nomer_oblasti].poloj = obl[nomer_oblasti].min_poloj;
            }
        }
    }

    return povernuto;
}


void drawFonOblastiIShar(Oblast* obl, HDC fon, HDC vsecuby, HDC spraitshara, int x, int y, int nom_obl_shar)
{
    txBegin();
    txBitBlt (txDC(), 0, 0, 1280, 720, fon, 0, 0);
    for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
    {
        txBitBlt (txDC(), obl[nomer_oblasti].lx, obl[nomer_oblasti].vy, obl[nomer_oblasti].rx - obl[nomer_oblasti].lx, obl[nomer_oblasti].ny - obl[nomer_oblasti].vy, vsecuby,  coord(obl[nomer_oblasti]), 10);
    }

    if (nom_obl_shar !=  obl_end)
 {
        txTransparentBlt(txDC(), x + 25, y + 25, 50, 50, spraitshara, 0, 0, TX_WHITE);
    }
    txEnd();
}

void vichislit_obl(Oblast* obl)
{
        for (int nomer_oblasti = 0; nomer_oblasti < KOLVO_OBLASTEI; nomer_oblasti++)
        {
            obl[nomer_oblasti].lx = get_min_x((nomer_oblasti % 8) + 1);
            obl[nomer_oblasti].rx = get_min_x((nomer_oblasti % 8) + 2);
            obl[nomer_oblasti].vy = get_min_y(nomer_oblasti / 8 + 1);
            obl[nomer_oblasti].ny = get_min_y(nomer_oblasti / 8 + 2);
            obl[nomer_oblasti].max_poloj = get_max_poloj(obl[nomer_oblasti].poloj);
            obl[nomer_oblasti].min_poloj = min_max_poloj(obl[nomer_oblasti].poloj);
        }
}
