#ifndef OBJPOS_H
#define OBJPOS_H
#include <iostream>


// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos;        
        char symbol;

        objPos();  //default
        objPos(int xPos, int yPos, char sym);  //specialized
        objPos& operator=(const objPos&m);  //copy assigment 
        objPos(const objPos&m); //copy constructor
        ~objPos();  //destructor
        
        
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        bool isPosEqual(const objPos* refPos) const;
};

#endif