#include "TXLib.h"

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

