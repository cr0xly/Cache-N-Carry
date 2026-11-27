// Testing
#include <iostream>
#include "CheckingAccount.h"
#include <limits>

using namespace std;

int main()
{
	cout << boolalpha;

	cout << "Creating Checking Account for Skylar" << endl;
	CheckingAccount skylar(1000001, 1);
	cout << "Balance: " << skylar.getBalance() << endl << endl;

	cout << "Depositing 10000..." << skylar.deposit(10000) << endl;
	cout << "Balance: " << skylar.getBalance() << endl << endl;

	cout << "Depositing -5000..." << skylar.deposit(-5000) << endl;
	cout << "Balance: " << skylar.getBalance() << endl << endl;

	cout << "Depositing 0..." << skylar.deposit(0) << endl;
	cout << "Balance: " << skylar.getBalance() << endl << endl;

	cout << "Withdrawing 5000..." << skylar.withdraw(5000) << endl;
	cout << "Balance: " << skylar.getBalance() << endl << endl;

	cout << "Withdrawing another 5000..." << skylar.withdraw(5000) <<endl;
	cout << "Balance: " << skylar.getBalance() << endl << endl;

	cout << "Withdrawing antoher 5000..." << skylar.withdraw(5000) << endl;
	cout << "Balance: " << skylar.getBalance() << endl << endl;

	cout << "Withdrawing 18000..." << skylar.withdraw(18000) << endl;
	cout << "Balance: " << skylar.getBalance() << endl << endl;

	cout << "Withdrawing 100..." << skylar.withdraw(100) << endl;
	cout << "Balance: " << skylar.getBalance() << endl << endl;

	cout << "Withdrawing 0..." << skylar.withdraw(0) << endl;
	cout << "Balance: " << skylar.getBalance() << endl << endl;

	cout << "Withdrawing -500..." << skylar.withdraw(-500) << endl;	
	cout << "Balance: " << skylar.getBalance() << endl << endl;

	cout << "Depositing 40000..." << skylar.deposit(40000) << endl;
	cout << "Balance: " << skylar.getBalance() << endl << endl << endl;


	cout << "Creating Checking Account for Tim" << endl;
	CheckingAccount tim(1000002, 2);
	cout << "Balance: " << tim.getBalance() << endl << endl;

	cout << "Depositing numeric limit..." << tim.deposit(std::numeric_limits<std::int64_t>::max()) << endl;
	cout << "Balance: " << tim.getBalance() << endl << endl;

	cout << "Depositing 1..." << tim.deposit(1) << endl;
	cout << "Balance: " << tim.getBalance() << endl << endl;

	cout << "Withdrawing numeric limit..." << tim.withdraw(std::numeric_limits<std::int64_t>::max()) << endl;
	cout << "Balance: " << tim.getBalance() << endl << endl;

	cout << "Withdrawing numeric limit again..." << tim.withdraw(std::numeric_limits<std::int64_t>::max()) << endl;
	cout << "Balance: " << tim.getBalance() << endl << endl;

	system("pause");
}

/*

I/O Dialogue

Creating Checking Account for Skylar
Balance: 0

Depositing 10000...true
Balance: 10000

Depositing -5000...false
Balance: 10000

Depositing 0...false
Balance: 10000

Withdrawing 5000...true
Balance: 5000

Withdrawing another 5000...true
Balance: 0

Withdrawing antoher 5000...true
Balance: -8500

Withdrawing 18000...true
Balance: -30000

Withdrawing 100...false
Balance: -30000

Withdrawing 0...false
Balance: -30000

Withdrawing -500...false
Balance: -30000

Depositing 40000...true
Balance: 10000


Creating Checking Account for Tim
Balance: 0

Depositing numeric limit...true
Balance: 9223372036854775807

Depositing 1...false
Balance: 9223372036854775807

Withdrawing numeric limit...true
Balance: 0

Withdrawing numeric limit again...false
Balance: 10000

Press any key to continue . . .

*/