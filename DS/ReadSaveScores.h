#ifndef READSAVESCORES_H
#define READSAVESCORES_H
#include <string>
#include <fstream>
#include <PlayerRecordList.h>

using namespace std;

class ReadSaveScores
{
    public:
        ReadSaveScores(string);
       ~ReadSaveScores();

        void saveToFile(string name, int score);
        void readFromFile(int);


    private:
        PlayerRecordList playerRecordList;
        const string filename;
        fstream file;
        int recordsCout();
        void bubleSort(PlayerRecordList tab[], int n);
        void printPlayers(PlayerRecordList playersTab[], int numOfTopPlayers, int tabSize);

};

#endif // READSAVESCORES_H
