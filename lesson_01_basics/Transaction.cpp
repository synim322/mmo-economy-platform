#include "Transaction.h"
#include <iostream>
#include "Agent.h"

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

Transaction::Transaction(Agent* sender, Agent* recipient, int transactionId, int amount) : sender (sender), recipient (recipient)
{
	if (sender)
	{
		result.senderId= sender->GetId();
	}
	else
	{
		result.senderId = InvalidAgentId;
	}

	if (recipient)
	{
		result.recipientId = recipient->GetId();
	}
	else
	{
		result.recipientId = InvalidAgentId;
	}

	result.status = TransactionStatus::Pending;

	result.message = "Transaction created";

	result.amount = amount;

	result.transactionId = transactionId;
}

Transaction::~Transaction()
{
}

TransactionResult Transaction::ProcessTransaction()
{
	if (result.status != TransactionStatus::Pending)
	{
		result.message = "Transaction already processed";
		return result;
	}

	if (!sender || !recipient)
	{
		result.status = TransactionStatus::InvalidParticipants;
		result.message = "Invalid participants";

		return result;
	}

	if (result.amount <= 0)
	{
		result.status = TransactionStatus::InvalidAmount;
		result.message = "Invalid amount";
			
		return result;
	}
	
	if (!sender->Withdraw(result.amount))
	{
		result.status = TransactionStatus::InsufficientFunds;
		result.message = "Insufficient funds";

		return result;
	}
	else
	{
		recipient->Deposit(result.amount);
		result.status = TransactionStatus::Completed;
		result.message = "Transaction completed";

		return result;
	}
}

void Transaction::PrintTransactionResult(const TransactionResult& result) const
{
	std::cout << "Transaction ID: " << result.transactionId << "\n";
	std::cout << "Sender ID: " << result.senderId << "\n";
	std::cout << "Recipient ID: " << result.recipientId << "\n";
	std::cout << "Amount: " << result.amount << "\n";
	std::cout << "Status: " << StatusToString(result.status) << "\n";
	std::cout << "Status message: " << result.message << "\n";
}

TransactionStatus Transaction::GetStatus() const
{
	return result.status;
}

int Transaction::GetTransactionId() const
{
	return result.transactionId;
}

int Transaction::GetSenderId() const
{
	return result.senderId;
}

int Transaction::GetRecipientId() const
{
	return result.recipientId;
}

