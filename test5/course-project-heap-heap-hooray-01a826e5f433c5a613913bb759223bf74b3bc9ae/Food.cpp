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

void Food::generateFood(objPosArrayList* blockOff)
{
    // you only need to block off the player position for now
    // easier for now, upgrade this in iteration 3

    srand(time(NULL));
    do
    {
        x = rand() % (xRange-2)+1;
        y = rand()% (yRange-2)+1;

        posocc = 0;
        for(int i = 0; i < blockOff->getSize(); i++)
        {
            objPos list = blockOff->getElement(i);

            if(list.pos->x == x && list.pos->y)
            {
                posocc = 1;
            }

        }

    } while (posocc);

    foodPos.pos->x = x;
    foodPos.pos->y = y;
    

}

objPos Food::getFoodPos() const
{
    return foodPos;
}