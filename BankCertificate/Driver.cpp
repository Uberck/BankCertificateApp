#include <iostream>
#include <limits>
#include "BankCertificate.h"

using namespace std;

int main() {

    float acctNumber, acctBalance, acctInterest, acctMaturity;

num:                                            // Account number section
    cout << "Please enter your account number:";
    cin >> acctNumber;                          // Store account balance input
    if (cin.fail()) {                           // Checks that the balance entered is indeed a number
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Please enter a 'whole' account number between 99 and 99999:" << endl;
        goto num;
    }
    if (acctNumber < 99 || acctNumber > 100000) // Checks that the acct# is not a number less than 99 or greater than 99999
    {
        cout << endl << "Please enter an account number greater than 99 & less than 99999:" << endl;
        goto num;
    }

bal:                                            // Balance section
    cout << "Please enter your initial account balance (in $):";
    cin >> acctBalance;                         // Store account balance input
    if (cin.fail()) {                           // Checks that the balance entered is indeed a number
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Please pick a 'whole' balance number between 1 and 100000:" << endl;
        goto bal;
    }
    if (acctBalance < 1 || acctBalance > 100000) // Checks that the balance entered is not a number less than 1 or greater than 100000
    {
        cout << endl << "Please enter a numeric account balance greater than 0 & less than 100,000:" << endl;
        goto bal;
    }

rate:                                           // Interest rate section
    cout << "Enter the account interest rate (0-1000):";
    cin >> acctInterest;                        // Store account interest rate input
    if (cin.fail()) {                           // Checks that the interest rate entered is indeed a number
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Please pick a 'whole' interest number between 0 and 1000:" << endl;
        goto rate;
    }
    if (acctInterest < 0 || acctInterest > 1000) // Checks that the interest rate entered is not less than 0 or greater than 1000
    {
        cout << endl << "Please enter a valid interest rate between 0 & 1000:" << endl;
        goto rate;
    }

mature:
    cout << "Enter the number of months until maturity" << endl << "(Must be 12 or fewer months):";
    cin >> acctMaturity;                        // Take input for term
    if (cin.fail()) {                           // Checks that the number of months entered is indeed a number
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Please pick a number for the months between 1-12:" << endl;
        goto mature;
    }
    if (acctMaturity < 1 || acctMaturity > 12)  // Check that months entered is not less than 1 or greater than 12
    {
        cout << endl << "Please enter a valid number of months between 1 & 12." << endl;
        goto mature;
    }

    CDAccount cd(acctNumber, acctBalance, acctInterest, acctMaturity);  // Constructing the CDAccount object
    cd.calcInterest();                                                  // Calling the function to calculate interest

    return 0;
}