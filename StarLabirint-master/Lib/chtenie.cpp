#include "TXLib.h"
#include <iostream>
#include <string> // подключаем строки
#include <fstream>

using namespace std;

int main()
    {
    txCreateWindow (1280, 720);

    ifstream file("Files\\2.txt"); // файл из которого читаем (для линукс путь будет выглядеть по другому)

    string stroka_golovy, stroka_tela;
    getline(file, stroka_golovy);
    x_bashki = {atoi(stroka_golovy.c_str())};
    getline(file, stroka_tela);
    x_tela = {atoi(stroka_tela.c_str())};
    file.close();
    }
