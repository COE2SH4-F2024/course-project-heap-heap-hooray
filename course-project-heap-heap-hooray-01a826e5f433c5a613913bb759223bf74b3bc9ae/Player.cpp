#include "Player.h"
#include "GameMechs.h"  


Player::Player(GameMechs* thisGMRef, Food* thisFood)//default constructor
{
    mainGameMechsRef = thisGMRef; //use this to access GameMechs methods
    Foodref = thisFood; //use this to access Food methods

    playerPosList = new objPosArrayList(); //allocate heap space for snake list
    direction = stop;//initialize direction enumeration to stop

    objPos headPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '@');
    //^^initialize snake to begin at center of board

    playerPosList->insertHead(headPos);//insert object into the snake list
}


Player::~Player()//destructor
{
    delete playerPosList;
}


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
                 break;
            case 'W':
            case 'w':
                if (direction == left || direction == right || direction == stop)
                {
                    direction = up;
                }
                break;
            case 'A':
            case 'a':
                if (direction == up || direction == down || direction == stop)
                {
                    direction = left;
                }
                break;
            case 'S':
            case 's':
                if (direction == left || direction == right || direction == stop )
                {
                    direction = down;
                }
                break;
            case 'D':
            case 'd':
                if (direction == up || direction == down || direction == stop)
                {
                    direction = right;
                }
                break;
            default:
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
            default:
                break;
        }
        //wraparound logic
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

        objPos foo = Foodref->getFoodPos();//use this to hold the position of the food

        for(int n = 1; n < playerPosList->getSize(); n++)//iterate through the snake list to make sure there is no self collision
        {
            if(playerPosList->getSize()>1)//only begin this check when the snake list holds more than 1 element
            {
                if(checkSelfCollision(n))
                {
                    //if the snake collides with itself set the exitflag to true and display lose message
                    mainGameMechsRef->setLoseFlag();
                    mainGameMechsRef->setExitTrue();
                    break;
                }
            }

        }
        
    

        if(checkFoodCollision())
        {
            //if snake has collided with food, add element to head, DO NOT remove tail, generate new food item
            playerPosList->insertHead(temp);
            Foodref->generateFood(playerPosList);
            mainGameMechsRef->incrementScore();
        }
        else
        {
            //when snake doesn't collide with food, add element to head and remove tail
            playerPosList->insertHead(temp);
            playerPosList->removeTail();
        } 
}

// More methods to be added

bool Player::checkFoodCollision()
{
    objPos temp = playerPosList->getHeadElement();//use this to hold the element at the head of the snake
    objPos foo = Foodref->getFoodPos();

    bool collided = temp.isPosEqual(&foo);//if head element and food have the same position, set collided to true
    return collided;
}

bool Player::checkSelfCollision(int index)
{
    objPos temp = playerPosList->getHeadElement();//use this to hold the element at the head of the snake
    objPos element = playerPosList->getElement(index);//use this to hold the snake element at a specific index

    bool collided = temp.isPosEqual(&element);//if head element and body elent have the same position, set collided to true
    return collided;
}
