#include "FirstBoard.h"
#include <iostream>

FirstBoard::FirstBoard()
{
      static char initialMap[NUM_OF_ROWS][NUM_OF_COLS+1] =
  {
      // Liczby poni¿ej u³atwiaj¹ orientacje w tablicy, uwaga wymiary musz¹ siê zgadzaæ
      //01234567890123456789012345678901234567890123456789012345678901234567890123456789
      "################################################################################",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#       1. Wyswietl liste rekordow                                             #",
      "#                                                                              #",
      "#       2. Graj                                                                #",
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
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "#                                                                              #",
      "################################################################################"
    };

    for(int i = 0; i < 24; ++i){
        strcpy(playBoardMap[i], initialMap[i]);
    }

}

char FirstBoard::selectFromMenu(){

    char select;
    do{
            std::cout << "\nCo wybierasz : ";
            std::cin >> select;
    }
    while(select < 48 || select > 57);
    return select;
}
