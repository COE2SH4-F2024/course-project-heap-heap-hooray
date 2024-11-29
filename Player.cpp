#include "Player.h"
#include "GameMechs.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    direction = stop;

    // more actions to be included

    playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
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
        char input = mainGameMechsRef-> getInput();
        // PPA3 input processing logic 

        switch(input)
        {                      
            case ' ':  // exit
                 mainGameMechsRef->setExitTrue();
                 //exitFlag = 1;
                 //printquit = 1;
                 break;
            case 'W':
            case 'w':
                if (direction == left || direction == right || direction == stop)
                {
                    direction = up;
                    //startCount = 1;
                }
                break;
            case 'A':
            case 'a':
                if (direction == up || direction == down || direction == stop)
                {
                    direction = left;
                    //startCount = 1;
                }
                break;
            case 'S':
            case 's':
                if (direction == left || direction == right || direction == stop )
                {
                    direction = down;
                    //startCount = 1;
                }
                break;
            case 'D':
            case 'd':
                if (direction == up || direction == down || direction == stop)
                {
                    direction = right;
                    //startCount = 1;
                }
                break;
            case 'M':   //THIS IS A DEBUGGING THING THEY WANTED US TO DO
                mainGameMechsRef->incrementScore();
                break;
        }  

        mainGameMechsRef->clearInput();  
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch(direction)
        {
            case up:
                playerPos.pos->y--;
                break;

            case right:
                playerPos.pos->x++;
                break;

            case left:
                playerPos.pos->x--;
                break;

            case down:
                playerPos.pos->y++;
                break;
        }

        if(playerPos.pos->x < 1)
        {
            playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
        }
        else if(playerPos.pos->x > mainGameMechsRef->getBoardSizeX() -1)
        {
            playerPos.pos->x = 1;
        }
        
        if(playerPos.pos->y < 1)
        {
            playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
        }
        else if(playerPos.pos->y > mainGameMechsRef->getBoardSizeY() -1)
        {
            playerPos.pos->y = 1;
        }
}

// More methods to be added

/*Dir Player:: getDirection() const  //i thought i needed this sorry babes
    {
        return direction;
    }*/ 