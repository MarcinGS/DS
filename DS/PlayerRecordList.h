#ifndef PLAYERRECORDLIST_H
#define PLAYERRECORDLIST_H
#include <string>

using namespace std;
class PlayerRecordList
{
    public:
        PlayerRecordList(string name = "", int score = 0);

        void setName(string name);
        void setScore(int score);
        string getName();
        int getScore();

    private:
        string name;
        int score;
};

#endif // PLAYERRECORDLIST_H
