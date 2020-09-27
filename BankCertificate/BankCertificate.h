#ifndef BankCertificate_H
#define BankCertificate_H
#include <iostream>
#include <limits>
using namespace std;

class CDAccount
{
private:
	string acctNumber;
	const double acctBalance, acctInterest, acctMaturity;

public:
	CDAccount(string& acctNumber_, double& acctBalance_, double& acctInterest_, double& maturityMonths_) :
		acctNumber(acctNumber_),
		acctBalance(acctBalance_),
		acctInterest(acctInterest_),
		acctMaturity(maturityMonths_) {}
	~CDAccount() = default;

	double getBalanceAtMaturity()
	{
		// balance *rate *term/12.0

		return acctBalance;
	}

	// Get functions for the 4 properties
	string getAcctNumber()
	{
		return acctNumber;
	}

	double getBalance()
	{
		return acctBalance;
	}

	double getInterestRate()
	{
		return acctInterest;
	}

	double getMaturityMonths()
	{
		return acctMaturity;
	}
};

#endif