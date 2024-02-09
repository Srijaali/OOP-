#include <iostream>
using namespace std;

class BoardMarker{
    private:

    string brand;
    string shade;
    bool refillable;
    bool inkstatus;


    public:

    BoardMarker(string Brand, string Shade, bool refill, bool ink){
        brand = Brand;
        shade = Shade;
        refillable = refill;
        inkstatus = ink;

    }

     void setbrand(string brand){
        brand = Brand;
    }

    string getbrand(){
        return brand;
    }

    void setshade(string shade){
        shade = Shade;
    }

    string getshade(){
        return shade;
    }

    bool setrefillable(bool refillable){
        refillable = refill;
    }

    bool getrefillable(){
        return refillable;
    }

     bool setinkstatus(bool inkstatus){
        inkstatus = ink
    }

    bool getrinkstatus(){
        return inkstatus;
    }

    void written(bool inkstatus){
        if (inkstatus==true){
            cout << "Ink is present in " << shade << " brand name" << Brand;

        }
        else{
            cout << "marker has no ink";
        }
    }

    void refill(bool refillable){
        if(refill==true){
            cout << " refill the marker";
            inkstatus = true;
            cout<< "refilled!";
        }
        else{
            cout << "not refillable";
        }
    }

};

int main(){

     BoardMarker marker("Dollar", "Black", true, true);

     marker.written("Dollar");
     marker.refill();
    

     return 0;

}
