/*
NAME: Rija Ali
ID: 23k-0057
Desc: finding LCM and GCD recursively
*/


#include <iostream>
using namespace std;

int calculateGCD(int n1, int n2) {
    if (n2 != 0){
        return calculateGCD(n2, n1 % n2);
    }    
    else{
        return n1;// when num2==0
    }
}

int calculateLCM(int n1, int n2) {

    int gcd = calculateGCD(n1, n2);

    int lcm = (n1 * n2) / gcd;

    return lcm;
}

int main() {
    int n1, n2;
    int LCM, GCD;

    cout << "Enter the two numbers to find their GCD and LCM: ";
    cin >> n1 >> n2;

    LCM=calculateLCM(n1,n2);
    GCD = calculateGCD(n1, n2);

    cout << "GCD is: " << GCD << endl;
    cout << "LCM is: " << LCM;

    return 0;
}
