#include "Food.h"
#include "objPos.h"
#include "GameMechs.h"
#include "MacUILib.h"
#include <stdlib.h>
#include <time.h>

Food::Food()
{
    foodPos.setObjPos(-10, -10, 'o');
    xRange = 20;
    yRange = 10;
    // initialize food object outside gameboard
}

Food::~Food()
{
    // nothing for now
}

void Food::generateFood(objPos blockOff)
{
    // you only need to block off the player position for now
    // easier for now, upgrade this in iteration 3

    srand(time(NULL));
    do
    {
        x = rand() % (xRange-2)+1;
        y = rand()% (yRange-2)+1;

        posocc = 0;

        if(blockOff.pos->x == x && blockOff.pos->y)
        {
            posocc = 1;
        }

    } while (posocc);

    foodPos.pos->x = x;
    foodPos.pos->y = y;
    

}

objPos Food::getFoodPos() const
{
    return foodPos;
}