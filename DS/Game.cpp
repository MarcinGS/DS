#include <iostream>
#include <stdio.h>
#include <string>
#include "Game.h"
#include "Console.h"
#include "ReadSaveScores.h"



Game::Game() : runner(40, 12, '*'), playBoard(), cash(0), playerLife(), readSaveScores("scores.txt")
{
    Console::clearScreen();
    Console::cursorOff();
}

Game::~Game()
{
    Console::clearScreen();
    Console::cursorOn();
}

void Game::updateGameStatus()
{
    char info[128];
    // Przygotowanie ³añcucha znaków z informacjami i wyœwietlenie
    sprintf(info, "X=%-2d Y=%-2d", runner.getX(), runner.getY());
    Console::writeStrXY(1, 25, info);
    // Przygotowanie ³añcucha znaków z informacjami i wyœwietlenie
    sprintf(info, "Gotowka=%-4d", cash);
    Console::writeStrXY(20, 25, info);

    sprintf(info, "Life=%d", playerLife.getLifeNum());
    Console::writeStrXY(35, 25, info);
}

void Game::displayClock()
{
    char info[128];

    time_t t = time(NULL); // Pobranie aktualnego czasu
    struct tm *ptm = localtime(&t); // "Rozpakowanie" informacji o czasie

    // Przygotowanie ³añcucha znaków z informacjami o czasie i wyœwietlenie
    sprintf( info, "%02d:%02d:%02d", ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
    Console::writeStrXY(72, 25, info);
}

void Game::backgroundProcess()
{
    updateGameStatus();
    displayClock();
}

void Game::processKey(int key)
{
    // Zapamietujemy aktualn¹ pozycjê runner'a
    Point newPos = runner;
    switch(key)
    {
        case KEY_UP:    // Przewidywana nowa pozycja
            newPos.setY(runner.getY()-1);
            // Czy mo¿na siê przemieœciæ na tê pozycjê?
            if(!playBoard.isWallOnXY(newPos))
                runner.moveUp();
            break;
        case KEY_DOWN:  newPos.setY(runner.getY()+1);
            if(!playBoard.isWallOnXY(newPos))
                runner.moveDown();
            break;
        case KEY_LEFT:  newPos.setX(runner.getX()-1);
            if(!playBoard.isWallOnXY(newPos))
                runner.moveLeft();
            break;
        case KEY_RIGHT: newPos.setX(runner.getX()+1);
            if(!playBoard.isWallOnXY(newPos))
                runner.moveRight();
            break;
    }
    // Zebranie gotówki z nowej pozycji, o ile na niej jest
    if(playBoard.isCashOnXY(runner))
    {
        cash += 1;
        playBoard.takeThePoint();
        playBoard.clearSignOnXY(runner);
    }
    if(playBoard.isTrapOnXY(runner)){
    	playerLife.lostOneLife();
    	runner.setX(40);
    	runner.setY(12);
    	playBoard.show();
    	updateGameStatus();
    	runner.show();
	}
    if(playBoard.isGoldOnXY(runner)){
        cash += 5;
        playBoard.takeThePoint();
        playBoard.clearSignOnXY(runner);
    }
}

void Game::run()
{
    int key = 0;
    char select;

    firstBoard.show();
    select = firstBoard.selectFromMenu();
    system("cls");
    if(select == '1'){
        readSaveScores.readFromFile(MAX_RECORDS_TO_SHOW);
        cout << "\n";
        system("pause");
    }
    system("cls");
    playBoard.show();
    runner.show();

    // Aktywne przepytywanie klawiatury. Rezultatem funkcji _kbhit()
    // jest true je¿eli w buforze klawiatury oczekuje nieodczytany znak
    do
    {
        if(!_kbhit())
            backgroundProcess();
        else{
            processKey(key = Console::getKey());
            if(playBoard.getPoints() == 0){
                winnerEndGameText();
                saveToList();
                key = KEY_ESC;
            }
            else if(playerLife.getLifeNum() == 0){
            	loseEndGameText();
            	saveToList();
            	key = KEY_ESC;
			}
        }
    }
    while(key != KEY_ESC);
}

 void Game::winnerEndGameText(){
     system("cls");
     std::cout << "\nKoniec Gry!!!\nWygrales!!!" << std::endl;
     system("pause");
 }

 void Game::loseEndGameText(){
     system("cls");
     std::cout << "\nKoniec Gry!!!\nPrzegrales!!!" << std::endl;
     system("pause");
 }

 void Game::saveToList(){
    system("cls");
    std::string name;
    std::cout << "Podaj swoje imie: " << std::endl;
    std::cin >> name;

    readSaveScores.saveToFile(name,cash);
 }
