
#include "TXLib.h"

int x_ball;
int y_ball;
int point_cuba;//их дохига будет    не забудь даун
int speed_ball = 35;

int main()
    {
    txCreateWindow (1280, 720);
    HDC main_menu = txLoadImage ("main_menu.bmp");
    txBitBlt (txDC(), 0, 0, 1280, 720, main_menu, 0, 0);

    txDeleteDC (main_menu);
    }


void move_ball_rigth()
{
/*это движение шара вправо */for(x_ball=point_cuba; x_ball<=/*другой*/point_cuba; x_ball++)
{
  x_ball=x_ball+speed_ball;
}
}

void move_ball_left()
{
/*это движение шара влево */for(x_ball=point_cuba; x_ball<=/*другой*/point_cuba; x_ball++)
{
 x_ball=x_ball-speed_ball;
}
}

void move_ball_up()
{
/*это движение шара вверх */for(y_ball=point_cuba; y_ball<=/*другой*/point_cuba; y_ball++)
{
 y_ball=y_ball+speed_ball;
}
}

void move_ball_down()
{
/*это движение шара вниз */for(y_ball=point_cuba; y_ball<=/*другой*/point_cuba; y_ball++)
{
 y_ball=y_ball-speed_ball;
}
}







