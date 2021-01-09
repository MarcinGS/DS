
#ifndef PROJEKT_PPO_CONSOLE_H
#define PROJEKT_PPO_CONSOLE_H

#include <cstring>
#include <cstdio>
#include <ctime>
#include <conio.h>

#if defined(__MINGW32__) || defined(_MSC_VER)
#include <windows.h>
#endif

// Kody klawiszy sterujących kursorem i klawiszy specjalnych
enum KEY_CODES
{
#ifdef __BORLANDC__
    KEY_BLANK = 0x0000,
#elif (defined(__GNUC__) && defined(__MINGW32__)) || defined(_MSC_VER)
    KEY_BLANK = 0x00e0,
#endif
    KEY_UP = 0x4800,
    KEY_DOWN = 0x5000,
    KEY_LEFT = 0x4b00,
    KEY_RIGHT = 0x4d00,
    KEY_ESC = 0x001b
};


// Rozmiary ekranu konsoli, nie uwzględniają ostatniego wiersza
// ten jest wierszem statusu i zawiera informacje o stanie gry
const int NUM_OF_COLS = 80;
const int NUM_OF_ROWS = 24;

class Console {
public:
    static int getKey();
    static void clearScreen();
    static void writeCharXY(int x, int y, char c);
    static void writeStrXY(int x, int y, char s[]);
    void writeIntXY(int x, int y, int i);
    void writeDoubleXY(int x, int y, double d);
    static void cursorOff();
    static void cursorOn();
};


#endif //PROJEKT_PPO_CONSOLE_H
