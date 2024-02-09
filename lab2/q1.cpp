#include <iostream>
using namespace std;

void recursiveSwap(int &a, int &b) {
	if(a==b){
		return;
	}
    else if (a > b) {
    
        a = a - b;
        b = b + a;
        a = b - a;
    } 
   
    else {
			recursiveSwap(b,a);
        }
}

int main() {
    int a;
	int b;

cout<<"Enter num 1: ";
cin>>a;

cout<<"Enter num 2: ";
cin>>b;
    
cout << "Before swapping:\n";
cout<<"A = " << a <<"\n";
cout<<"B = " << b <<endl;
    
    recursiveSwap(a, b);
    
cout << "After swapping:\n"; 
cout<<"A = " << a <<"\n";
cout<<"B = " << b <<endl;
    
    return 0;
}

