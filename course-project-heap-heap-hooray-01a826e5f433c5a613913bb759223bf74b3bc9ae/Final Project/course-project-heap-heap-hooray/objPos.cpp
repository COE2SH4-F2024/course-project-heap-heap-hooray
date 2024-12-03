#include "objPos.h"
#include <iostream>
using namespace std;

objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL

    //cout << "default func called" << endl;
}

objPos::objPos(int xPos, int yPos, char sym)
{
     /*if(xPos <= 0 || xPos >= 9 || yPos <= 0 || xPos >= 19)
    {
   		throw std::invalid_argument("Invalid coordinate range");
	}

    if(sym == '#')
    {
        throw std::invalid_argument("Invalid symbol selection");
    }*/

    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;

    //cout << "special member func called" << endl;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule

objPos& objPos :: operator=(const objPos&m)
{   
    /*if(xPos <= 0 || xPos >= 9 || yPos <= 0 || xPos >= 19)
    {
   		throw std::invalid_argument("Invalid coordinate range");
	}

    if(sym == '#')
    {
        throw std::invalid_argument("Invalid symbol selection");
    }*/
    
    if(this!= &m)
    {
        delete pos; //new
        this -> pos = new Pos;

        this->pos->x = m.pos->x;
        this->pos->y = m.pos->y;
        this->symbol = m.symbol;
        
    }
    //cout << "copy assigment func called" << endl;
    return *this;

}

objPos :: objPos(const objPos&m)
{
    pos = new Pos;  //new
    
    pos->x = m.pos->x;
    pos->y = m.pos->y;
    symbol = m.symbol;

    //cout << "copy func called" << endl;
}

objPos :: ~objPos()
{
    delete pos;

    //cout << "destroyer func called" << endl;
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
