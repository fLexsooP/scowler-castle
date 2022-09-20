#include "person.h"

/** Person object. the base class for guards and Innocents
 * @parameter pos. the initial position
 * @parameter type. the type of person
 */
Person::Person(const Position& pos, char type)
{
    this->pos = new Position(pos);
    this->type = type;
}

/** Gets the current position of the Person
 * @return position. */
Position Person::getPosition() const
{
    return *pos;
}

/** Gets the type of the person [I, R, H, Y, W]
 * @return the type of the Person
 */
char Person::getType() const
{
    return type;
}

/** Equality operator
 * @parameter other the other person object
 * @return true if this object has the same position as the other and false otherwise */
bool Person::operator==(const Person& other) const
{
    if((pos->x == other.pos->x) && (pos->y == other.pos->y))
        return true;
    return false;
}

/** Inequality operator
 * @parameter other the other person object
 * @return false if this object has the same position as the other and true otherwise */
bool Person::operator!=(const Person& other) const
{
    if((pos->x == other.pos->x) && (pos->y == other.pos->y))
        return false;
    return true;
}

//g++ -c person.cpp