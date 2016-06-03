#include "Card.h"

Card::Card(rank rank, suit suit)
{
	_rank = rank;
	_suit = suit;
	_faceUp = true;
}

const int Card::value()
{
	int value = 0;
	if (_faceUp)
	{
		value = _rank;
		if (value > 10)
			value = 10;
	}
	return value;
}

void Card::flipCard()
{
	_faceUp = !(_faceUp);
}