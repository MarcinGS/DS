#include "PlayerRecordList.h"

PlayerRecordList::PlayerRecordList(string name, int score): name(name), score(score)
{

}

void PlayerRecordList::setName(string name){
    PlayerRecordList::name = name;
}

void PlayerRecordList::setScore(int score){
    PlayerRecordList::score = score;
}

string PlayerRecordList::getName(){
    return name;
}

int PlayerRecordList::getScore(){
    return score;
}
