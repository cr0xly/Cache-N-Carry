// Checking Account specification file
#pragma once
#include "Account.h"


class CheckingAccount : public Account {
private:
	//overdraft limit and fee in cents
	std::int64_t overdraftLimit = 30000;
	std::int64_t overdraftFee = 3500;
public:
	CheckingAccount(int account_number, int customer_id);
	bool withdraw(std::int64_t amount) override;
	std::string getAccountType() const override;
};