/*
Name: Syeda Rija Ali
ID: 23K-0057
Desc:  program to show the working of friend class.
*/

#include <iostream>
using namespace std;

class Perimeter{
    private:
    int length;
    int breadth;

    public:
    Perimeter(int length, int breadth) : length(length) , breadth(breadth) {}

    int calcPeri() const {
        return 2*length + 2*breadth;
    }

    friend class Printclass;
};

class Printclass{
    public:

    void Display(const Perimeter& obj){
        cout << "Perimeter is: " << obj.calcPeri();
    }
};

int main(){
    Perimeter per(2,4);
    Printclass pri;

    pri.Display(per);

    return 0;
}
