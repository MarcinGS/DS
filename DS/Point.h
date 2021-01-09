
// Klasa reprezentacji informacji o położeniu punktu
// w przestrzeni 2D, bez żadnych ograniczeń w sensie
// wartości współrzędnych
#ifndef PROJEKT_PPO_POINT_H
#define PROJEKT_PPO_POINT_H


class Point {
public:
    Point(int startX = 0, int startY = 0);
    void setX(int newX);
    void setY(int newY);
    int  getX();
    int  getY();
protected:
    int  x, y;
};


#endif //PROJEKT_PPO_POINT_H
