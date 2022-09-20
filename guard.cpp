

#include "guard.h"

/** Guard constructor. Calls person constructor  
     * @parameter pos is the initial position. 
     * @parameter type is the type of person. */
Guard::Guard(const Position& pos, char type)
: Person::Person(pos, type){}

int Guard::random()
{
     srand((unsigned int)time(NULL));
     return rand() % 100;
}

void Guard::randomMove()
{
     srand(time(NULL));

     // switch (random())
     // {
     // case 0:
     //      if(pos->x > 0)
     //           --pos->x;
     //      break;
     // case 1:
     //      if(pos->x < 7)
     //           ++pos->x;
     //      break;
     // case 2:
     //      if(pos->y > 0)
     //           --pos->y;
     //      break;
     // case 3:
     //      if(pos->y < 7)
     //           ++pos->y;
     //      break;
     // }
     
     if(random() < 50)//move horizontal
     {
          if(pos->x > 0 && pos->x < 7)
               (random() < 25) ? --pos->x : ++pos->x;
          else if(pos->x <= 0)
               ++pos->x;
          else
               --pos->x;
     }
     else//move vertical
     {
          if(pos->y > 0 && pos->y < 7)
               (random() < 75) ? --pos->y : ++pos->y;
          else if(pos->y <= 0)
               ++pos->y;
          else
               --pos->y;
     }
}