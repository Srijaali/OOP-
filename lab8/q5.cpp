/*
Name: Syeda Rija Ali
ID:23K-0057
desc:  inheritance between cars and their types
LAB 8 Q5
*/

#include <iostream>
#include <string>

using namespace std;

class Vehicle{
    protected:
    string make;
    string model;
    int year;

    public:
    Vehicle(string make, string model , int year) :
    make(make) , model(model) , year(year) {}

    void displayVehicle() {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle{
    protected:
    int num_doors;
    int fuel_efficiency;

    public:
    Car(string make,string model,int year,int num_doors,int fuel_efficiency) :
    Vehicle(make,model,year) , num_doors(num_doors), fuel_efficiency(fuel_efficiency) {}

    void displayCar(){
        Vehicle :: displayVehicle();
        cout << "Number of Doors: " << num_doors << endl;
        cout << "Fuel Efficiency: " << fuel_efficiency << endl;
    }
};

class ElectricCar : public Car{
    protected:
    int battery_life;

    public:
    ElectricCar(string make, string model , int year, int num_doors , int fuel_efficiency , int battery_life) :
    Car(make,model,year,num_doors,fuel_efficiency) , battery_life(battery_life) {}

    void displayElectricCar() {
        Car :: displayCar();
        cout << "Battery Life: " << battery_life << endl;
    }
};

int main() {
    ElectricCar ec("Audi" , "RS5" , 2024 , 4 , 40 , 100);
    ec.displayElectricCar();

    return 0;
    
}

