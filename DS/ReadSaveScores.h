#ifndef READSAVESCORES_H
#define READSAVESCORES_H
#include <string>
#include <fstream>

using namespace std;

class ReadSaveScores
{
    public:
        ReadSaveScores(string);
       ~ReadSaveScores();

        void saveToFile(string text);
        void readFromFile(int);


    private:
        const string filename;
        fstream file;
        int recordsCout();

};

#endif // READSAVESCORES_H
