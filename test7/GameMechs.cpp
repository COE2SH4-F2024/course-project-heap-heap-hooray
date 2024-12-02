#include "GameMechs.h"
#include "MacUILib.h"
#include "Food.h"
#include "Player.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 20;
    boardSizeY = 10;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;   
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // nothing on the heap
    // destructor can stay empty for now
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    
void GameMechs::collectAsynchInput(Player *myPlayer, Food *myFood)
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    if(input == ' ')
    {
        setExitTrue();
    }
    else if (input == 'f') // 'f' triggers food regeneration
    {
        if (myFood != nullptr && myPlayer != nullptr) // Ensure valid pointers
        {
            //myFood->generateFood(myPlayer->getPlayerPos());
            //myFood->generateFood(myPlayer->getPlayerPos()->getHeadElement());
            objPos headPos = myPlayer->getPlayerPos()->getHeadElement();

            myFood->generateFood(headPos);

        }
    }


}
char GameMechs::getInput()
{

    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here