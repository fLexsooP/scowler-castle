#include <cstdlib>
#include <ctime>
#include "person.h"
#include "position.h"
#include "guard.h"

#ifndef INDENTURED_GUARD_H
#define INDENTURED_GUARD_H

// should inherit from guard 
class IndenturedGuard : public Guard
{
public:
    /** IndenturedGuard constructor. Calls Guard constructor with type 'I'
     * @parameter pos is the initial position.*/
    IndenturedGuard(const Position& pos);

    /** Moves the guard. This function overrides in the Guard's pure virtual function
     *  has a 15% chance of moving this guard in a random direction.
     * @parameter move determines the  position to move to. Should be a pure virtual function, 
     *            Defaults to 'A' for auto
     */
    void move(const char move = 'A'); 
    
    /** Destructor */
    ~IndenturedGuard(){}
    
protected:

private:
    //int random100();//random for 15% chance move
};

#endif