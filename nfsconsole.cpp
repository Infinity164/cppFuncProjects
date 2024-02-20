

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include "Header.h"

using namespace std;

#define random(a, b) a+rand()%(b+1-a);
#define DEBUG 

enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};
void SetColor(ConsoleColor text, ConsoleColor background)
{
    HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleHandle, text | background);
}
void moveCursor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
char** createField(int width, int height) {
    char** field = new char* [height];
    for (int i = 0; i < height; i++) {
        field[i] = new char[width];
        for (int j = 0; j < width; j++) {
            field[i][j] = char(176);
        }
    }
    return field;
}
void windowSettings(int width, int height) {
    system("color 02");
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD crd = { width, height };
    SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
    SetConsoleWindowInfo(out_handle, true, &src);
    SetConsoleScreenBufferSize(out_handle, crd);

    HWND hWnd;
    HMENU hm;
    if ((hWnd = GetConsoleWindow()) == NULL)
    {
        printf("No console window!?\n");
        return;
    }
    hm = GetSystemMenu(hWnd, FALSE);
    RemoveMenu(hm, SC_SIZE, MF_BYCOMMAND | MF_REMOVE);
    RemoveMenu(hm, SC_MAXIMIZE, MF_BYCOMMAND | MF_REMOVE);
    DrawMenuBar(hWnd);

    HWND window_header = GetConsoleWindow();
    MoveWindow(window_header, 800, 300, width, height, false);
}
void showArray(char** array) {
    int size = _msize(array) / sizeof(array[0]);
    int size2 = _msize(array[0]) / sizeof(array[0][0]);
    for (int i = 0; i < size; i++) {
        moveCursor(5, 5 + i);
        for (int j = 0; j < size2; j++) {
            cout << array[i][j] << array[i][j];
        }
        cout << endl;
    }
}
void showMenu() {
    int counter = 0;
    int keycode = 0;
    while (true) {
        keyboardlisten();
        moveCursor(11, 10);
        if (counter == 0) SetColor(ConsoleColor::Red, ConsoleColor::Black);
        else SetColor(ConsoleColor::Green, ConsoleColor::Black);
        cout << "NEW GAME";

        moveCursor(13, 12);
        if (counter == 1) SetColor(ConsoleColor::Red, ConsoleColor::Black);
        else SetColor(ConsoleColor::Green, ConsoleColor::Black);

        cout << "EXIT";

        int keycode = keyboardlisten();
        switch (keycode) {
        case 119:
            if (counter > 0) counter--;
            break;
        case 115:
            if (counter < 1) counter++;
            break;
        }
    }
}
void render(char** field) {
    moveCursor(13, 2);
    cout << "NFS" << endl;
    cout << endl;
    showMenu();
   
    //showArray(field);
}
int keyboardlisten() {
    if (_kbhit()) {
        moveCursor(13, 25);
        int n = _getch();
        return n;
    }
}

int main()
{   
    windowSettings(30, 20);
    system("mode con cols=30 lines=20");
    srand(time(NULL));
    char** field = createField(9, 12);
    render(field);
    _getch();
    
}