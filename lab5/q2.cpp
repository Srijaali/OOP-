/*
Name : Syeda Rija Ali
ID : 23K-0057
DESC: calculating loan payments
*/

#include <iostream>
using namespace std;

class LoanHelper{
    private:
    int loanAmount;
    int months; // the months user will repay the loan in

    public:
    const float interestRate;
    LoanHelper(): interestRate(0.2) , loanAmount(0), months(0) {}
       
    LoanHelper(int loanAmount, int months): interestRate(0.2) , loanAmount(loanAmount) , months(months) {}

    void setLoanAmount(int loanAmount){
        this-> loanAmount = loanAmount;
    }

    int getLoanAmount(){
        return this -> loanAmount;
    }

    void setMonths(int months){
        this -> months = months;
    }

    int getMonth(){
        return this -> months;
    }

    int loanRepayment(int loanAmount, const float interestRate, int months){
       return  (loanAmount / months) * interestRate;  
    }
};

int main(){
   
    LoanHelper l1;

    l1.setLoanAmount(4000);
    l1.setMonths(3);

    cout << "You have taken " << l1.getLoanAmount() << " and you have " << l1.getMonth() << " months to repay your loan." << endl;

    cout << "You have to pay " << l1.loanRepayment(l1.getLoanAmount(),l1.interestRate, l1.getMonth()) << " every month for the next " << l1.getMonth() << " months to repay your loan!"<< endl;

    return 0;

}
