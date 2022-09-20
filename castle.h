// iostream is only used for the operator<< function.
// Do not print anything directly to cout from this or any other class
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <sstream>
#include <string>

#include "innocent.h"
#include "guard.h"
#include "indentured_guard.h"
#include "roving_guard.h"
#include "hunter_guard.h"

// this class does not provide UI no does it contain main. 
class Castle
{
    
public:
    /** stream insertion operator overload */
    friend std::ostream& operator<<(std::ostream& output, const Castle& c);
    
    /** castle constructor. Initializes the castle */ 
    Castle();

    /** move the position of the hero
     @ parameter move the direction in which the hero must move: must be a valid move
     @ throws invalid_argument exception if move is invalid */ 
    void move(char move);

    void guardMove();
    bool isDead();
    bool isEscape();

    /** Castle destructor. Deletes all heap based objects (including guards) */
    ~Castle(){delete hero; delete wife; delete &guards;}
private:
    std::vector<Guard*> guards;
    Innocent* hero;
    Innocent* wife;

    bool picked = false;
    std::string message = "";
    

    size_t random(size_t start, size_t end);
    
};