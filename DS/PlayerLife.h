#ifndef PLAYERLIFE_H
#define PLAYERLIFE_H


class PlayerLife
{
    public:
        PlayerLife();

        int getLifeNum();
        void lostOneLife();

    private:
        int lifeNum;


};

#endif // PLAYERLIFE_H
