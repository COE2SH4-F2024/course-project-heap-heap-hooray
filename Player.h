#ifndef PLAYER_H
#define PLAYER_H

//#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
//#include "Food.h"

class GameMechs;
class Food;

class Player
{

    
    public:
        enum Dir {up, down, left, right, stop};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* thisFood);//constructor
        ~Player();//destructor

        objPosArrayList* getPlayerPos() const;     
        void updatePlayerDir();
        Dir getDirection() const;   
        void movePlayer();
        bool checkSelfCollision(int index);
        bool checkFoodCollision();

        

    private:     
        enum Dir direction;
        objPosArrayList* playerPosList;

        // Need a reference to the Main Game and food methods
        GameMechs* mainGameMechsRef;
        Food* Foodref;
};

#endif