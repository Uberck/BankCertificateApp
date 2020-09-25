#ifndef BankCertificate_H
#define BankCertificate_H

#include <iostream>
#include <limits>

using namespace std;

class CDAccount {

private:
    float acctNumber_, acctBalance_, acctInterest_, acctMaturity_;
    double interest, balance;
public:
    CDAccount(float& acctNumber, float& acctBalance, float& acctInterest, float& acctMaturity) :
        acctNumber_(acctNumber), acctBalance_(acctBalance), acctInterest_(acctInterest), acctMaturity_(acctMaturity), interest(0.0), balance(0.0) {}~CDAccount() =
        default;

    // Getter functions for the 4 properties
    float getAcctNumber() {
        return acctNumber_;
    }

    float getAcctBalance() {
        return acctBalance_;
    }

    float getAcctInterest() {
        return acctInterest_;
    }

    float getAcctMaturity() {
        return acctMaturity_;
    }

    // Setter functions for the 4 properties
    void setAcctNumber(const float& an) {
        acctNumber_ = an;
    }

    void setAcctBalance(const float& ab) {
        acctBalance_ = ab;
    }

    void setAcctInterest(const float& ai) {
        acctInterest_ = ai;
    }

    void setAcctMaturity(const float& am) {
        acctMaturity_ = am;
    }

    void calcInterest();
};

#endif