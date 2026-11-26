// Account Class implementation file

#include "Account.h"
#include <limits>

// Define the supported balance limits to prevent arithmetic overflow
const std::int64_t maxBalance = std::numeric_limits<std::int64_t>::max();
const std::int64_t minBalance = std::numeric_limits<std::int64_t>::min();



Account::Account(int account_number, int customer_id) : account_number(account_number), customer_id(customer_id) {}

bool Account::tryAdjustBalance(std::int64_t delta) {
	// Check for overflow or underflow before modifying the balance
	if (delta > 0 && balance > maxBalance - delta) {
		return false;
	}
	if (delta < 0 && balance < minBalance - delta) {
		return false;
	}

	this->balance += delta;

	return true;
}

bool Account::deposit(std::int64_t amount) {
	// Reject non-positive deposits to prevent bypassing withdrawal rules
	if (amount <= 0) {
		return false;
	}
	return tryAdjustBalance(amount);
}

