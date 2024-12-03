#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Food.h"

#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000
#define BOARD_ROWS 10
#define BOARD_COLS 20

Player *myPlayer;   // global pointer meant to instinitate a player object on the heap
objPos boardObj;    
GameMechs *myGM;
Food *myFood;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    boardObj.setObjPos(0,0, '#');
    //call the default constructors 
    myGM = new GameMechs();
    myFood = new Food();
    myPlayer = new Player(myGM, myFood);
    //generate food, making sure its in a different position than the player
    myFood->generateFood(myPlayer->getPlayerPos());

}

void GetInput(void)
{
    char input = myGM ->getInput();
    myGM->collectAsynchInput(myPlayer, myFood);
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer ->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 

    objPosArrayList* playerPos = myPlayer -> getPlayerPos();//use this to hold all the elements in the player
    int playerSize = playerPos->getSize();

    objPos foodPos = myFood->getFoodPos();//use this to hold the position of the food

    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();

    for (int i = 0; i < boardY; i++) {
        for (int j = 0; j < boardX; j++) {
            // we now need to iterate through the playerPos array list to print all the segments out
            bool printed = false;
            for(int k = 0; k < playerSize; k++)
            {
                objPos thisSeg = playerPos->getElement(k);

                if(thisSeg.pos->x == j && thisSeg.pos->y == i)
                {
                    MacUILib_printf("%c", thisSeg.symbol);
                    printed = true;
                    break;
                }

                // check if the current segment x,y pos matches the (j, i) coordinate
                // if yes, print the symbol

                // watch out, we need to skip the if-else block below if we have printed something
                // i.e. use continue
            }

            // at the end of the for loop, do something to determine whether to contune with the if-else or move on to the next iteration of (i-j)
            if(printed)
            {
                continue;
            }

            if (i == 0 || i == boardY - 1 || j == 0 || j == boardX - 1) 
            {
                MacUILib_printf("%c", boardObj.symbol);
            } 
            else if( i == myFood->y && j == myFood->x)
            {
                MacUILib_printf("%c", foodPos.symbol);
            }
            else 
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
    int score = myGM->getScore();
    MacUILib_printf("score: %d", score);

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    //print different messages if the player loses or terminates the game
    if(myGM->getLoseFlagStatus() == true)
    {
        MacUILib_printf("you lose!");
    }
    else
    {
        MacUILib_printf("terminated successfully");
    }


    delete myGM;
    //delete myPlayer;
    delete myFood;
    

    MacUILib_uninit();

    
}
