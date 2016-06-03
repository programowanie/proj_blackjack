#pragma once
#include "Hand.h"
#include "Card.h"
#include "Player.h"

class Dealer : public Player
{
public:
	Dealer(string name = "Krupier");
	~Dealer();
	void flipDealersCard();
};