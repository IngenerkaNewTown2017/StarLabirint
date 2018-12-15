/*!
\file
\brief Кнопки уровней


\authors StarLabirint™
\version 1.0.0 beta
\date 11.12.2018
\example https://github.com/IngenerkaNewTown2017/StarLabirint
\warning Осторожнее
\name Библиотеки

*/
#pragma once

#include "TXLib.h"
#include "dirent.h"

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

void download_all_level_buttoms(LevelButton* levelButtons)
{
	levelButtons[0] = {76, 115, "1", RGB(34, 177, 76), RGB(181, 230, 29)};
	levelButtons[1] = {303, 127, "2", RGB(34, 177, 76), RGB(181, 230, 29)};
	levelButtons[2] = {191, 392, "3", RGB(34, 177, 76), RGB(181, 230, 29)};
	levelButtons[3] = {508, 151, "4", RGB(255, 127, 39), RGB(255, 201, 14)};
	levelButtons[4] = {953, 60, "5", RGB(255, 127, 39), RGB(255, 201, 14)};
	levelButtons[5] = {446, 419, "6", RGB(255, 127, 39), RGB(255, 201, 14)};
	levelButtons[6] = {1100, 150, "7", RGB(237, 28, 36), RGB(255, 127, 39)};
	levelButtons[7] = {530, 590, "8", RGB(237, 28, 36), RGB(255, 127, 39)};
	levelButtons[8] = {950, 400, "9", RGB(237, 28, 36), RGB(255, 127, 39)};
}

void chtenie_txt_1(LevelButton* levelButtons)
{
    DIR *mydir;
    struct dirent *filename;
    int kolich_urovnei = 0;

    if ((mydir = opendir ("levels\\")) != NULL)
    {
        while ((filename = readdir (mydir)) != NULL)
        {
            if ((strcmp(".", filename->d_name) !=0) and (strcmp("..", filename->d_name) != 0))
            {
                char* levelmaker = new char[100];
                string str = filename->d_name;
                strcpy(levelmaker, str.substr(0, strlen(filename->d_name)-4).c_str());

                levelButtons[kolich_urovnei].text = levelmaker;

                kolich_urovnei++;
            }
        }
        closedir (mydir);
    }
}


