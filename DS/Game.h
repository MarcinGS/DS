

#ifndef PROJEKT_PPO_GAME_H
#define PROJEKT_PPO_GAME_H

#include "Runner.h"
#include "PlayBoard.h"
#include "PlayerLife.h"
#include "ReadSaveScores.h"
#include "FirstBoard.h"

// Klasa zarządzania grą. Połączona z klasą PlayBoard i Runner związkiem
// kompozycji (całość-część). Klasa realizuje w funkcji run() "aktywne"
// przepytywanie klawiatury. Jeżeli żaden klawisz nie został naciśnięty
// wywoływana jest procedura backgroundProcess(). W tej wersji realizuje
// ona wyświetlanie zegara i aktualizacjê pozycji runner'a oraz kwoty
// zebranej gotówki. Docelowo w tej procedurze można zrealizować animowanie
// ruchomych obiektów gry.
// Każde naciśnięcie klawisza skutkuje jego obsługą (funkcja processKey(int))
// i powrotem do aktywnego przepytywania klawiatury.

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    const int MAX_RECORDS_TO_SHOW = 5;
    Runner runner;
    PlayBoard playBoard;
    PlayerLife playerLife;
    ReadSaveScores readSaveScores;
    FirstBoard firstBoard;
    int cash;
    void backgroundProcess();
    void processKey(int key);
    void updateGameStatus();
    void displayClock();
    void winnerEndGameText();
    void loseEndGameText();
    void saveToList();
};


#endif //PROJEKT_PPO_GAME_H
