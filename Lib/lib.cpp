
#include "TXLib.h"


//файл для рисования всех частей тел XD
void risovat_golova(HDC golova,int x ,int y) {
    txBitBlt (txDC(), 200, 200, 211, 200, golova, x, y);
}
void risovat_telo(HDC telo,int x ,int y) {
    txBitBlt (txDC(), 205, 395, 169, 168, telo, 0, 0);
}
void risovat_fon(HDC fon) {
    txBitBlt (txDC(),0, 0, 1280, 720,fon, 0, 0);
}
