/*
Name: Syeda Rija Ali
ID: 23K-0057
Desc:  program to show the working of friend class.
*/

#include <iostream>
#include <string>
using namespace std;

class Overload{
    int num;

    public:
    Overload(int num) : num(num){}

// when used as a prefix
    Overload operator--(){
        Overload temp(num);
        num = num*4;
        return temp;
    }
// when used as a postfix
    Overload operator--(int){
        Overload temp(num);
        num = num/4;
        return temp;
    }

    void display(){
        cout << "Number is: " << num << endl;
    }
};

int main() {
    Overload n1(8);
    cout << "Original " ;
    n1.display();

    --n1;
    cout << "When using decrement operator as a PREFIX: " << endl;
    n1.display();

    n1--;
    cout << "When using decrement operator as a POSTFIX: " << endl;
    n1.display();

    return 0;

}

