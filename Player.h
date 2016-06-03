#pragma once
#include "Hand.h"
#include <fstream>
#include <iterator>

class Player : public Hand
{
public:
	friend ostream& operator<<(ostream& out, Player& player); 

	Player();
	Player(string name);
	virtual ~Player();
	void bet();
	bool hit();
	bool isBusted();
	void win();
	void lose();
	void tie();
private:
	static void init();
	static std::vector<string> names;
	unsigned int _money;
	unsigned int _bet;
protected:
	string _name;
};