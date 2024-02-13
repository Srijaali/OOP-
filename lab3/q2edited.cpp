#include <iostream>
#include <string>

using namespace std;

class Waterbottle{
private:
string company;
string color;
int watercap_inL;
int watercap_inMl;

public:

Waterbottle(string Company,string Color, int watercapacityinL, int watercapacityinMl)
    : company(Company), color(Color), watercap_inL(watercapacityinL), watercap_inMl(watercapacityinMl) {}

void setcompany(string Company){
    company = Company;
}

string getcompany(){
    return company;
}

void setcolor(string Color){
    color = Color;
}

string getcolor(){
    return color;
}

void watercap_inLset(int watercapacityinL){
    watercap_inL =  watercapacityinL;
}

int watercap_inLget(){
    return watercap_inL;
}

void watercap_inMlset(int watercapacityinMl){
   watercap_inMl = watercapacityinMl;
}

int watercap_inMlget(){
    return watercap_inMl;
}
};

int main(){
     
     Waterbottle bottle("AQUA", "BLUE", 0, 0);

     bottle.setcompany("AQUA");
     bottle.setcolor("BLUE");
     bottle.watercap_inLset(1);
     bottle.watercap_inMlset(500);

     cout<< "company: " << bottle.getcompany() << endl;
     cout<< "color: " << bottle.getcolor() << endl;
     cout<< "capacity in Litre: " << bottle.watercap_inLget() << endl;
      cout<< "capacity in MilliLitre: " << bottle.watercap_inMlget() << endl;

    return 0;
} 
