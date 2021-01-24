#include "ReadSaveScores.h"
#include <iostream>
#include <fstream>


ReadSaveScores::ReadSaveScores(string filename): filename(filename)
{

}

ReadSaveScores::~ReadSaveScores()
{

}

void ReadSaveScores::saveToFile(string name, int score){
    playerRecordList.setName(name);
    playerRecordList.setScore(score);
    fstream file("scores.dat", ios::out|ios::app|ios::binary);
    if(file)
        file.write(reinterpret_cast<char*>(&playerRecordList), sizeof(playerRecordList));
    file.close();
}

//Wczytuje dane z pliku
void ReadSaveScores::readFromFile(int numOfTopPlayers){
    int tabSize = recordsCout();

    fstream file("scores.dat", ios::in|ios::binary);

    PlayerRecordList playersTab[tabSize]; //tablica graczy dla operacji sortowania

    //Wczytuje zapisanych graczy do tablicy
    if(file){
        int i = 0;
        while(file.read(reinterpret_cast<char*>(&playerRecordList), sizeof(playerRecordList))){
             playersTab[i].setName(playerRecordList.getName());
             playersTab[i].setScore(playerRecordList.getScore());
             i++;
        }

        bubleSort(playersTab, tabSize);
        printPlayers(playersTab, numOfTopPlayers, tabSize);

    file.close();
    }
}

//Liczy i zwraca ilosc wpisow w pliku (wszystkich)
 int ReadSaveScores::recordsCout(){
    int i = 0;
    fstream file("scores.dat", ios::in|ios::binary);

    if(file){
        while(file.read(reinterpret_cast<char*>(&playerRecordList), sizeof(playerRecordList))){
            i++;
        }
    }
    file.close();
    return i;
 }

 void ReadSaveScores::bubleSort(PlayerRecordList tab[], int n)
{
	for(int i = 0; i < n; i++)
		for(int j=1; j<n-i ;j++)
		if(tab[j-1].getScore() < tab[j].getScore())
			swap(tab[j-1], tab[j]);
}

//Wyœwietla wyniki graczy
void ReadSaveScores::printPlayers(PlayerRecordList playersTab[], int numOfTopPlayers, int tabSize){
     if(tabSize < numOfTopPlayers){     //je¿eli na liscie jest mniej graczy ni¿ 5(numOfTopPlayers) zabezpieczenie przed wyjsciem poza tablice.
              for(int i = 0; i < tabSize; i++)
            cout << i+1 <<". " << playersTab[i].getName() << " " << playersTab[i].getScore() << endl;
        }
        else{
            for(int i = 0; i < numOfTopPlayers; i++)
            cout << i+1 <<". " << playersTab[i].getName() << " " << playersTab[i].getScore() << endl;
       }
}
