#include <iostream>
#include <string>
#include "Player.h"
#include "Wallet.h"
#include "Agent.h"

/*
void PrintPlayerInfo(const Player& player)
{
	player.PrintInfo();
}

void PrintPlayerInfo2(Player hero)
{
	hero.PrintInfo();
}
*/

int main()
{
	/* if (true)
	{
		Player player1("Nikit");
		Player player2("Alex");
		Player player3("Bob");

		player1.TakeDamage(20);
		player2.AddExperience(50);
		player3.Heal(10);
		
		player1.PrintInfo();
		player2.PrintInfo();
		player3.PrintInfo();
	}
	*/

	//Player originalPlayer("Original");
	//Player copiedPlayer = originalPlayer; // Copy constructor

	/*
	copiedPlayer.SetName("Copied");
	copiedPlayer.TakeDamage(30);

	originalPlayer.PrintInfo();
	copiedPlayer.PrintInfo(); 
	*/

	//PrintPlayerInfo(originalPlayer);
	//PrintPlayerInfo2(originalPlayer);
	
	Agent agent1(1, "Agent1", 100);

	if (agent1.Withdraw(30))
	{
		std::cout << "Withdrawal successful" << "\n";
	}
	else
	{
		std::cout << "Withdrawal failed" << "\n";
	}

	if (agent1.Withdraw(10000))
	{
		std::cout << "Withdrawal successful" << "\n";
	}
	else
	{
		std::cout << "Withdrawal failed" << "\n";
	}
	
	if (agent1.Withdraw(0))
	{
		std::cout << "Withdrawal successful" << "\n";
	}
	else
	{
		std::cout << "Withdrawal failed" << "\n";
	}

	agent1.PrintInfo();

	return 0;
}

