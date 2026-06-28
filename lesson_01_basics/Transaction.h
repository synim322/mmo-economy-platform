#pragma once

enum class Status
{
	Pending,
	Completed,
	Failed
};

class Agent; // Forward declaration of Agent class

class Transaction
{
private:
	Agent* sender;
	Agent* recipient;
	int amount;
	int transactionId;
	int senderId;
	int recipientId;

	Status status;

public:
	Transaction(Agent* sender, Agent* recipient, int amount, int transactionId);
	~Transaction();

	void ProcessTransaction();
	void PrintTransactionInfo() const;

	Status GetStatus() const;
	int GetTransactionId() const;
	int GetSenderId() const;
	int GetRecipientId() const;
};