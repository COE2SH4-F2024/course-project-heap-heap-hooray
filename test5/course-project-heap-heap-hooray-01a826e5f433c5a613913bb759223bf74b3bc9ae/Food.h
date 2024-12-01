#ifndef FOOD_H
#define FOOD_H
#include <iostream>

#include "GameMechs.h"
#include "objPos.h"


class Food
{
    private:
        objPosArrayList* foodBucket;
    
    public:
        int xRange;
        int yRange;
        int x;
        int y;
        int posocc;

        Food();
        ~Food();

        void generateFood(objPosArrayList* blockOff);
        objPosArrayList* getFoodPos() const;
};

#endif