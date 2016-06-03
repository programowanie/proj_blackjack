#pragma once
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Card
{
public:
	friend ostream& operator<<(ostream& out, Card& card);

	enum rank {As=1,Dwa,Trzy,Cztery,Piec,Szesc,
		Siedem,Osiem,Dziewiec,Dziesiec,Walet,Dama,Krol};
	enum suit {Kier,Karo,Trefl,Pik};
	Card(rank, suit);
	const int value();
	void flipCard();
private:
	bool _faceUp;
	rank _rank;
	suit _suit;
};