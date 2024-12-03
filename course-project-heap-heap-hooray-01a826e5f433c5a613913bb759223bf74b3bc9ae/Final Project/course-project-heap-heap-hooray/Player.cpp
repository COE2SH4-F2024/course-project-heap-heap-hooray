#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    direction = stop;

    // more actions to be included

    playerPos.pos->x = 10;
    playerPos.pos->y = 5;
    playerPos.symbol = '@';

    //cout << "here" << endl;

}


Player::~Player()
{
    // delete any heap members here
    // no keyword new in the constructor
    // leave the destructor empty FOR NOW
}

/*void Player::getPlayerPos(objPos &returnPos) const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}*/

objPos Player::getPlayerPos() const
{
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic  
        switch(input)
        {                      
            // case ' ':  // exit
            //     exitFlag = 1;
            //     printquit = 1;
            //     break;
            case 'w':
                if (direction == left || direction == right || direction == stop)
                {
                    direction = up;
                    //startCount = 1;
                }
                break;
            case 'a':
                if (direction == up || direction == down || direction == stop)
                {
                    direction = left;
                    //startCount = 1;
                }
                break;
            case 's':
                if (direction == left || direction == right || direction == stop )
                {
                    direction = down;
                    //startCount = 1;
                }
                break;
            case 'd':
                if (direction == up || direction == down || direction == stop)
                {
                    direction = right;
                    //startCount = 1;
                }
                break;
        }        
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

// More methods to be added