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
    txBitBlt (txDC(), 220, 255, 160, 160, golova, x, y);
}
void risovat_telo(HDC telo,int x ,int y) {
    txBitBlt (txDC(), 220, 410,145, 145, telo, x, y);

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
void reklama (){

       txSetTextAlign (TA_CENTER);
    txSelectFont("Arial", 95);
    txSetColor(TX_RED, 5);
    txDrawText(10, 10, 1000,1000, "нее ворууй");
    txSleep (95);
    txSetColor(TX_BLUE, 5);
    txDrawText(10, 10, 1000,1000, "нее ворууй");
    txSleep (95);
    txSetColor(TX_RED, 5);
    txDrawText(10, 10, 1000,1000, "нее ворууй");
    txSleep (95);
    txSetColor(TX_GREEN, 5);
    txDrawText(10, 10, 1000,1000, "нее ворууй");
    txSleep (95);
    txSetColor(TX_YELLOW, 5);
     txDrawText(10, 10, 1000,1000, "нее ворууй");}
