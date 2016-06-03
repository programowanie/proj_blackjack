#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

ostream& operator<<(ostream& out, Card& card);
ostream& operator<<(ostream& out, Player& player);

int main(int argc, char** argv)
{
	srand(time(NULL));
	Deck deck;
	Player player;
	Dealer dealer;
	player.bet();
	for (int i = 0; i < 2; i++)
	{
		deck.deal(player);
		deck.deal(dealer);
	}
	dealer.flipDealersCard();
	cout<<player<<endl;
	cout<<dealer<<endl;
	while(player.hit())
	{
		deck.dealNewCard(player);
	}
	dealer.flipDealersCard();
	while(dealer.hit())
	{
		deck.dealNewCard(dealer);
	}
	cout<<player<<endl;
	cout<<dealer<<endl;
	if(player.isBusted() || player.total() < dealer.total() || (dealer.isBusted() && player.isBusted()))
		player.lose();
	else if(player.total() == dealer.total() && !player.isBusted())
		player.tie();
	else if(player.total() > dealer.total() && !player.isBusted())
		player.win();
}

ostream& operator<<(ostream& out, Card& card) //przeciążamy operator << żeby móc wyświetlić karty
{
	string ranks[] = {"0","A", "2", "3", "4", "5", "6", "7",
					"8", "9", "10", "J", "Q", "K"};
	string suits[] = {"Kier", "Karo", "Trefl", "Pik"};
	if(card._faceUp)
	{
		out<<ranks[card._rank]<<" "<<suits[card._suit];
	}
	else
		out<<"Karta zakryta";
	return out;
}

ostream& operator<<(ostream& out, Player& player) //a tu przeciążamy, aby wyświetlić gracza i krupiera
{
	out<<player._name<<endl;
	out<<"Pieniadze: "<<player._money<<"$"<<endl;
	std::vector<Card*>::iterator itCard;
	for (itCard = player.cards.begin(); itCard != player.cards.end(); itCard++)
	{
		out<<*(*itCard)<<endl;
	}
	cout<<"Wartosc kart: "<<player.total()<<endl;
	return out;
}