/*
Name : Syeda Rija Ali
ID : 23K-0057
DESC: calculating area of 3 different squares
*/

#include <iostream>
using namespace std;

class Square{
    private:
    float sideLength;
    float area;
    static float allareas;

    public:
    Square(){ // default constructor called
        sideLength = 0.0; 
        area = 0.0;      
    };

    Square( float sideLength){ //parameterised constructor called
       this -> sideLength = sideLength;
       area = calculateArea(sideLength);
       allareas += area;
    }

   void setSidelength(float sideLength){
       this -> sideLength = sideLength;
       area = calculateArea(sideLength); //so when the value of sidelength is  changed the value of area also changes
       allareas += area;
    }

    float getsideLength(){
        return this->sideLength;
    }

    void setArea(float area){
        this -> area = area;
    }

    float getArea(){
        return this->area;
    }

  static float getAllAreas(){
        return  allareas;
   }

private:
  static float calculateArea(float sideLength){
      return sideLength*sideLength;  
    }

};

    float Square :: allareas = 0.0;

int main(){
    
     Square s1;
     Square s2;
     Square s3;

     s1.setSidelength(2); 
    s2.setSidelength(4);
     s3.setSidelength(6);

    cout << "area of s1 is: " <<  s1.getArea() << endl;
    cout << "area of s2 is: " <<  s2.getArea() << endl;
    cout << "area of s3 is: " <<  s3.getArea() << endl;
    cout << "total area: " << Square::getAllAreas() << endl;

    return 0;


}
