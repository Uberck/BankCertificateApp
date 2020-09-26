#ifndef BankCertificate_H
#define BankCertificate_H

#include <iostream>
#include <limits>

using namespace std;

class CDAccount {

private:
    string acctNumber;
    const double balance, interestRate, maturityMonths;

public:
    CDAccount(string& acctNumber_, double& balance_, double& interestRate_, double& maturityMonths_) :
        acctNumber(acctNumber_), 
        balance(balance_),
        interestRate(interestRate_),
        maturityMonths(maturityMonths_)
    {
    }
    ~CDAccount() = default;

    double balanceAtMaturity() {
        // balance * rate * term/12.0
        
        return balance * interestRate * maturityMonths / 12;
    }

    // Get functions for the 4 properties
    string getAcctNumber() {
        return acctNumber;
    }

    double getBalance() {
        return balance;
    }

    double getInterestRate() {
        return interestRate;
    }

    double getMaturityMonths() {
        return maturityMonths;
    }

};

#endif