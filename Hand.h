#pragma once
#include "Card.h"

class Hand
{
public:
	Hand();
	virtual ~Hand();
	bool add(Card* card);
	void clean();
	const int total();
protected:
	std::vector<Card*> cards;
};