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

Transaction::Transaction(Agent* sender, Agent* recipient, int amount, int transactionId) : sender(sender), recipient(recipient), amount(amount), transactionId(transactionId), status(TransactionStatus::Pending)
{
	if (sender)
	{
		senderId = sender->GetId();
	}
	else
	{
		senderId = InvalidAgentId; // or some default value indicating no sender
	}

	if (recipient)
	{
		recipientId = recipient->GetId();
	}
	else
	{
		recipientId = InvalidAgentId; // or some default value indicating no recipient
	}
}

Transaction::~Transaction()
{
}

void Transaction::ProcessTransaction()
{
	if (sender && recipient)
	{
		if (amount <= 0)
		{
			status = TransactionStatus::InvalidAmount;
		}
		else
		{
			if (sender->Withdraw(amount))
			{
				recipient->Deposit(amount);
				status = TransactionStatus::Completed;
			}
			else
			{
				status = TransactionStatus::InsufficientFunds;
			}
		}
	}
	else
	{
		status = TransactionStatus::InvalidParticipants;
	}
}

void Transaction::PrintTransactionInfo() const
{
	std::cout << "Transaction ID: " << transactionId << "\n";
	std::cout << "Sender ID: " << senderId << "\n";
	std::cout << "Recipient ID: " << recipientId << "\n";
	std::cout << "Amount: " << amount << "\n";
	std::cout << "Status: " << StatusToString(status) << "\n";
}

TransactionStatus Transaction::GetStatus() const
{
	return status;
}

int Transaction::GetTransactionId() const
{
	return transactionId;
}

int Transaction::GetSenderId() const
{
	return senderId;
}

int Transaction::GetRecipientId() const
{
	return recipientId;
}

