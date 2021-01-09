
#include "Console.h"
int Console::getKey()
{
    int key = _getch();
    return (key == KEY_BLANK) ? _getch() << 8 : key;
}

void Console::clearScreen()
{
#ifdef __BORLANDC__
    clrscr();
#elif (defined(__GNUC__) && defined(__MINGW32__)) || defined(_MSC_VER)
    COORD leftTop = { 0, 0 };
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    int numOfCells = 80 * 25;
    DWORD writtenItems;
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo))
        numOfCells = consoleInfo.dwSize.X * consoleInfo.dwSize.Y;

    FillConsoleOutputAttribute(consoleHandle, 0xf,
                               numOfCells, leftTop, &writtenItems);
    FillConsoleOutputCharacter(consoleHandle, ' ',
                               numOfCells, leftTop, &writtenItems);
#else
#error "Nieobslugiwana platforma"
#endif
}

void Console::writeCharXY(int x, int y, char c) {
#ifdef __BORLANDC__
    gotoxy(x, y);
	putch(c);
#elif (defined(__GNUC__) && defined(__MINGW32__)) || defined(_MSC_VER)
    COORD cursorPos;
    DWORD written;

    cursorPos.X = x - 1;
    cursorPos.Y = y - 1;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), &c, 1, &written, 0);
#else
#error "Nieobslugiwana platforma"
#endif
}

void Console::writeStrXY(int x, int y, char s[])
{
#ifdef __BORLANDC__
    gotoxy(x, y);
	cputs(s);
#elif (defined(__GNUC__) && defined(__MINGW32__)) || defined(_MSC_VER)
    COORD cursorPos;
    DWORD written;

    cursorPos.X = x - 1;
    cursorPos.Y = y - 1;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), s, strlen(s), &written, 0);
#else
#error "Nieobslugiwana platforma"
#endif
}

void Console::writeIntXY(int x, int y, int i)
{
    char s[80];
#if defined(_MSC_VER)
    sprintf_s(s, 80, "%d", i);
#else
    sprintf(s, "%d", i);
#endif
    writeStrXY(x, y, s);
}

void Console::writeDoubleXY(int x, int y, double d)
{
    char s[80];
#if defined(_MSC_VER)
    sprintf_s(s, 80, "%g", d);
#else
    sprintf(s, "%g", d);
#endif
    writeStrXY(x, y, s);
}

void Console::cursorOff()
{
#ifdef __BORLANDC__
    _setcursortype(_NOCURSOR);
#elif (defined(__GNUC__) && defined(__MINGW32__)) || defined(_MSC_VER)
    CONSOLE_CURSOR_INFO cursorInfo;
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
#else
#error "Nieobslugiwana platforma"
#endif
}

void Console::cursorOn()
{
#ifdef __BORLANDC__
    _setcursortype(_NORMALCURSOR);
#elif (defined(__GNUC__) && defined(__MINGW32__)) || defined(_MSC_VER)
    CONSOLE_CURSOR_INFO cursorInfo;
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
#else
#error "Nieobslugiwana platforma"
#endif
}