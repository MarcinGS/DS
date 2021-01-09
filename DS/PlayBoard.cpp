

#include "PlayBoard.h"
#include "Console.h"
#include <cstring>


PlayBoard::PlayBoard()
{
    // Drobna sztuczka: ze wzglêdu na problemy zwi¹zane z inicjalizacj¹ tablicowych
    // pól klasy (do wersji C++11), pole playBoardMap bêd¹ce tablic¹ dwuwymiarow¹
    // jest inicjowane w konstruktorze zawartoœci¹ statycznej tablicy initialMap.
    // Tê ostatni¹ można dowolnie edytowaæ ustalaj¹c zawartoœæ planszy.
     static char initialMap[NUM_OF_ROWS][NUM_OF_COLS+1] =
  {
      // Liczby poniżej ułatwiają orientacje w tablicy, uwaga wymiary muszą się zgadzać
      //01234567890123456789012345678901234567890123456789012345678901234567890123456789
      "################################################################################",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                               $$$                                            #",
      "#                               GGG                                            #",
      "#                                 +                                            #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "################################################################################"
    };
    // Kopiowane kolejnych wierszy z mapy statycznej do playBoardMap
    for(int i = 0; i < 24; ++i){
        strcpy(playBoardMap[i], initialMap[i]);
    }

    for(int i = 0; i < NUM_OF_ROWS; i++){
        for(int j = 0; j< NUM_OF_COLS; j++){
            if(playBoardMap[i][j]== '$'||playBoardMap[i][j]== 'G')
            maxPoints++;
        }
    }
}

void PlayBoard::show()
{
    for(int i = 0; i < 24; ++i)
        Console::writeStrXY(1, i + 1, playBoardMap[i]);
}

bool PlayBoard::isWallOnXY(Point p)
{
    // Pozycja ekranowa liczona jest od 1, indeksy w tablicy od 0
    return playBoardMap[p.getY() - 1][p.getX() - 1] == '#';
}

bool PlayBoard::isCashOnXY(Point p)
{
    // Pozycja ekranowa liczona jest od 1, indeksy w tablicy od 0
    return playBoardMap[p.getY() - 1][p.getX() - 1] == '$';
}

void PlayBoard::clearSignOnXY(Point p)
{
    // Pozycja ekranowa liczona jest od 1, indeksy w tablicy od 0
    playBoardMap[p.getY() - 1][p.getX() - 1] = ' ';
}

bool PlayBoard::isTrapOnXY(Point p){
	return playBoardMap[p.getY() - 1][p.getX() - 1] == '+';
}

bool PlayBoard::isGoldOnXY(Point p){
	return playBoardMap[p.getY() - 1][p.getX() - 1] == 'G';
}

void PlayBoard::takeThePoint(){
    maxPoints--;
}

int PlayBoard::getPoints(){
    return maxPoints;
}
