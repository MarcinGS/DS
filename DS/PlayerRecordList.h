#ifndef PLAYERRECORDLIST_H
#define PLAYERRECORDLIST_H
#include <string>

using namespace std;
class PlayerRecordList
{
    public:
        PlayerRecordList(string name, int score);

    private:
        string name;
        int score;
};

#endif // PLAYERRECORDLIST_H
