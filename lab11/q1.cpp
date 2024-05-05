/*
Name: Syeda Rija Ali
ID: 23k-0057
Desc: conversion of units using polymorphism and pointer to base class
*/

#include <iostream>
using namespace std;

class Convert{
    protected:
    int val1; //initial value
    float val2; // converted value

    public:
    Convert(int val1, float val2 = 0) : val1(val1) , val2(val2) {}

    virtual void compute() {}
};

class L_to_G : public Convert{
    public:
    L_to_G(int val1) : Convert(val1) {}

    void compute() override {
        const float ratio = 0.264172;

        val2 = val1*ratio;

        cout << "The converted value is " << val2 << " gallons." << endl;

    }
};

class F_to_C : public Convert{
    public:
    F_to_C (int val1) : Convert(val1) {}
    void compute()override{
        val2 = (val1-32)*0.555;

        cout << "The converted value is " << val2 << " degrees." << endl;

    }
};

int main(){
    //Convert c;
    L_to_G lg(5);
    F_to_C fc(5);
    
    cout << "Litres to Gallons:" << endl;
    Convert* cptr;
    cptr = &lg;
    cptr -> compute();

    cout << "Farenheit to Celsius:" << endl;
    cptr = &fc;
    cptr -> compute();

    return 0;

}
