#include "Dealer.h"

Dealer::Dealer(string name) : Player(name)
{
	
}

Dealer::~Dealer()
{
	clean();
}

void Dealer::flipDealersCard()
{
	cards[0]->flipCard();
}