#include "Hand.h"

Hand::Hand()
{

}

Hand::~Hand()
{
	clean();
}

bool Hand::add(Card* card)
{
	cards.push_back(card);
}

void Hand::clean()
{
	for (std::vector<Card*>::iterator i = cards.begin(); i != cards.end(); i++)
	{
		delete *i;
		*i = NULL;
	}
	cards.clear();
}

const int Hand::total()
{
	int total = 0;
	bool hasAce = false;
	if (cards.empty())
		return 0;
	for (std::vector<Card*>::iterator i = cards.begin(); i != cards.end(); i++)
	{
		if ((*i)->value() == Card::As)
			hasAce = true;
		total += (*i)->value();
	}
	if (hasAce && total <= 11)
		total += 10;
	return total;
}