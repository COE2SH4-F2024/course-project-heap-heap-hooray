#include "objPos.h"
#include <iostream>
using namespace std;

objPos::objPos()//default constructor
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)//specialized constuctor
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}


objPos& objPos :: operator=(const objPos&m)//copy assignment operator
{       
    if(this!= &m)
    {
        delete pos; //new
        this -> pos = new Pos;

        this->pos->x = m.pos->x;
        this->pos->y = m.pos->y;
        this->symbol = m.symbol;
        
    }
    return *this;

}

objPos :: objPos(const objPos&m)//copy constructor
{
    pos = new Pos;  //new
    
    pos->x = m.pos->x;
    pos->y = m.pos->y;
    symbol = m.symbol;
}

objPos :: ~objPos()
{
    delete pos;
}



void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
