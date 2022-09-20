#include <stdexcept>

#include "innocent.h"

/** Innocent constructor. Calls person constructor  
 * @parameter pos is the initial position. 
 * @parameter type is the type of person. */
Innocent::Innocent(const Position& pos, char type)
: Person::Person(pos, type){}

/** Moves the Innocent based on the pos argument. 
 *  This function overrides in the Guard's pure virtual function
 * @parameter move determines the updated position to move to. Moves: [N, S, E, W, P, C]
 * throws invalid_argument exception if pos is an invalid move */
void Innocent::move(const char move)
{
    switch (move)
    {
    case 'N':
        --pos->y;
        break;
    case 'S':
        ++pos->y;
        break;
    case 'E':
        ++pos->x;
        break;
    case 'W':
        --pos->x;
        break;
    case 'P':
        break;
    case 'C':
        //todo
        break;
    default:
        throw std::invalid_argument("invalid move");
    }
    
}

//g++ innocent.cpp -o innocent.exe
//g++ -c innocent.cpp