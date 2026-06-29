#include <iostream>
#include <string>
#include "Player.h"
#include "Wallet.h"
#include "Agent.h"
#include "Transaction.h"

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

const char* StatusToString(TransactionStatus status)
{
	switch (status)
	{
	case TransactionStatus::Pending:
		return "Pending";
	case TransactionStatus::Completed:
		return "Completed";
	case TransactionStatus::InvalidParticipants:
		return "InvalidParticipants";
	case TransactionStatus::InsufficientFunds:
		return "InsufficientFunds";
	case TransactionStatus::InvalidAmount:
		return "InvalidAmount";
	default:
		return "Unknown";
	}
}

void PrintTransactionResult(const TransactionResult& result)
{
	std::cout << "Transaction ID: " << result.transactionId << "\n";
	std::cout << "Sender ID: " << result.senderId << "\n";
	std::cout << "Recipient ID: " << result.recipientId << "\n";
	std::cout << "Amount: " << result.amount << "\n";
	std::cout << "Status: " << StatusToString(result.status) << "\n";
	std::cout << "Status message: " << result.message << "\n";
}

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
	Agent agent2(2, "Agent2", 50);

	Transaction transaction(&agent1, &agent2, 1, 30);

	TransactionResult result1 = transaction.ProcessTransaction();
	agent1.PrintInfo();
	agent2.PrintInfo();	
	PrintTransactionResult(result1);

	TransactionResult result1Repeat = transaction.ProcessTransaction(); // Attempt to process the same transaction again
	agent1.PrintInfo();
	agent2.PrintInfo();
	PrintTransactionResult(result1Repeat);

	Transaction transaction2(&agent1, &agent2, 2, 10000); // Insufficient funds

	TransactionResult result2 = transaction2.ProcessTransaction();
	agent1.PrintInfo();
	agent2.PrintInfo();
	PrintTransactionResult(result2);

	Transaction transaction3(&agent1, &agent2, 3, 0); // Invalid amount

	TransactionResult result3 = transaction3.ProcessTransaction();
	agent1.PrintInfo();
	agent2.PrintInfo();
	PrintTransactionResult(result3);

	Transaction transaction4(nullptr, &agent2, 4, 20);

	TransactionResult result4 = transaction4.ProcessTransaction();
	agent2.PrintInfo();
	PrintTransactionResult(result4);


	Transaction transaction5(&agent1, nullptr, 5, 20);

	TransactionResult result5 = transaction5.ProcessTransaction();
	agent1.PrintInfo();
	PrintTransactionResult(result5);


	Transaction transaction6(nullptr, nullptr, 6, 20);

	TransactionResult result6 = transaction6.ProcessTransaction();
	PrintTransactionResult(result6);

	return 0;
}

