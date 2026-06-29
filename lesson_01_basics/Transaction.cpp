#include "Transaction.h"
#include "Agent.h"

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

