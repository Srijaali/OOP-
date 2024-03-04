/*
Name : Syeda Rija Ali
ID : 23K-0057
DESC: calculating loan payments
*/

#include <iostream>
using namespace std;

class LoanHelper{
    private:
    const float interestRate;
    int loanAmount;
    int months; // the months user will repay the loan in

    public:
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

    int loanRepayment(){
       return  (loanAmount / months) * interestRate;  
    }
};

int main(){
   
    LoanHelper l1;

    l1.setLoanAmount(4000);
    l1.setMonths(3);

    cout << "You have taken " << l1.getLoanAmount() << " rupees loan and you have " << l1.getMonth() << " months to repay it." << endl;

    cout << "You have to pay " << l1.loanRepayment() << " every month for the next " << l1.getMonth() << " months to repay your loan!"<< endl;

    return 0;

}
