/*
Name: Rija Ali
ID: 23k-0057
desc: a software module for a geometry library that calculates the
areas and perimeters of various shapes.
*/

#include <iostream>
using namespace std;

const double pi = 3.142;

class Shape{
    private:
    int r;
    int l;
    int w;
    float b;
    int h;
    float cons;
    
    public:
    
    Shape(){}

    void area(int r){
        int area = pi*r*r;
        cout << "The area of Circle is: " << area << endl;
    }

    void area(int l, int w){
        int area = l*w;
        cout << "The area of Square is: " << area << endl;
    }

    void area(float b,int h , float cons){
        //float f = 0.5;
        float area = cons*b*h;
        cout << "The area of Triangle is: " << area << endl;
    }

    void perimeter(int r){
        int per = 2*pi*r;
        cout << "The Perimeter of Circle is: " << per << endl;
    }

    void perimeter(int l,int w){
        int per = (2*l) + (2*w);
        cout << "The Perimeter of Square is: " << per << endl;
    }

    void perimeter(int b,int hyp, int c){
        int per = hyp+b+c;
        cout << "The Perimeter of Triangle is: " << per << endl;
    }
};

int main(){
    Shape shape;
    shape.area(2);
    shape.area(2,4);
    shape.area(3.2,2,0.5);

    shape.perimeter(3);
    shape.perimeter(2,6);
    shape.perimeter(10,5,7);

}
