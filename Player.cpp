#include "Player.h"

std::vector<string> Player::names;

void Player::init()
{
	srand(time(NULL));
	std::ifstream file("names.dat");
	copy(std::istream_iterator<string>(file),
		std::istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

Player::Player()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_money = rand() % 500 + 100;
}

Player::Player(string name)
{
	_name = name;
}

Player::~Player()
{
	clean();
}

void Player::bet()
{
	srand(time(NULL));
	_bet = rand() % _money;
	cout<<_name<<" stawia "<<_bet<<"$"<<endl;
	cout<<endl;
}

bool Player::hit()
{
	return (total() <= 16);
}

bool Player::isBusted()
{
	return (total() > 21);
}

void Player::win()
{
	unsigned int moneyWon = 0;
	if(total() == 21)
		moneyWon = (3*_bet)/2;
	else
		moneyWon = _bet;
	cout<<_name<<" wygrywa "<<moneyWon<<"$!"<<endl;
}

void Player::lose()
{
	cout<<_name<<" przegrywa "<<_bet<<"$!"<<endl;
}

void Player::tie()
{
	cout<<_name<<" remisuje!"<<endl;
}