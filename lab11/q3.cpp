/*
Name: Syeda Rija Ali
ID: 23k-0057
Desc: a project that involves managing different types of vehicles, such as cars, trucks, and motorcycles. 
*/

#include <iostream>
using namespace std;

class Vehicles{
    protected:
    string make;
    string model;
    int speed;

    public:
    Vehicles(string make , string model , int speed) : make(make) , model(model) , speed(speed) {}

    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void calculateFuelEfficiency() = 0;

    string getMake(){
        return make;
    }
    string getModel() {
        return model;
    }
    int getSpeed() {
        return speed;
    }

};

class Car : public Vehicles{
    private:
    double fuelcapacity;

    public:
    
    Car(string make , string model , int speed, double fuelcapacity) : Vehicles(make,model,speed) , fuelcapacity(fuelcapacity) {}

    void accelerate() override {
        cout << "The car is Accelerating..." << endl;
        speed += 5;
        cout << "Speed is now " << speed << "Km/h" << endl;
    }

    void brake() override {
        cout << "Brakes are being applied..." << endl;
        speed -= 10;
        cout << "Speed is now " << speed << "km/h" << endl;
    }

    void calculateFuelEfficiency() override {
        double effieciency;
        effieciency = fuelcapacity/speed;
        cout << "Fuel Efficiency is: " << effieciency << " km/l" << endl;
    }
};

class Truck : public Vehicles {
    private:
    int cargoCapacity;
    int fuelcapacity;

    public:

    Truck(string make, string model , int speed , int cargoCapacity , int fuelcapacity) : Vehicles(make,model,speed) , cargoCapacity(cargoCapacity) , fuelcapacity(fuelcapacity) {}

     void accelerate() override {
        cout << "The Truck is Accelerating..." << endl;
        speed += 15;
        cout << "Speed is now " << speed << "Km/h" << endl;
    }

    void brake() override {
        cout << "Brakes are being applied..." << endl;
        speed -= 15;
        cout << "Speed is now " << speed << "km/h" << endl;
    }

    void calculateFuelEfficiency() override {
        float effieciency;
        effieciency = fuelcapacity/speed;
        cout << "Fuel Efficiency is: " << effieciency << " km/l" << endl;
    }
};

int main() {
    cout << "Vehicle Car:" << endl;
    Car c( "2005" , "AMG" , 120 , 50.0);
    Vehicles *v;
    v = &c;
    v -> accelerate();
    v -> brake();
    v -> calculateFuelEfficiency();

    cout << endl;
    cout << "Vehicle Truck: " << endl;
    Truck t("2011" , "FORD" , 80 , 200 , 100);
     v = &t;
    v -> accelerate();
    v -> brake();
    v -> calculateFuelEfficiency();

    return 0;
}
