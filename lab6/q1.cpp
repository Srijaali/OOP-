/*
Name: Syeda Rija Ali
ID: 23k-0057;
desc: bank managment system using pointer and dma
*/
#include <iostream>
#include <cstring>
using namespace std;

class BankAccount{
    private:
    int accountID;
    double balance;
    int* transactionHistory;
    int numTransactions;

    public:
//parameterised constructor
    BankAccount(int accountID, double balance, int* transactionHistory, int numTransactions){
        this -> accountID = accountID;
        this -> balance = balance;
        this -> numTransactions = numTransactions;
        //DMA to store transaction history
        this -> transactionHistory = new int[numTransactions];
        //copying memory for allocation
        memcpy(this->transactionHistory, transactionHistory, numTransactions*sizeof(int));
    }
//copy constructor
BankAccount(const BankAccount& ba) : accountID(ba.accountID) , balance(ba.balance) , numTransactions(ba.numTransactions){
    transactionHistory = new int[numTransactions];
    memcpy(transactionHistory , ba.transactionHistory , numTransactions * sizeof(int));
}

//destructor

~BankAccount (){
    delete[] transactionHistory;
}

void display(){
    cout << "Account ID: " << accountID << endl;
    cout << "Balance: " << balance << endl;
    cout << "Transaction History: ";
    for(int i=0; i< numTransactions ;i++){
     cout << transactionHistory[i] << " ";
    }
    cout << endl;
}

void updateTransactionHistory(int* transaction, int numtrans){
    delete [] transactionHistory;

    numTransactions = numtrans;
    transactionHistory = new int[numTransactions];
    memcpy(transactionHistory,transaction,numTransactions*sizeof(int));
   }
};

int main(){
   
    int transA[]={-400,200,350};
    int numtransA = sizeof(transA)/sizeof(transA[0]);//to get the size of one data item
    
    BankAccount bA1(123 , 4500 , transA, numtransA );

//copy
    BankAccount bA2 = bA1;
//display:
    cout << "Original Bank Account display:" << endl;
    bA1.display();

    cout << "Copied Bank Account display:" << endl;
    bA2.display();

//update transaction history and display:

    int transB[]={-600,920};
    int numtransB = sizeof(transB)/sizeof(transB[0]);//to get the size of one data item
    bA1.updateTransactionHistory(transB,numtransB);

    cout<< "After updating transaction history: " << endl;
    bA1.display();

    return 0;
}
