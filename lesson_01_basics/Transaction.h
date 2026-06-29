#pragma once

enum class TransactionStatus
{
	Pending,
	Completed,
	InvalidParticipants,
	InsufficientFunds,
	InvalidAmount,
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

	TransactionStatus status;

	static constexpr int InvalidAgentId = -1;
public:
	Transaction(Agent* sender, Agent* recipient, int amount, int transactionId);
	~Transaction();

	void ProcessTransaction();
	void PrintTransactionInfo() const;

	TransactionStatus GetStatus() const;
	int GetTransactionId() const;
	int GetSenderId() const;
	int GetRecipientId() const;
};