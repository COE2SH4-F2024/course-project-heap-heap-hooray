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
        
        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule
        
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        bool isPosEqual(const objPos* refPos) const;
};

#endif