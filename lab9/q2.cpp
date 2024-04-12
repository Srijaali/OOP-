/*
Name: Rija Ali
ID: 23k-0057
desc: developing a geometry application that helps users calculate
properties of various shapes.
*/

#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.142;

class Shape{
    public: 

    virtual double area() const {
        cout << "The area of the shape is: "<< endl;
    }

    virtual double perimeter() const {
        cout << "The perimeter of the shape is: "<< endl;
    }

    virtual void displayProperties() const {
        //cout << "The properties of " << shape << endl;
        cout << "Properties are: " << endl;
        // cout << "Area: " << area << endl;
        // cout << "Perimeter: " << perimeter << endl;
    }

};

class Circle : public Shape {
    private:
    int radius;

    public:
    Circle(int radius) : radius(radius) {}

    double area ()const override {
        return pi*radius*radius;
    }

    double perimeter()const override {
        return 2*pi*radius;
    }

    void displayProperties()const override {
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
        cout << "Diameter: " << 2*radius << endl;
    }
};

class Rectangle : public Shape{
    private:
    int length;
    int width;

    public:

    Rectangle(int length , int width) : length(length) , width(width) {}

    double area()const override {
        return length*width;
    }

    double perimeter()const override {
        return 2*(length+width);
    }

    void displayProperties()const override {
        cout << "area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class Square : public Shape {
    private:
    int length;

    public:
    Square(int length) : length(length) {}

    double area() const override {
        return length*length;
    }

    double perimeter() const override {
        return 4*length;
    }

    void displayProperties() const override {
        cout << "area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class Triangle : public Shape {
    private:
    int base;
    int height;
    int hyp;

    public:
    Triangle(int base, int height , int hyp) : base(base) , height(height) , hyp(hyp) {}

    double area() const override {
        return 0.5*base*height;
    }

    double perimeter() const override {
        return base+height+hyp;
    }

    void displayProperties()  const override {
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class EquilateralTriangle : public Triangle {
    private:
    int side;
    
    public:
    EquilateralTriangle(int side) : Triangle(side,side,side){}

    double area() const override{
        return (sqrt(3)/4) *side*side;
    }

    double perimeter() const override {
        return 3*side;
    }

    void displayProperties() const override {
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

int main() {
    
    Shape *shape;
    Triangle *tri;
    
    int choice;
    cout << "1.Circle\n" << "2.Rectangle\n" << "3.Square\n" << "4.Triangle\n" << "5.Equilateral Triangle\n" << endl; 
    cout << "Choose the shape you want calculate area and perimeter of: " << endl;
    cin >> choice;

    switch(choice) {

    case 1:{
       Shape* s = new Circle(2);
       s -> displayProperties();
       delete s;
       break;
        }

        case 2: {
            Shape* s = new Rectangle(2,4);
            s->displayProperties();
            delete s;
            break;
        }

        case 3:
        {
        Shape* s = new Square(2);
        s->displayProperties();
        delete s;
         break;
       }

       case 4:
       {
        Shape* s = new Triangle(3,2,7);
        s-> displayProperties();
        delete s;
         break;
       }

       case 5:
       {
        Shape* s = new EquilateralTriangle(5);
        s->displayProperties();
        delete s;
         break;
       }

       default:
       cout << "INvalid" << endl;
       return 1;
    }



    return 0;
}
