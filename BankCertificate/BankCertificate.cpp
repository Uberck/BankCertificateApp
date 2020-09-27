#include <iostream>
#include <limits>
#include <string>
#include "BankCertificate.h"
using namespace std;

bool isAllDigits(const string& s)	  // Iterate over string to find non-digit characters, credit StackOverflow - https://rb.gy/vpxxv3
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

int main()
{
	string acctNumber;
	int acctNumberInt;
	double acctBalance, acctInterest, acctMaturity, balance, interest;

	// Account number section
	while (true)
	{
		// Loop
		cout << "Please enter your account number: ";
		cin >> acctNumber;	// Store account balance input
		cout << "Account # entered:[" << acctNumber << "]" << endl << endl; // Verification
		if (!isAllDigits(acctNumber))
		{
			cout << "Account number must only contain digits." << endl;
			continue;
		}

		try
		{
			acctNumberInt = stoi(acctNumber);	// String to integer conversion
		}

		catch (...)
		{
			cout << "Numeric conversion failed." << endl;    // String entered contains 
			continue;
		}

		if (acctNumberInt < 99 || acctNumberInt > 100000)	// Checks that the acct# is not a number less than 99 or greater than 99999
		{
			cout << "Account number must be greater than 99 &less than 99999." << endl;
			continue;
		}

		break;
	}

	// Account balance section
	while (true)
	{
		cout << "Enter your initial account balance (in $): ";
		cin >> acctBalance;	// Store account balance input
		cout << "Balance entered:[$" << acctBalance << "]" << endl << endl;
		if (cin.fail())
		{
			// Checks that the balance entered is indeed a number
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Balance must be a number between 1 and 100000." << endl;
			continue;
		}

		if (acctBalance < 1 || acctBalance > 100000)	// Checks that the balance entered is not a number less than 1 or greater than 100000
		{
			cout << endl << "Account balance must be greater than 0 &less than 100,000." << endl;
			continue;
		}

		break;
	}

	// Interest rate section
	while (true)
	{
		cout << "Enter the account interest rate (0-1000):";
		cin >> acctInterest;	// Store account interest rate input
		cout << "Interest rate entered:[" << acctInterest << "%]" << endl << endl;
		if (cin.fail())
		{
			// Checks that the interest rate entered is indeed a number
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please pick a 'whole' interest number between 0 and 1000:" << endl;
			continue;
		}

		if (acctInterest < 0 || acctInterest > 1000)	// Checks that the interest rate entered is not less than 0 or greater than 1000
		{
			cout << endl << "Please enter a valid interest rate between 0 &1000:" << endl;
			continue;
		}

		break;
	}

	// Account term section
	while (true)
	{
		cout << "Enter the number of months until maturity" << endl << "(Must be 12 or fewer months):";
		cin >> acctMaturity;	// Take input for term
		cout << "Term entered:[" << acctMaturity << " months]" << endl << endl;
		if (cin.fail())
		{
			// Checks that the number of months entered is indeed a number
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please pick a number for the months between 1-12:" << endl;
			continue;
		}

		if (acctMaturity < 1 || acctMaturity > 12)	// Check that months entered is not less than 1 or greater than 12
		{
			cout << endl << "Please enter a valid number of months between 1 &12." << endl;
			continue;
		}

		break;
	}

	CDAccount cd(acctNumber, acctBalance, acctInterest, acctMaturity);	// Constructing the CDAccount object

	cout << "Information Entered: " << endl << endl;
	cout << "Account Number:      " << cd.getAcctNumber() << endl;
	cout << "Initial Balance:$    " << cd.getBalance() << endl;
	cout << "Interest Rate:       " << cd.getInterestRate() << "%" << endl;
	cout << "Term:                " << cd.getMaturityMonths() << " months." << endl << endl;

	acctInterest = acctInterest / 100;
	acctMaturity = acctMaturity / 12;
	interest = acctBalance * acctInterest * acctMaturity; // Equation to calculate interest
	balance = acctBalance + interest; // Calculates total balance

	// Print results
	cout << "When your CD matures in " << acctMaturity * 12 << " months, account #" << acctNumber << " will have a balance of $" << balance << endl << endl;
	system("pause");	// Pause the window
	return 0;
}

//  exit(8);     	// Exit program for debugging purposes