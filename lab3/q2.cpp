#include <iostream>
#include <string>

using namespace std;

class Waterbottle{

string company;
string color;
int watercap_inL;
int watercap_inMl;

void setcompany(string company){
    company = Company;
}

string getcompany(){
    return company;
}

void setcolor(string color){
    color=Color;
}

string getcolor(){
    return color;
}

void watercap_inLset(int watercap_inL){
    watercap_inL =  watercapacityinL
}

int watercap_inLget(){
    return watercap_inL;
}

void watercap_inMlset(int watercap_inL){
   watercap_inMl = watercapacityinMl
}

int watercap_inMlget(){
    return watercap_inMl;
}
};

int main(){
     
     Waterbottle bottle;

     bottle.setcompany("AQUA");
     bottle.setcolor("BLUE");
     bottle.watercap_inLset(1);
     bottle.watercap_inMlset(500);

     cout<< "company: " << bottle.getcompany() << endl;
     cout<< "color: " << bottle.getcolor() << endl;
     cout<< "capacity in Litre: " << bottle.watercap_inLget() << endl;
      cout<< "capacity in Litre: " << bottle.watercap_inMlget() << endl;

    return 0;
}
