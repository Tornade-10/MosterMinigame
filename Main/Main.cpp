// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iso646.h>
#include <vector>

#include "Monster.h"
#include "ChooseMoove.h"



//Initialise all bool
bool isPlaying = true;
bool MonsterIsAlive = true;

//Initialise all int
int EnemyMonster = 0;
int PlayerMonster = 0;
int Turn = 0;

//Initialise the char
char playAgain = 0;

enum Race
{
	Orc,
	Troll,
	Goblin
};
enum Actions
{
	Fight,
	Pary,
	Heal
};

std::string PlayerMonsterName;

std::vector<Monster> MonsterChoice
{
	Monster("Orc", PlayerMonsterName, 24, 8, 7, 3),
	Monster("Troll", PlayerMonsterName, 21, 12, 4, 7),
	Monster("Goblin",PlayerMonsterName, 18, 9, 2, 10)
};

int EnemyAction = 0;
int PlayerAction = 0;

int main()
{
	do
	{

#pragma region Random
		//Create the random
		srand(time(NULL));
		EnemyMonster = rand() % 3;
#pragma endregion

		//Select the monster
		std::cout << "Select a monster \n" << "Orc [" << Orc << "], " << "Troll [" << Troll << "], " << "Goblin [" << Goblin << "] " << std::endl;
		std::cin >> PlayerMonster;

		//Create a smaller variable for the choosed monster
		Monster PlayerSelectedMonster = MonsterChoice.at(PlayerMonster);
		Monster EnemySelectedMonster = MonsterChoice.at(EnemyMonster);

		//Race the monster
		std::cout << "Choose his name" << std::endl;
		std::cin >> PlayerMonsterName;
		std::cout << std::endl;

		//Rename the Monster with a pseudo
		PlayerSelectedMonster.Pseudo = PlayerMonsterName;

		//Clear the console
		system("cls");

		do
		{

			//Choose the action of the bot
			EnemyAction = rand() % 3;

#pragma region PlayerFeedBack
			//Show the Turn
			std::cout << "Turn : " << Turn << std::endl;
			std::cout << std::endl;

			//Show the health of both Monster
			std::cout << PlayerSelectedMonster.Pseudo << " the " << PlayerSelectedMonster.Race << " Health :" << PlayerSelectedMonster.Health << std::endl;
			std::cout << EnemySelectedMonster.Race << " Health :" << EnemySelectedMonster.Health << std::endl;
			std::cout << std::endl;

			//Show the action the player can choose
			std::cout << "choose an action" << std::endl;
			std::cout << "Fight (Make your monster attack) [" << Fight << "]" << std::endl;
			std::cout << "Pary (Protect your self for this turn) [" << Pary << "]" << std::endl;
			std::cout << "heal (Recover a small amount of health) [" << Heal << "]" << std::endl;

			std::cin >> PlayerAction;
#pragma endregion

			system("cls");

			//Make the Player or the Bot attack first depending on the speed
			if (PlayerSelectedMonster.Speed >= EnemySelectedMonster.Speed)
			{

				//Check wich action the player will do
				switch (PlayerAction)
				{
				case Fight:
					PlayerSelectedMonster.Fight(EnemySelectedMonster);
					std::cout << "BAM !" << std::endl;
					std::cout << "You did " << PlayerSelectedMonster.Attack - EnemySelectedMonster.Deffense << " damage \n" << std::endl;
					break;

				case Pary:
					PlayerSelectedMonster.Pary();
					std::cout << "You parry the hit \n" << std::endl;
					break;

				case Heal:
					PlayerSelectedMonster.Heal();
					std::cout << "You Healed some HP \n" << std::endl;
					break;

				default:
					break;
				}

				if (EnemySelectedMonster.Health <= 0)
				{
					MonsterIsAlive = false;
				}

				//Check wich action the bot will do
				switch (EnemyAction)
				{
				case Fight:
					EnemySelectedMonster.Fight(PlayerSelectedMonster);
					std::cout << "OUCH !" << std::endl;
					std::cout << "You took " << EnemySelectedMonster.Attack - PlayerSelectedMonster.Deffense << " damage \n" << std::endl;
					break;

				case Pary:
					EnemySelectedMonster.Pary();
					std::cout << "Your ennemie seems ready to take the hit \n" << std::endl;
					break;


				case Heal:
					EnemySelectedMonster.Heal();
					std::cout << "Your ennemie seems a bit more healthy \n" << std::endl;
					break;

				default:
					break;
				}

			}
			else
			{

				//Check wich action the bot will do
				switch (EnemyAction)
				{
				case Fight:
					EnemySelectedMonster.Fight(PlayerSelectedMonster);
					std::cout << "OUCH !" << std::endl;
					std::cout << "You took " << EnemySelectedMonster.Attack - PlayerSelectedMonster.Deffense << " damage \n" << std::endl;
					break;

				case Pary:
					EnemySelectedMonster.Pary();
					std::cout << "Your ennemie seems ready to take the hit \n" << std::endl;
					break;


				case Heal:
					EnemySelectedMonster.Heal();
					std::cout << "Your ennemie seems a bit more healthy \n" << std::endl;
					break;

				default:
					break;
				}

				if (PlayerSelectedMonster.Health <= 0)
				{
					MonsterIsAlive = false;
				}

				//Check wich action the player will do
				switch (PlayerAction)
				{
				case Fight:
					PlayerSelectedMonster.Fight(EnemySelectedMonster);
					std::cout << "BAM !" << std::endl;
					std::cout << "You did " << PlayerSelectedMonster.Attack - EnemySelectedMonster.Deffense << " damage \n" << std::endl;
					break;

				case Pary:
					PlayerSelectedMonster.Pary();
					std::cout << "You parry the hit \n" << std::endl;
					break;

				case Heal:
					PlayerSelectedMonster.Heal();
					std::cout << "You Healed some HP \n" << std::endl;
					break;

				default:
					break;
				}
			}

			//Reset the Defense point to all monsters
			PlayerSelectedMonster.ResetPary();
			EnemySelectedMonster.ResetPary();

			//Add one to the Turn count
			Turn++;

		}
		while (MonsterIsAlive);


		std::cout << "A monster died!" << std::endl;

		//Check wiche Monster died
		if (PlayerSelectedMonster.Health <= 0)
		{
			std::cout << "your monster died, you loose\n" << std::endl;
		}
		else if (EnemySelectedMonster.Health <= 0)
		{
			std::cout << "The enemy monster died! You won!\n" << std::endl;
		}

#pragma region PlayerFeedBack

		//Mostly some player feedBack
		std::cout << PlayerSelectedMonster.Pseudo << " the " << PlayerSelectedMonster.Race << " Health :" << PlayerSelectedMonster.Health << std::endl;
		std::cout << EnemySelectedMonster.Race << " Health :" << EnemySelectedMonster.Health << std::endl;

		std::cout << std::endl;

		//Ask if the player want to restart
		std::cout << "It took : " << Turn << " Turn to end" << std::endl;
		std::cout << "Want to play another game?\n" << "yes [y] or no [n]?" << std::endl;
		std::cin >> playAgain;

#pragma endregion 

		//Check the player and if he want to restart
		if (playAgain == 'n')
		{
			isPlaying = false;
		}
		else if (playAgain == 'y')
		{
			isPlaying = true;
		}

		system("cls");

		//Reset a bool and a var 
		MonsterIsAlive = true;
		Turn = 0;
	}
	while (isPlaying);

	return EXIT_SUCCESS;
}

