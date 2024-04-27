/*
Name: Syeda Rija Ali
ID: 23K-0057
Desc:  operator overloading.
*/

#include <iostream>
#include <string>
using namespace std;

class Shape{
    int length;
    int breadth;
    int area;

    public:
    Shape(int length, int breadth) : length(length) , breadth(breadth) {
        area =  length*breadth;
    }

    Shape operator+(const Shape& s) const {
       Shape temp(length + s.length , breadth +s.breadth );
        temp.area = area + s.area;
        return temp;
       
    }

    void Display()const{
        cout << "Area is: " << area << endl;
    }
}; 

int main(){
    Shape shape1(10,12) , shape2(4,8);
    
    shape1.Display();
    shape2.Display();

    Shape shape3 = shape1 + shape2;
   cout << "Combined" ;
   shape3.Display();

   return 0;
    
}
