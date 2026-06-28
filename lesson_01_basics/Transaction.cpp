#include "Transaction.h"
#include <iostream>
#include "Agent.h"

const char* StatusToString(Status status)
{
	switch (status)
	{
	case Status::Pending:
		return "Pending";
	case Status::Completed:
		return "Completed";
	case Status::Failed:
		return "Failed";
	default:
		return "Unknown";
	}
}

Transaction::Transaction(Agent* sender, Agent* recipient, int amount, int transactionId) : sender(sender), recipient(recipient), amount(amount), transactionId(transactionId), status(Status::Pending)
{
	if (sender)
		senderId = sender->GetId();
	if (recipient)
		recipientId = recipient->GetId();
}

Transaction::~Transaction()
{
}

void Transaction::ProcessTransaction()
{
	if (sender && recipient)
	{
		if (sender->Withdraw(amount))
		{
			recipient->Deposit(amount);
			status = Status::Completed;
		}
		else
		{
			status = Status::Failed;
		}
	}
	else
	{
		status = Status::Failed;
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

Status Transaction::GetStatus() const
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

