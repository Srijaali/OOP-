#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    private:
    
     long accountNumber;
     string accountHolderName;
     float balance;

    public:

    BankAccount(long accountNumber, string accountHolderName, float balance)
    {
            this-> accountNumber = accountNumber;
            this -> accountHolderName = accountHolderName;
            this -> balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount){
        if(amount <= balance){
            cout << "Withdrawal Successful!!" << endl;
            balance -= amount;
        }else{
            cout << "Insufficient amount!" << endl;
        }
    }

    void display(){
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Number is: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount accounts[3] = {
        BankAccount(12345, "Ali", 1500.0),
        BankAccount(54321, "Babar", 2050.0),
        BankAccount(98765, "Noman", 1700.0)
    };

    for (int i = 0; i < 3; ++i) {
        cout << "Account Details for Account " << i + 1 << ":" <<endl;
        accounts[i].display();
        cout << endl;
    }

    for (int i = 0; i < 3; ++i) {
        cout << "Transaction Details for Account " << i + 1 << ":" << endl;
        accounts[i].deposit(500.0);
        cout << "After deposit:" << endl;
        accounts[i].display();

        accounts[i].withdraw(200.0);
        cout << "After withdrawal:" << endl;
        accounts[i].display();
        cout << endl;
    }

    return 0;
}
