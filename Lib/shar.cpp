#include "TXLib.h"
int seichas_v = 0;
int bil_v = 0;
int idet_v = 0;



struct tohka_Shara
{
  int xs;
  int ys;
};

//Shar1.xs = get_x_shara(2);

int get_x_shara(int nomer_stolbca); //x 288                            288,161     388,261   разница в 100
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

int kolvo_obl_shar = 40;

/*if(obl.lx < x_shara < obl.rx and obl.vy < y_shara < obl.ny) //в какой области сейчас шар
{
    int seichas_v = nomer_obl;
}

 if(y_shara + 75 == obl,poloj1() or y_shara + 75 = obl,poloj2() or y_shara + 75 = obl,poloj6() )
   {
      move_ball_down();
   }
else if(y_shara + 75 == obl,poloj3() or y_shara + 75 = obl,poloj4() or y_shara + 75 = obl,poloj4())
   {

   }
                       */


int proverit_mozhno_vpravo(int poloj)
{
    if (poloj == 1  or poloj == 3  or poloj == 5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int proverit_mozhno_vlevo(int poloj)
{
    if (poloj == 2  or poloj == 4  or poloj == 5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int proverit_chto_mozhno_idti_suda(
    Oblast* oblasti,   int KOLVO_OBLASTEI,
    int x_old, int y_old,
    int x_new, int y_new)
{
    int normalnyi_x_y_old = 0;
    int normalnyi_x_y_new = 0;

    for (int  nomer = 0; nomer < KOLVO_OBLASTEI; nomer++)
    {
    /*
        int mozhno_vlevo = proverit_mozhno_vlevo(oblasti[nomer].poloj)) ;
        int mozhno_vpravo = proverit_mozhno_vpravo(oblasti[nomer].poloj)) ;


            if (oblasti[nomer].lx == x_old &&
                oblasti[nomer].vy == y_old)
            {
                if (x_new > x_old && mozhno_vpravo)
                {
                    normalnyi_x_y_old  = 1;
                }
                if (x_new < x_old && mozhno_vlevo)
                {
                    normalnyi_x_y_old  = 1;
                }
            }            */


        //Допустим, хотим вправо

        if (x_new > x_old)
        {
            //Из старой точки можно уйти вправо
            if (oblasti[nomer].lx == x_old &&
                oblasti[nomer].vy == y_old &&
                proverit_mozhno_vpravo(oblasti[nomer].poloj))
            {
                normalnyi_x_y_old  = 1;
            }

            //В новую точку можно прийти слева
            if (oblasti[nomer].lx == x_new &&
                oblasti[nomer].vy == y_new &&
                proverit_mozhno_vlevo(oblasti[nomer].poloj))
            {
                normalnyi_x_y_new  = 1;
            }
        }

        //Допустим, хотим вниз
        else if (y_new > y_old)
        {
            //Из старой точки можно уйти вниз
            if (oblasti[nomer].lx == x_old &&
                oblasti[nomer].vy == y_old &&
                (oblasti[nomer].poloj == 3  or oblasti[nomer].poloj == 4  or oblasti[nomer].poloj == 6    ))
            {
                normalnyi_x_y_old  = 1;
            }

            //В новую точку можно прийти сверху
            if (oblasti[nomer].lx == x_new &&
                oblasti[nomer].vy == y_new &&
                (oblasti[nomer].poloj == 1  or oblasti[nomer].poloj == 2  or oblasti[nomer].poloj == 6    ))
            {
                normalnyi_x_y_new  = 1;
            }
        }

         //допустим хотим в вверх
         else if (y_new < y_old)
        {
            //Из старой точки можно уйти вверх
            if (oblasti[nomer].lx == x_old &&
                oblasti[nomer].vy == y_old &&
                (oblasti[nomer].poloj == 1  or oblasti[nomer].poloj == 2  or oblasti[nomer].poloj == 6   ))
            {
                normalnyi_x_y_old  = 1;
            }

            //В новую точку можно прийти снизу
            if (oblasti[nomer].lx == x_new &&
                oblasti[nomer].vy == y_new &&
                (oblasti[nomer].poloj == 3  or oblasti[nomer].poloj == 4  or oblasti[nomer].poloj == 6    ))
            {
                normalnyi_x_y_new  = 1;
            }
        }

         //допустим хотим влево
         else if (x_new < x_old)
        {
            //Из старой точки можно уйти влево
            if (oblasti[nomer].lx == x_old &&
                oblasti[nomer].vy == y_old)
            {
                if(proverit_mozhno_vlevo(oblasti[nomer].poloj))
                {
                    normalnyi_x_y_old  = 1;
                }

                char str[100];
                sprintf(str, "%d %d %d", x_old, y_old, oblasti[nomer].poloj);
                txTextOut(100, 300, str);
            }

            //В новую точку можно прийти справа
            if (oblasti[nomer].lx == x_new &&
                oblasti[nomer].vy == y_new)
            {
                if(proverit_mozhno_vpravo(oblasti[nomer].poloj))
                {
                    normalnyi_x_y_new  = 1;
                }

                char str[100];
                sprintf(str, "%d %d %d", x_old, y_old, oblasti[nomer].poloj);
                txTextOut(100, 300, str);
            }
        }
    }


    //txSleep(1000);
    if (normalnyi_x_y_old && normalnyi_x_y_new)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
