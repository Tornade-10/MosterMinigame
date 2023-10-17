#pragma once
#include <string>

class Monster
{
public:
	std::string Race;
	std::string Pseudo;
	int MaxHealth;
	int Health;
	int Attack;
	int MaxDeffense;
	int Deffense;
	int Speed;

	//The constructor
	Monster(std::string _name, std::string _pseudo, int _maxHealth, int _attack, int _maxDeffense, int _speed);

	//All the ction the monster can make
	void Fight(Monster& x);
	void Pary();
	void ResetPary();
	void Heal();
};

