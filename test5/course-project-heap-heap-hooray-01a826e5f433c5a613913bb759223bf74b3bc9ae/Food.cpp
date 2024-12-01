#include "Food.h"
#include "objPos.h"
#include "GameMechs.h"
#include "MacUILib.h"
#include <stdlib.h>
#include <time.h>

Food::Food()
{   
    foodBucket = new objPosArrayList(5);

    // for(int i = 0; i < foodBucket->getSize(); i++)
    // {
    //     objPos elem = foodBucket->getElement(i);
    //     if(i == 3)
    //     {
    //         elem.setObjPos(-10, -10, '$');
    //         xRange = 20;
    //         yRange = 10;
    //     }

    //     if(i == 4)
    //     {
    //         elem.setObjPos(-10, -10, '?');
    //         xRange = 20;
    //         yRange = 10;
    //     }
    //     elem.setObjPos(-10, -10, 'o');
    //     xRange = 20;
    //     yRange = 10;
    // }

    for (int i = 0; i < 5; i++) // Assuming 5 food objects
    {
        objPos elem; // Create a new objPos instance
        if (i == 3)
        {
            elem.setObjPos(-10, -10, '$');
        }
        else if (i == 4)
        {
            elem.setObjPos(-10, -10, '?');
        }
        else
        {
            elem.setObjPos(-10, -10, 'o');
        }
        foodBucket->insertTail(elem); // Add to the foodBucket
    }
    xRange = 20; 
    yRange = 10;


    // foodPos.setObjPos(-10, -10, 'o');
    // xRange = 20;
    // yRange = 10;
    // initialize food object outside gameboard
}

Food::~Food()
{
    delete foodBucket;
    foodBucket = nullptr;
    // nothing for now
}

void Food::generateFood(objPosArrayList* blockOff)
{
    // you only need to block off the player position for now
    // easier for now, upgrade this in iteration 3

    srand(time(NULL));

    for(int j = 0; j < foodBucket->getSize(); j++)
    {
        do
        {


            x = rand() % (xRange-2)+1;
            y = rand() % (yRange-2)+1;

            posocc = 0;
            for(int i = 0; i < blockOff->getSize(); i++)
            {
                objPos list = blockOff->getElement(i);

                if(list.pos->x == x && list.pos->y == y)
                {
                    posocc = 1;
                    break;
                }

            }
            printf("xrange = %d, yrange = %d", x, y);

        } while (posocc);

        // objPos newFoodPos;
        // newFoodPos.setObjPos(x, y, foodBucket->getElement(j).symbol);
        // foodBucket->insertTail(newFoodPos);
        //foodBucket->getElement(j).setObjPos(x,y,foodBucket->getElement(j).symbol);
        
        foodBucket->getElement(j).pos->x = x;
        foodBucket->getElement(j).pos->y = y;
        printf("outside  xy xrange = %d, yrange = %d", foodBucket->getElement(j).pos->x, foodBucket->getElement(j).pos->y);

    }

   
}

objPosArrayList* Food::getFoodPos() const
{
    return foodBucket;
}