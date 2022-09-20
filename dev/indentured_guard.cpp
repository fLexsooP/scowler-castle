#include "indentured_guard.h"

/** IndenturedGuard constructor. Calls Guard constructor with type 'I'
 * @parameter pos is the initial position.*/
IndenturedGuard::IndenturedGuard(const Position& pos)
: Guard::Guard(pos, 'I') {}

/** Moves the guard. This function overrides in the Guard's pure virtual function
 *  has a 15% chance of moving this guard in a random direction.
 * @parameter move determines the  position to move to. Should be a pure virtual function, 
 *            Defaults to 'A' for auto
 */
void IndenturedGuard::move(const char move)
{
    srand(time(NULL));
    if(random() < 15)//15% chance move
    {
        randomMove();
    }
}

// int IndenturedGuard::random100()
// {
//     srand(time(NULL));
//     return rand() % 100;
// }

