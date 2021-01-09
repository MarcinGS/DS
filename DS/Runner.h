
#ifndef PROJEKT_PPO_RUNNER_H
#define PROJEKT_PPO_RUNNER_H

#include "Point.h"
#include "Console.h"
// Klasa Runner, dziedziczenie pozycji ekranowej po klasie Point.
// Obiekt klasy Runner będzie zatem posiadał pola X, y oraz dostęp
// do nieprywatnych funkcji składowych. Uwaga -- funkcje ustawiania
// wartości x i y w klasie Point nie kontrolują wartości wstawianych
// do tych pól. W klasie runner dbamy o kontrole, nie pozwalamy ustawić
// wartości nie mieszczących się na ekranie konsoli. Dlatego w tej
// implementacji klasy Runner funkcje skłądowe setX oraz setY zostały
// zdefiniowane ponownie
class Runner : public Point {
public:
    Runner(int startX = 1, int startY = 1, char startShape = '*');
    void setShape(char newShape);
    char getShape();

    // Ponowna definicja funkcji ustawiania pozycji
    void setX(int newX);
    void setY(int newY);

    void show();
    void hide();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

private:
    char shape; // Znak określający wygląd elementu
    // Pomocnicze funkcje weryfikacji pozycji ekranowej
    bool isXOnScreen(int x);
    bool isYOnScreen(int y);
};


#endif //PROJEKT_PPO_RUNNER_H
