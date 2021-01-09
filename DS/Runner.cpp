
#include <windows.h>
#include "Runner.h"
#include "Console.h"
#include "PlayBoard.h"




Runner::Runner(int startX, int startY, char startShape)
{
    // Wartości x, y i shape mogłyby być ustawione na liście inicjalizacyjnej.
    // Ale wartości parametrów konstruktora mogły być nieprawidłowe, dlatego
    // są ustawione w ciele konstruktora z wykorzystaniem odpowiednich funkcji
    // ustawiających
    setX(startX);
    setY(startY);
    setShape(startShape);
}

void Runner::setShape(char newShape)
{
    shape = (newShape > 8 && newShape <= 127)
            ? newShape : '*';
}

void Runner::setX(int newX)
{
    // Wykorzystujemy możliwość bezpośredniego dostępu
    // do pola chronionego x klasy Point
    x = isXOnScreen(newX) ? newX : 1;

    // Alternatywnie, gdyby pole x było prywatne:
    // Point::setX(isXOnScreen(newX) ? newX : 1);
    // No, można napisać też jak w przedszkolu:
    // if(isXOnScreen(newX))
    //   Point::setX(newX);
    // else
    //   Point::setX(1);
}

void Runner::setY(int newY)
{
    // Wykorzystujemy możliwość bezpośredniego dostępu
    // do pola chronionego y klasy Point
    y = isYOnScreen(newY) ? newY : 1;
}

void Runner::show()
{
    Console::writeCharXY(x, y, shape);
}

void Runner::hide()
{
    Console::writeCharXY(x, y, ' ');
}

char Runner::getShape()
{
    return shape;
}

void Runner::moveUp()
{
    hide();
    if(y > 1)
        --y;
    show();
}

void Runner::moveDown()
{
    hide();
    if(y < NUM_OF_ROWS)
        ++y;
    show();
}

void Runner::moveLeft()
{
    hide();
    if(x > 1)
        --x;
    show();
}

void Runner::moveRight()
{
    hide();
    if(x < NUM_OF_COLS)
        ++x;
    show();
}

bool Runner::isXOnScreen(int newX)
{
    return (newX > 0 && newX <= NUM_OF_COLS);
}

bool Runner::isYOnScreen(int newY)
{
    return (newY > 0 && newY <= NUM_OF_ROWS);
}
