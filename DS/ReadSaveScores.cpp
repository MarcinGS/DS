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

void ReadSaveScores::readFromFile(int numOfTopPlayers){
    int tabSize = recordsCout();

    fstream file("scores.dat", ios::in|ios::binary);

    PlayerRecordList playersTab[tabSize];

    //Wczytuje zapisanych graczy do tablicy
    if(file){
        int i = 0;
        while(file.read(reinterpret_cast<char*>(&playerRecordList), sizeof(playerRecordList))){
             playersTab[i].setName(playerRecordList.getName());
             playersTab[i].setScore(playerRecordList.getScore());
             i++;
        }
//TODO wczytuje do tablicy i sortuje teraz oczyscic i zabezpieczyc przed mniejsza i wieksza liczba rekordow/zapisow oraz aby wyswietlalo tylko 5 rekordow
         for(int i = 0; i < tabSize; i++){
            cout << playersTab[i].getName() << " " << playersTab[i].getScore() << endl;
        }
        cout << endl;
        bubleSort(playersTab, tabSize);

        for(int i = 0; i < tabSize; i++){
            cout << playersTab[i].getName() << " " << playersTab[i].getScore() << endl;
        }
    }

    file.close();
}

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
		for(int j=1; j<n-i ;j++) //pêtla wewnêtrzna
		if(tab[j-1].getScore() > tab[j].getScore())
			//zamiana miejscami
			swap(tab[j-1], tab[j]);
}
