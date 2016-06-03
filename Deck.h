#pragma once
#include "Card.h"
#include "Hand.h"
#include "Player.h"

class Deck : public Hand
{
public:
	Deck();
	void fillDeck();
	void shuffleDeck();
	void deal(Hand& hand);
	void dealNewCard(Player& player);
};