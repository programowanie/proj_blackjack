#include "Deck.h"

Deck::Deck()
{
	clean();
	fillDeck();
	shuffleDeck();
}

void Deck::fillDeck()
{
	for (int suit = Card::Kier; suit <= Card::Pik; suit++)
	{
		for (int rank = Card::As; rank <= Card::Krol; rank++)
		{
			add(new Card((Card::rank)rank,(Card::suit)suit));
		}
	}
}

void Deck::shuffleDeck()
{
	random_shuffle(cards.begin(), cards.end());
}

void Deck::deal(Hand& hand)
{
		hand.add(cards.back());
		cards.pop_back();
}

void Deck::dealNewCard(Player& player)
{
	deal(player);
}