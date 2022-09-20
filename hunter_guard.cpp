#include "hunter_guard.h"

/** HunterGuard constructor. Calls Guard constructor with type 'H'
 * @parameter pos is the initial position.
 * @parameter hero is a pointer to the hero object in the castle */
HunterGuard::HunterGuard(const Position& pos, const Innocent& hero)
: Guard::Guard(pos, 'H'), hero{&hero} {}

/** Moves the guard. This function overrides in the Guard's pure virtual function
 *  moves this guard towards the hero either in the x or y direction.
 * @parameter move determines the  position to move to. Should be a pure virtual function, 
 *            Defaults to 'A' for auto */
void HunterGuard::move(const char move)
{
    srand(time(NULL));
    if(!isDetected())//before detected
        randomMove();
    else//after detected
    {
        if(pos->x > hero->getPosition().x)
        {
            --pos->x;
        }
        else if(pos->x < hero->getPosition().x)
        {
            ++pos->x;
        }
        else
        {
            if(pos->y > hero->getPosition().y)
                --pos->y;
            else if(pos->y < hero->getPosition().y)
                ++pos->y;
        }
    }
}


bool HunterGuard::isDetected()
{
    if(labs(pos->x - hero->getPosition().x) + labs(pos->y - hero->getPosition().y) <= 3)
        return true;
    
    return false;
}