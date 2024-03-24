/*
Name: Syeda Rija Ali
ID: 23K-0057
desc: hair salo program to note the appointment details and calculate earnings and avg cost 
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Appointment{
    private:
        string name;
        string service;
        int price;
        static int total_appointments;
       static int total_earnings;
    public:
        Appointment(string name,string service, int price){
            this -> name = name;
            this -> service = service;
            this -> price = price;
            total_appointments++;
            total_earnings += price;
        }

        static int avg_cost(){
            if(total_appointments == 0){
                return 0;
            }
            else{
                return total_earnings/total_appointments;
            }
        }

        void display(){
            cout << "Appointment Details: " << endl;
            cout << "Name: " << name << endl;
            cout << "Service Taken: " << service << endl;
            cout << "Price: " << price << endl;
        }
};


int Appointment :: total_appointments = 0;
int Appointment :: total_earnings = 0;
int main(){

    Appointment a1("Raha", "Hair color", 4500);
    Appointment a2("Ahmed", "Hair cut", 390);
    Appointment a3("Areefa" , "Straightening", 3600);

    a1.display();
    cout << endl;
    a2.display();
    cout << endl;
    a3.display();
     cout << endl;

//calculate avg cost:
    cout << "Average cost: " << Appointment::avg_cost() << endl;
}
       
