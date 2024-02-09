#include <iostream>
using namespace std;

class BoardMarker{
    private:

    string brand;
    string shade;
    bool refillable;
    bool inkstatus;


    public:
    string setbrand(string brand){
        brand = Brand;
    }

    string getbrand(){
        return Brand;
    }

    string setshade(string shade){
        shade = Shade;
    }

    string getshade(){
        return Shade;
    }

    bool setrefillable(bool refillable){
        refillable = refill;
    }

    bool getrefillable(){
        return refill;
    }

     bool setinkstatus(bool inkstatus){
        inkstatus = Inkstatus
    }

    bool getrinkstatus(){
        return Inkstatus;
    }

    void written(bool inkstatus){
        if (Inkstatus==true){
            cout << "Ink is present in " << shade << " brand name" << Brand;

        }
        else{
            cout << "marker has no ink";
        }
    }

    void refill(bool refillable){
        if(refill==true){
            cout << " refill the marker";
            Inkstatus = true;
            cout<< "refilled!";
        }
        else{
            cout << "not refillable"
        }
    }

};

int main(){

     BoardMarker marker("Dollar", "Black", true, true);

     marker.written("Dollar");
     marker.refill();
    

     return 0;

}
