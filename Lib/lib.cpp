
#include "TXLib.h"


//файл для рисования всех частей тел XD
void risovat_golova(HDC golova,int x ,int y) {
    txTransparentBlt (txDC(), 400, 200, 300, 300, golova, x, y, TX_WHITE);
}
void risovat_fon(HDC fon) {
    txBitBlt (txDC(),0, 0, 1280, 720,fon, 0, 0);
}
