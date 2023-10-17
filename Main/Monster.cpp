#include "Monster.h"

Monster::Monster(std::string _name, std::string _pseudo, int _maxHealth, int _attack, int _maxDeffense, int _speed)
{
	Race = _name;
	Pseudo = _pseudo;
	MaxHealth = _maxHealth;
	Health = MaxHealth;
	Attack = _attack;
	MaxDeffense = _maxDeffense;
	Deffense = MaxDeffense;
	Speed = _speed;
}

//Action Attack
void Monster::Fight(Monster &x)
{
	if (Speed > x.Speed + 2)
	{
		x.Health = x.Health - (Attack - x.Deffense) * 2;
		if (Attack < x.Deffense)
		{
			Attack = x.Deffense;
		}
	}
	else
	{
		x.Health = x.Health - (Attack - x.Deffense);
		if (Attack < x.Deffense)
		{
			Attack = x.Deffense;
		}
	}
}

//Action Block
void Monster::Pary()
{
	Deffense = Deffense + 3;
}

//Reset the deffense
void Monster::ResetPary()
{
	if (Deffense > MaxDeffense)
	{
		Deffense = Deffense - 3;
	}
}

//Action Heal
void Monster::Heal()
{
	if (Health <= MaxHealth)
	{
		Health = Health + (2 * 100 / MaxHealth);
		if (Health > MaxHealth)
		{
			Health = MaxHealth;
		}
	}
}
