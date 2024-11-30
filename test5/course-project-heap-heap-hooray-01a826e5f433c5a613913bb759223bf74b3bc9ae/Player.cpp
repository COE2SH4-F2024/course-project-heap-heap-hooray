#include "Player.h"
#include "GameMechs.h"  


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    playerPosList = new objPosArrayList();
    direction = stop;

    objPos headPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '@');

    playerPosList->insertHead(headPos);

    //following is just for test
    objPos test1(headPos.pos->x-1, headPos.pos->y-1, '@');
    playerPosList->insertTail(test1);

    objPos test2(headPos.pos->x-2, headPos.pos->y-2, '@');
    playerPosList->insertTail(test2);

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
    // create a temporary objPos to calculate tthe new head position
    // probably should get the head element of the playerPosList 
    // good astarting point

    objPos temp = playerPosList->getHeadElement();

    switch(direction)
        {
            // calculate the new position of the head
            // using the temp objPos
            case up:
                temp.pos->y--;
                break;

            case right:
                temp.pos->x++;
                break;

            case left:
                temp.pos->x--;
                break;

            case down:
                temp.pos->y++;
                break;
        }

        if(temp.pos->x < 1)
        {
            temp.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
        }
        else if(temp.pos->x > mainGameMechsRef->getBoardSizeX() -2)
        {
            temp.pos->x = 1;
        }
        
        if(temp.pos->y < 1)
        {
            temp.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
        }
        else if(temp.pos->y > mainGameMechsRef->getBoardSizeY() -2)
        {
            temp.pos->y = 1;
        }

        // insert temp objPos to the head of the list

        playerPosList->insertHead(temp);
        playerPosList->removeTail();

        // FEATURE TWO: CHECK IF THE NEW TEMP OBJPOS OVERLAPS THE FOOD POS (GET IT FROM THE GAMEMECHS CLASS)
        // FEATURE TWO: USE ISPOSEQUAL() METHOD FROM OBJPOS CLASS
        // FEATURE TWO: IF OVERLAPP, FOOD CONSUMED, DO NOT REMOVE SNAKE TAIL
        // TAKE THE RESPECTIVE ACTIONS TO INCREASE THE STORE
        // IF NO OVERLAP REMOVE TAIL, COMPLETE MOVEMENT

        // if(playerPosList->getHeadElement().pos->x < 1)
        // {
        //     // playerPosList->removeHead();
        //     // playerPosList->insertHead(position)

        //     // for(int i = 0; i < playerPosList->getSize(); i++)
        //     // {
        //     //     objPos elem = playerPosList->getElement(i);
        //     //     elem.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
        //     // }
        // }


    //     if (temp.pos->x < 0) {
    //     temp.pos->x = mainGameMechsRef->getBoardSizeX() - 1;
    // } else if (temp.pos->x >= mainGameMechsRef->getBoardSizeX()) {
    //     temp.pos->x = 0;
    // }

    // if (temp.pos->y < 0) {
    //     temp.pos->y = mainGameMechsRef->getBoardSizeY() - 1;
    // } else if (temp.pos->y >= mainGameMechsRef->getBoardSizeY()) {
    //     temp.pos->y = 0;
    // }

        

}

// More methods to be added

/*Dir Player:: getDirection() const  //i thought i needed this sorry babes   <3
    {
        return direction;
    }*/ 