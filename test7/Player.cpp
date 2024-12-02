#include "Player.h"
#include "GameMechs.h"  
#include "objPos.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    playerPosList = new objPosArrayList();
    direction = stop;

    objPos headPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'@');
    playerPosList->insertHead(headPos);
    // more actions to be included

    // playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    // playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
    // playerPos.symbol = '@';

    //cout << "here" << endl;

}


Player::~Player()
{
    // delete any heap members here
    // no keyword new in the constructor
    // leave the destructor empty FOR NOW
    delete playerPosList;
}

/*void Player::getPlayerPos(objPos &returnPos) const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}*/

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList;
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
    //Iteration 3: create a temporary objPos to calculate the new head position
    //probably should get the head element of the playerPosList as a starting point
    objPos temp;
    temp = playerPosList->getHeadElement();//temp holds the element at the head of the snake...should this be the 

    switch(direction)
        {
            //calculate new position of the head using the temp objPos
            case up:
                //playerPos.pos->y--;
                temp.pos->y--;  //is this legal??
                break;

            case right:
                //playerPos.pos->x++;
                temp.pos->x++;
                break;

            case left:
                //playerPos.pos->x--;
                temp.pos->x--;
                break;

            case down:
                //playerPos.pos->y++;
                temp.pos->y++;
                break;
        }
        //insert temp objPos to the head of the list
        playerPosList->insertHead(temp);
        //***check if the new temp objPos overlaps with food pos (get from GameMechs class)
        //if(temp.isPosEqual()) //Ahhh helppp
        
        //use isPosEqual method from objPos class to check overlap
        //if overlapped, food consumed, do not remove snake tail, increase the score

        //if no overlap, remove tail, complete movement.


        //Chen doesn't have this block in his tutorial vid, is this the wraparound logic?
        /*if(playerPos.pos->x < 1)
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
        }*/
}

// More methods to be added

/*Dir Player:: getDirection() const  //i thought i needed this sorry babes   <3
    {
        return direction;
    }*/ 