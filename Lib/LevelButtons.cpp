#pragma once

#include "TXLib.h"

struct LevelButton
{
    int x;
    int y;
    const char* text;
    COLORREF color1;
    COLORREF color2;
};

void drawLevelButton(int x, int y, const char* text, COLORREF backColor, COLORREF frontColor);
void drawLevelButton(int x, int y, const char* text, COLORREF backColor, COLORREF frontColor)
{
    //x = 76, y = 115
    txSetColor(TX_BLACK);
    txSetFillColor(backColor);
    txRectangle(x,      y,      x +  99, y +  99);

    txSetColor(frontColor);
    txSetFillColor(frontColor);
    txRectangle(x + 25, y -  5, x +  75, y + 104);
    txRectangle(x -  5, y + 24, x + 105, y +  76);

    txSetColor(TX_BLACK);
    txSelectFont("Arial Black", 50);
    txTextOut  (x + 38, y + 25, text);
}
