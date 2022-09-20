#include "roving_guard.h"

/** RovingGuard constructor. Calls Guard constructor with type 'R'
 * @parameter pos is the initial position.*/
RovingGuard::RovingGuard(const Position& pos)
: Guard::Guard(pos, 'R') {}

/** Moves the guard. This function overrides in the Guard's pure virtual function
 *  moves this guard in a random direction.
 * @parameter move determines the  position to move to. Should be a pure virtual function, 
 *            Defaults to 'A' for auto */
void RovingGuard::move(const char move)
{
    srand(time(NULL));
    randomMove();
}

