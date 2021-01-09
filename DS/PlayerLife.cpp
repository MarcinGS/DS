#include "PlayerLife.h"

PlayerLife::PlayerLife()
{
    lifeNum = 3;
}


int PlayerLife::getLifeNum() {
    return lifeNum;
}

void PlayerLife::lostOneLife() {
    if(lifeNum > 0)
        lifeNum--;
}
