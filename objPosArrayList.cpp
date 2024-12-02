#include "objPosArrayList.h"

objPosArrayList::objPosArrayList()//default constructor
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP; 
    aList = new objPos[ARRAY_MAX_CAP]; 
    
}

objPosArrayList::~objPosArrayList()//destructor
{
    for (int i = 0; i < listSize; ++i) {
        aList[i].~objPos();  // Call destructor for each objPos
    }
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    //check if list is already full
    if(listSize == arrayCapacity)
    {
        return; 
    }
    //shift all elements down to make space at the head
    for(int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;
    listSize++;//increase list size when element is inserted
}

void objPosArrayList::insertTail(objPos thisPos)
{
    //check if list is already full
    if(listSize == arrayCapacity)
    {
        return; 
    }
    //no need for shifting elements
    aList[listSize] = thisPos;
    listSize++;//increase list size when element is inserted
}

void objPosArrayList::removeHead()
{
    //check if list is empty
    if(listSize == 0)
    {
        return; 
    }
    //shift every element up one - overwrite head element
    for(int i = 0; i < (listSize-1); i++)
    {
        aList[i] = aList[i+1];
    }
    listSize--;//decrease list size when element is removed
}

void objPosArrayList::removeTail()
{
    //check if list is empty
    if(listSize == 0)
    {
        return; 
    }
    listSize--;//decrease list size to remove tail element
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
{
    if(index<0)
    {
        index = 0;
    }
    else if(index >= listSize)
    {
        index = listSize - 1;
    }

    return aList[index];
}