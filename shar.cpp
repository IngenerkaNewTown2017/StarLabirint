#include "TXLib.h"

struct tohka_Shara
{
  int xs;
  int ys;
};

//Shar1.xs = get_x_shara(2);

int get_x_shara(int nomer_stolbca); //x 288
int get_y_shara(int nomer_stroki); //y161

int get_y_shara(int nomer_stroki)
{
    int y_shara =  get_min_y(nomer_stroki) + 25;
    return y_shara;
}

int get_x_shara(int nomer_stolbca)
{
    int x_shara =  get_min_x(nomer_stolbca) + 25;
    return x_shara;
}
