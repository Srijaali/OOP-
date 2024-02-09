#include <iostream>
using namespace std;

int recursiveswap(int& a,int& b){
   int temp;
    if(a==b){
        return 0;//base case to return/exit if the integers are same
    }
    else {
        
        temp = a;
        a = b;
        b = temp;
    recursiveswap(b,a)

    }
 
}

int main() {
    int a = 6;
    int b = 2;
    int temp;

    cout << "Before swapping: \n";
    cout << "A = " << a << "\n";
      cout << "B = " << b << endl;

      recursiveswap(a,b);

      cout<< "After swapping:\n";
      cout<< "A = " << a << "\n";
        cout<< "B = " << b << "\n";

}
