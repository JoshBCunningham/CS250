#include "Airplane.hpp"


//! Move traveller onto airplane
/**
    For the traveller passed in, push it into the airplane's stack.

    @param <Traveller*> traveller
    @return <void>
*/
void Airplane::Board(Traveller* traveller)
{
	TravellerStack.Push(traveller);
}

//! Pull traveller off airplane
/**
    Get the next (top-most) traveller from the airplane stack,
    remove them from the stack and return the traveller.

    @return <Traveller*>
*/
Traveller* Airplane::Disembark()
{
	Traveller * temp = TravellerStack.Top();
	TravellerStack.Pop();
	return temp;
}

//! Return whether the airplane is empty (no passengers)
/**
    If the size of the stack is 0, then the airplane is empty.

    @return <bool>
*/
bool Airplane::IsEmpty()
{
	if (TravellerStack.IsEmpty() == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

