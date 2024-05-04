/*
Name: Syeda Rija Ali
ID: 23k-0057
Desc:  a project that requires you to design a system for managing different types of bank accounts.
*/

#include <iostream>
using namespace std;

class Account{
    protected:
    int accountNumber;
    double balance;

    public:
    Account(int accountNumber, double balance) : accountNumber(accountNumber) , balance(balance) {}

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void calculateInterest() = 0;

    int getAccountNumber(){
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

};


class SavingsAccount : public Account{
    private:
    double interestRate;

    public:
    SavingsAccount(int accountNumber,double balance , double interestRate) : Account(accountNumber,balance) , interestRate(interestRate) {}

    void deposit(double amount) override {
        cout << "Depositing Amount.." << endl;
        balance += amount;
        cout << "Current balance = " << balance << endl;
    }

    void withdraw(double amount)  override {
              if(amount <= balance){
            balance -= amount;
            cout << "Withdrawal Successful!" << endl;
            cout << "Current balance = " << balance << endl;
        }
        else {
            cout << "Withdrawal not possible due to Insufficient amount!!" << endl;
        }
    }

    void calculateInterest()  override {
        double interest;
        int tp;

        cout << "Enter the time period for which you want to calculate the interest(in years): " << endl;
        cin >> tp;

        interest = balance*interestRate*tp;
        cout << "The interest is: " << interest << endl;
    }
};

class CurrentAccount : public Account{
        private: 
        double overdraftLimit;
        double interestRate;

        public:
        CurrentAccount(int accountNumber , double balance , double overdraftLimit , double interestRate) : Account(accountNumber,balance) , overdraftLimit(overdraftLimit) , interestRate(interestRate) {}

        void deposit(double amount) override {
        balance += amount;
        cout << "Amount deposited successfully!" << endl;
        cout << "Current balance = " << balance << endl;
    }

       void withdraw(double amount) override {

        if(amount <= balance){
            balance -= amount;
            cout << "Withdrawal Successful!" << endl;
            cout << "Current balance = " << balance << endl;
        }
        else if(amount <= overdraftLimit) {
            balance = overdraftLimit - amount;
            cout << "Withdrawal possible from Overdraft Limit amounts!" << endl;
        }
        else {
            cout << "Insufficient amount and insufficient Overdraft limit!" << endl;
        }
    }

      void calculateInterest()  override {
        double interest;
        int tp;

        cout << "Enter the time period for which you want to calculate the interest(in years): " << endl;
        cin >> tp;

        interest = balance*interestRate*tp;
        cout << "The interest is: " << interest << endl;
    }
};

int main(){
   cout << "SAVINGS ACCOUNT: " << endl;
   SavingsAccount sa(1001 , 5000 , 0.05);
   Account *a1;
   a1 = &sa;
   a1 -> deposit(500);
   a1 -> withdraw (100);
   a1 -> calculateInterest(); 
    cout << endl;
   cout << "CURRENT ACCOUNT: " << endl;
   CurrentAccount ca(1002 , 500 , 700 , 0.02 );
   Account * a2;
   a2 = &ca;
   a2 -> deposit(200);
   a2 -> withdraw(500);
   a2 -> calculateInterest();

   return 0;

}
