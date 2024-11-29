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
//objPos arb1;
//objPos arb2;
//objPos arb3;

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

    /*for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            if (x == 0 || x == 19 || y == 0 || y == 9)
            {
                boardObj.setObjPos(x, y, '#');
            }
            else
            {
                boardObj.setObjPos(x, y, ' ');
            }
        }
    }*/

    boardObj.setObjPos(0,0, '#');

    //arb1.setObjPos(1, 1, 'P');
    //arb2.setObjPos(2, 6, '!');
    //arb3.setObjPos(8, 7, '*');

    myGM = new GameMechs();
    myPlayer = new Player(myGM);
    myFood = new Food();

    myFood->generateFood(myPlayer->getPlayerPos());

}

void GetInput(void)
{
   char input = myGM ->getInput();
   myGM->collectAsynchInput(myPlayer, myFood);
    myGM->collectAsynchInput(myPlayer, myFood);

   //char input = myGM ->getInput();
  // myGM->collectAsynchInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer ->movePlayer();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 

    objPos playerPos = myPlayer -> getPlayerPos();
    objPos foodPos = myFood->getFoodPos();

    int boardX = myGM->getBoardSizeX();
    int boardY = myGM->getBoardSizeY();
    //this isn't actually getting used

    for (int i = 0; i < boardY; i++) {
        for (int j = 0; j < boardX; j++) {
            if (i == 0 || i == boardY - 1 || j == 0 || j == boardX - 1) 
            {
                MacUILib_printf("%c", boardObj.symbol);

            } else if (i == playerPos.pos->y && j == playerPos.pos->x) 
            {
                MacUILib_printf("%c", playerPos.symbol);

            } 
            else if( i == myFood->y && j == myFood->x)
            {
                MacUILib_printf("%c", foodPos.symbol);
            }
            
            /*else if ( i == arb1.getObjPos().pos->y && j == arb1.getObjPos().pos->x)
            {
                MacUILib_printf("%c", arb1.getSymbol());
            }
            else if ( i == arb2.getObjPos().pos->y && j == arb2.getObjPos().pos->x)
            {
                MacUILib_printf("%c", arb2.getSymbol());
            }
            else if ( i == arb3.getObjPos().pos->y && j == arb3.getObjPos().pos->x)
            {
                MacUILib_printf("%c", arb3.getSymbol());
            }*/
            else 
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
    int score = myGM->getScore();
    MacUILib_printf("score: ", score);

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    delete myPlayer;
    delete myFood;

    MacUILib_uninit();

    
}
