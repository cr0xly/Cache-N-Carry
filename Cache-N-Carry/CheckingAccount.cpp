// CheckingAccount Class implementation file
#include "CheckingAccount.h"
#include <limits>

CheckingAccount::CheckingAccount(int account_number, int customer_id) : Account(account_number, customer_id) {}

bool CheckingAccount::withdraw(std::int64_t amount) {
	// Reject non-positive withdrawal amounts
	if (amount <= 0) {
		return false;
	}

	// Process withdrawals that do not require overdraft
	if (amount <= getBalance()) {
		return tryAdjustBalance(-amount);
	}

	// Prevent overflow when combining the withdrawal amount and overdraft fee
	if (amount > std::numeric_limits<std::int64_t>::max() - overdraftFee) {
		return false;
	}

	// Ensure the withdrawal and fee remain within the overdraft limit
	if (getBalance() < amount - (overdraftLimit - overdraftFee)) {
		return false;
	}
	return tryAdjustBalance(-amount - overdraftFee);
}

std::string CheckingAccount::getAccountType() const {
	return "Checking";
}