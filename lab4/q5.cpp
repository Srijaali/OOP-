/*
Name: Rija Ali
Desc: DMA fo rarray memory allocation
*/

#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

class office{
    string location;
    int seatingspace;
    string* furniture;
    
    public:
    office(string loc="",int seatcap=0,int count=0):location(loc),seatingspace(seatcap){
        furniture=new string[count];
    }


    void print(){
        cout<<"Location: "<<location<<endl;
        cout<<"Seating Capacity: "<<seatingspace<<endl;
        cout<<"Furniture List: "<<endl;
        for(int i=0;i<3;i++){
            cout<<furniture[i];
            cout<<endl;
        }
    }

~office(){
    delete[] furniture;//deallocating furninture's memory
    cout<<"Furniture list deleted.\n";
}
};
int main(){
    office *officeptr=new office("DHA Phase 6",50,3);

    cout << "Office Info:" << endl;
    officeptr->print();

    delete officeptr;//deleting object's memory

    return 0;
}
