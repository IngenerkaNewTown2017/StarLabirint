#include "TXLib.h"

struct ColorButton
{
    int x;
    int x1;
    int y;
    int y1;
    COLORREF color;
    int pictureX;
    int pictureY;
};

//файл для рисования всех частей тел XD
void risovat_golova(HDC golova,int x ,int y) {
    txBitBlt (txDC(), 200, 200, 211, 200, golova, x, y);
}
void risovat_telo(HDC telo,int x ,int y) {
    txBitBlt (txDC(), 205, 395, 169, 168, telo, x, y);

}
void risovat_fon(HDC fon) {
    txBitBlt (txDC(),0, 0, 1280, 720,fon, 0, 0);
}
void vkladka(HDC FONtelo){
    txBitBlt (txDC(),635, 70, 1280, 720,FONtelo, 0, 0);
}
void risovat_lico(HDC lico1,int x ,int y) {
    txBitBlt (txDC(), 205, 295, 150, 50, lico1, x, y);
}
