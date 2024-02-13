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

     void setbrand(string Brand){
        brand = Brand;
    }

    string getbrand(){
        return brand;
    }

    void setshade(string Shade){
        shade = Shade;
    }

    string getshade(){
        return shade;
    }

    bool setrefillable(bool refill){
        refillable = refill;
    }

    bool getrefillable(){
        return refillable;
    }

     bool setinkstatus(bool ink){
        inkstatus = ink;
    }

    bool getrinkstatus(){
        return inkstatus;
    }

    void written(bool inkstatus){
        if (inkstatus==true){
            cout << "Ink is present in " << shade <<  brand << " Marker" <<endl;

        }
        else{
            cout << "marker has no ink";
        }
    }

    void refill(bool refillable){
        if(refillable==true){
            cout << "refill the marker"<<endl;
            inkstatus = true;
            cout<< "refilled!"<<endl;
        }
        else{
            cout << "not refillable";
        }
    }

};

int main(){

     BoardMarker marker("Dollar", "Black", true, true);

     marker.written("Dollar");
     marker.refill(1);
    

     return 0;

}
