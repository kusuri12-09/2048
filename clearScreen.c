//
// Created by user on 25. 5. 30.
//

#include "clearScreen.h"
#include <windows.h>

void clearScreen(void) {
    COORD cursorPosition = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // COORD coordScreen = { 0, 0 };
    // DWORD cCharsWritten;
    // CONSOLE_SCREEN_BUFFER_INFO csbi;
    // DWORD dwConSize;
    //
    // GetConsoleScreenBufferInfo(hConsole, &csbi);
    // dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    //
    // FillConsoleOutputCharacter(hConsole, ' ', dwConSize, coordScreen, &cCharsWritten);
    // FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    // SetConsoleCursorPosition(hConsole, coordScreen);
}

// 몰라서 걍 지피티 돌림