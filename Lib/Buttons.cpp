#pragma once

struct Button
{
    int x1;
    int x2;
    int y1;
    int y2;
    COLORREF color;
    const char* text;
};

void drawButton(Button btn1);
int KNOPKAClick (Button exitButton, int risovat);

void drawButton(Button btn1)
{
    txSetFillColor(RGB(0, 0, 255));
    txRectangle   (btn1.x1, btn1.y1, btn1.x2, btn1.y2);
    txSetFillColor(RGB(0,0,0));
    txRectangle   (btn1.x1+5, btn1.y1+5, btn1.x2-5, btn1.y2-5);
    txDrawText    (btn1.x1, btn1.y1, btn1.x2, btn1.y2, btn1.text);
}



bool checkClick(int MinX, int MaxX, int MinY, int MaxY)
{
    if (
        txMouseX() >= MinX &&
        txMouseX() <= MaxX &&
        txMouseY() <= MaxY &&
        txMouseY() >= MinY &&
        txMouseButtons() & 1
        )
    {
        return true;
    }

    return false;
}

int KNOPKAClick (Button exitButton, int risovat)
{
    if (txMouseX() > exitButton.x1  &&
        txMouseX() < exitButton.x2 &&
        txMouseY() > exitButton.y1  &&
        txMouseY() < exitButton.y2 &&
        txMouseButtons() & 1)
    {
        return 1;
    }

    return risovat;
}

