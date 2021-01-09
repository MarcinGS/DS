

#include "Point.h"

Point::Point(int startX, int startY) : x(startX), y(startY)
{
}

void Point::setX(int newX)
{
    x = newX;
}

void Point::setY(int newY)
{
    y = newY;
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}
