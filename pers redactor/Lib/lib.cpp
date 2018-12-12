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
    txTransparentBlt (txDC(), 220, 255, RAZMER_KARTINKI_GOLOVY, 160, golova, x, y , TX_WHITE);
}
void risovat_telo(HDC telo,int x ,int y) {
    txTransparentBlt (txDC(), 220, 410,RAZMER_KARTINKI_TELA, 180, telo, x, y, TX_WHITE);

}
void risovat_fon(HDC fon) {
    txBitBlt (txDC(),0, 0, 1280, 720,fon, 0, 0);
}
void vkladka(HDC FONtelo){
    txBitBlt (txDC(),635, 70, 1280, 720,FONtelo, 0, 0);
}
void risovat_lico(HDC lico1,int x ,int y) {
    txTransparentBlt (txDC(), 238, 342, RAZMER_KARTINKI_EMOJI,37, lico1, x, y, TX_WHITE);
}

