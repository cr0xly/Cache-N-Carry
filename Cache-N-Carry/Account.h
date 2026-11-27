// Account Class specification file
#pragma once
#include <cstdint>
#include <string>


class Account {
private:
	int account_number;
	int customer_id;

	// Store monetary values in cents to avoid floating-point precision errors
	std::int64_t balance = 0;

protected:
	// Restrict account construction to derived account types
	Account(int account_number, int customer_id);

	bool tryAdjustBalance(std::int64_t delta);

public:
	int getAccountNumber() const { return this->account_number; }
	int getCustomerId() const { return this->customer_id; }
	std::int64_t getBalance() const { return this->balance; }

	bool deposit(std::int64_t amount);

	// Require derived classes to implement account-specific behaviour
	virtual bool withdraw(std::int64_t amount) = 0;
	virtual std::string getAccountType() const = 0 ;

	// (default) Let the compiler implement the destructor, but keep it virtual for polymorphism
	virtual ~Account() = default;
};