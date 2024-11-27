#ifndef FOOD_H
#define FOOD_H
#include <iostream>

#include "GameMechs.h"
#include "objPos.h"


class Food
{
    private:
        objPos foodPos;
    
    public:
        int xRange;
        int yRange;
        int x;
        int y;
        int posocc;

        Food();
        ~Food();

        void generateFood(objPos blockOff);
        objPos getFoodPos() const;
};

#endif