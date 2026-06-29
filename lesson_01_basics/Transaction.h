#pragma once
#include <string>

enum class TransactionStatus
{
	Pending,
	Completed,
	InvalidParticipants,
	InsufficientFunds,
	InvalidAmount,
};

struct TransactionResult
{
	int transactionId;
	int senderId;
	int recipientId;
	int amount;
	TransactionStatus status;
	std::string  message;
};

class Agent; // Forward declaration of Agent class

class Transaction
{
private:
	Agent* sender;
	Agent* recipient;
	
	TransactionResult result;

	static constexpr int InvalidAgentId = -1;
public:
	Transaction(Agent* sender, Agent* recipient, int transactionId, int amount);
	~Transaction();

	TransactionResult ProcessTransaction();

	TransactionStatus GetStatus() const;
	int GetTransactionId() const;
	int GetSenderId() const;
	int GetRecipientId() const;
};