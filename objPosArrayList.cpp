#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP; 
    aList = new objPos[ARRAY_MAX_CAP]; 
    
}

objPosArrayList::objPosArrayList(int size)
{
    listSize = size;
    arrayCapacity = ARRAY_MAX_CAP; 
    aList = new objPos[size];
    // for(int i = 0; i < size; i++)
    // {
    //     aList[i] = new objPos();
    // }
}

objPosArrayList::objPosArrayList(const objPosArrayList& other)
    : listSize(other.listSize), arrayCapacity(other.arrayCapacity)
{
    aList = new objPos[arrayCapacity];  // Allocate new array
    for (int i = 0; i < listSize; ++i) {
        aList[i] = other.aList[i];  // Deep copy each element
    }
}

objPosArrayList& objPosArrayList::operator=(const objPosArrayList& other)
{
    if (this != &other) {  // Protect against self-assignment
        delete[] aList;  // Delete existing array
        aList = nullptr;

        arrayCapacity = other.arrayCapacity;
        listSize = other.listSize;
        aList = new objPos[arrayCapacity];  // Allocate new memory

        for (int i = 0; i < listSize; ++i) {
            aList[i] = other.aList[i];  // Deep copy elements
        }
    }
    return *this;
}


// objPosArrayList::objPosArrayList(const objPosArrayList& other)
//     : listSize(other.listSize), arrayCapacity(other.arrayCapacity) {
//     aList = new objPos[arrayCapacity];
//     for (int i = 0; i < listSize; i++) {
//         aList[i] = other.aList[i]; // This calls objPos's copy constructor
//     }
// }

// objPosArrayList& objPosArrayList::operator=(const objPosArrayList& other) {
//     if (this != &other) {
//         delete[] aList;
//         listSize = other.listSize;
//         arrayCapacity = other.arrayCapacity;
//         aList = new objPos[arrayCapacity];
//         for (int i = 0; i < listSize; i++) {
//             aList[i] = other.aList[i]; // Calls objPos's copy constructor
//         }
//     }
//     return *this;
// }


objPosArrayList::~objPosArrayList()
{
    for (int i = 0; i < listSize; ++i) {
        aList[i].~objPos();  // Call destructor for each objPos
    }
    delete[] aList; 
    aList = nullptr;
    //delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        return; //not sure if we need something else here
    }
    //shift all elements down to make space at the head
    for(int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        return; //not sure if we need something else here
    }
    aList[listSize] = thisPos;
    listSize++;
    
}
void objPosArrayList::insertTailFood(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        return; //not sure if we need something else here
    }
    aList[listSize] = thisPos;
    
}

void objPosArrayList::removeHead()
{
    if(listSize == 0)
    {
        return; 
    }
    for(int i = 0; i < (listSize-1); i++)
    {
        aList[i] = aList[i+1];
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    if(listSize == 0)
    {
        return; 
    }
    listSize--;
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
void objPosArrayList::setElement(objPos value, int index)
{
    if(index < listSize)
    {
        aList[index] = value;
    }
}