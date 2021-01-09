#include "ReadSaveScores.h"
#include <iostream>
#include <fstream>


ReadSaveScores::ReadSaveScores(string filename): filename(filename)
{

}

ReadSaveScores::~ReadSaveScores()
{

}

void ReadSaveScores::saveToFile(string text){

   file.open("scores.txt", ios::app);
   if(file)
    file << text+"\n";

    file.close();
}

void ReadSaveScores::readFromFile(int numOfTopPlayers){
    string text;
    int recordsNum = recordsCout();

    string playersRecordsTab[recordsNum];
    file.open(filename, ios::in);

    if(file){
        for(int i = 0; i< (numOfTopPlayers); i++){
            std::getline(file,text,'$');
            std::cout << text;
            std::getline(file,text,'$');
            playersRecordsTab[i] = text;
            std::cout << text;
            }
        }
    file.close();
}

int ReadSaveScores::recordsCout(){

 string text;
 file.open(filename, ios::in);
  int i = 0;
    while(!file.eof()){
        getline(file,text);
        i++;
    }
    file.close();
    return i-1;


}
