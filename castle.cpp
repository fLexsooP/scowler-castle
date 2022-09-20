#include "castle.h"

/** castle constructor. Initializes the castle */ 
Castle::Castle()
{
    srand(time(NULL));
    hero = new Innocent({0, 0}, 'Y');
    wife = new Innocent({(size_t)random(3, 4), (size_t)random(3, 4)}, 'W');
    for (size_t i = 0; i < 5; i++)
        guards.emplace_back(new IndenturedGuard({random(0, 7), random(0, 7)}));
    for (size_t i = 0; i < 4; i++)
        guards.emplace_back(new RovingGuard({random(0, 7), random(0, 7)}));
    for (size_t i = 0; i < 2; i++)
        guards.emplace_back(new HunterGuard({random(0, 7), random(0, 7)}, *hero));
}

/** stream insertion operator overload */
std::ostream& operator<<(std::ostream& output, const Castle& c)
{

    for (size_t i = 0; i < 49; i++)
        output << '-';
    output << std::endl;

    for (size_t i = 0; i < 8; i++)
    {    
        for (size_t j = 0; j < 8; j++)
        {
            output << '|';
            output << ' ';

            for (size_t k = 0; k < 5; k++)//print indenture guard if available
            {
                if(c.guards.at(k)->getPosition().x == j && c.guards.at(k)->getPosition().y == i)
                {
                    output << c.guards.at(k)->getType();
                    break;
                }
                if(k == 4)
                    output << ' ';
            }

            for (size_t k = 5; k < 9; k++)//print roving guard if available
            {
                if(c.guards.at(k)->getPosition().x == j && c.guards.at(k)->getPosition().y == i)
                {
                    output << c.guards.at(k)->getType();
                    break;
                }
                if(k == 8)
                    output << ' ';
            }

            for (size_t k = 9; k < 11; k++)//print hunter guard if available
            {
                if(c.guards.at(k)->getPosition().x == j && c.guards.at(k)->getPosition().y == i)
                {
                    output << c.guards.at(k)->getType();
                    break;
                }
                if(k == 10)
                    output << ' ';
            }

            output << ((c.wife->getPosition().x == j && c.wife->getPosition().y == i) ? c.wife->getType() : ' ');
        }
        output << '|' << std::endl;

        for (size_t j = 0; j < 8; j++)
        {
            output << '|';
            output << ' ';
            output << ' ';
            output << ((c.hero->getPosition().x == j && c.hero->getPosition().y == i) ? c.hero->getType() : ' ');
            output << ' ';
            output << ' ';
        }
        output << '|' << std::endl;

        for (size_t i = 0; i < 49; i++)
            output << '-';
        
        output << std::endl;
    }
    output << c.message << std::endl;
    return output;
}


/** move the position of the hero
 @ parameter move the direction in which the hero must move: must be a valid move
    @ throws invalid_argument exception if move is invalid */ 
void Castle::move(char move)
{
    move = toupper(move);
    switch (move)
    {
    case 'E':
        if(hero->getPosition().x >= 7)
            message = "That is not a valid move";
        else
        {
            hero->move('E');
            picked ? wife->move('E') : wife->move('P');
            message = "";
        }
        break;
    case 'W':
        if(hero->getPosition().x <= 0)
            message = "That is not a valid move";
        else
        {
            hero->move('W');
            picked ? wife->move('W') : wife->move('P');
            message = "";
        }
        break;
    case 'N':
        if(hero->getPosition().y <= 0)
            message = "That is not a valid move";
        else
        {
            hero->move('N');
            picked ? wife->move('N') : wife->move('P');
            message = "";
        }
        break;
    case 'S':
        if(hero->getPosition().y >= 7)
            message = "That is not a valid move";
        else
        {
            hero->move('S');
            picked ? wife->move('S') : wife->move('P');
            message = "";
        }
        break;
    case 'P':
        hero->move('P');
        break;
    case 'C':
        hero->move('C');
        if(hero->operator==(*wife))
            picked = true;
        else
            message = "The hero is not in the same room as his wife";
        break;
    }
}

void Castle::guardMove()
{
    for (Guard *g : guards)
        g->move();
}

size_t Castle::random(size_t start, size_t end)
{
    return rand() % (end - start + 1) + start;
}

bool Castle::isDead()
{
    for (size_t i = 0; i < 9; i++)
    {
        if(*hero == *guards.at(i))
            return true;
    }
    for (size_t i = 9; i < 11; i++)
    {
        if(abs((int)hero->getPosition().x - (int)guards.at(i)->getPosition().x) + abs((int)hero->getPosition().y - (int)guards.at(i)->getPosition().y) <= 1)
            return true;
    }
    return false;
}

bool Castle::isEscape()
{
    Innocent* o = new Innocent({0, 0},'o');
    if(*hero == *wife && *wife == *o)
        return true;
    
    return false;
}