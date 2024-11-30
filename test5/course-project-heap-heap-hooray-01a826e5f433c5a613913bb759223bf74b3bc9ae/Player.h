#ifndef PLAYER_H
#define PLAYER_H

//#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class GameMechs;

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {up, down, left, right, stop};  // This is the direction state

        Player(GameMechs* thisGMRef);//constructor
        ~Player();//destructor

        objPosArrayList* getPlayerPos() const; // Upgrade this in iteration 3.       
        void updatePlayerDir();
        Dir getDirection() const;   //um i added this for now cus idk how to get direction
        void movePlayer();

        // More methods to be added here

    private:
        //objPos playerPos; // Upgrade this in iteration 3.       
        enum Dir direction;
        objPosArrayList* playerPosList;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif