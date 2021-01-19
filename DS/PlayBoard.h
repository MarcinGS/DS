

#ifndef PROJEKT_PPO_PLAYBOARD_H
#define PROJEKT_PPO_PLAYBOARD_H

#include "Point.h"
#include "Console.h"
// Klasa reprezentująca planszę gry. Funkcje publiczne pozwalają na testowanie
// czy na zadanej pozycji planszy są ściany labiryntu (znak #) oraz czy na
// zadanej pozycji jest gotówka (znak $)


class PlayBoard {
public:
    PlayBoard();
    bool isWallOnXY(Point p);
    bool isCashOnXY(Point p);
    void clearSignOnXY(Point p);
    bool isTrapOnXY(Point p);
    bool isGoldOnXY(Point p);
    void show();
    void takeThePoint();
    int getPoints();
protected:
    char playBoardMap[NUM_OF_ROWS][NUM_OF_COLS+1];
private:
    int maxPoints = 0;
};


#endif //PROJEKT_PPO_PLAYBOARD_H
