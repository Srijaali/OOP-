#include <iostream>
#include <cmath>
using namespace std;

class Drone{
    protected:
    float latitude;
    float longitude;
    float altitude;
    float speed;

    public:
    Drone(double latitude, double longitude, int altitude, int speed) : latitude(latitude), longitude(longitude), altitude(altitude) , speed(speed) {}

    void adjustAltitude(float meters ){
        altitude += meters ;
        cout << "The Altitude is now " << altitude << " meters" << endl;
    }

    void setSpeed(float speed){
        this -> speed = speed;
    }
};

class Flyable{
    public:
   virtual void takeoff() = 0;
   virtual void land() = 0;
   virtual void navigateTo(float latitude , float longitude , float altitude) = 0;
};

class Scannable{
    public:
  virtual void scanArea(float radius) = 0;
};

class ReconDrone : public Drone, public Flyable , public Scannable{
    private:
    int camResolution;
    int maxFlighttime;

    public:
    ReconDrone(float latitude, float longitude, float altitude, float speed, int camResolution, int maxFlighttime) : Drone(latitude,longitude,altitude,speed) , camResolution(camResolution) , maxFlighttime(maxFlighttime) {}

    void takeoff() override {
        cout << "The Drone is taking of..." << endl;
    }

    void navigateTo(float targetlat, float targetlon, float targetalt) override {
        float distance;
        // normal distance formula applied between two coordinates.
        distance =  sqrt(pow(targetlat - latitude , 2) + pow(targetlon - longitude , 2));
        cout << "The distance left is " << distance << " meters" << endl;

        float time;
        time = distance / speed;
        cout << "The time to reach destination is " << time << " seconds" << endl;

    }

    void scanArea(float radius) override {
        cout << "Scanning Area for detection...." << endl;
        int obj = rand() % 100; //to generate a random number of object from 0-100
        if(obj != 0){
            cout << "Detected " << obj << " objects within the radius " << radius << " meter" << endl;
        }
        else{
            cout << "No object detected!" << endl;
        }
    }

    void land() override {
        cout << "The Drone is landing..." << endl;
    }
};

int main(){
    cout<<"SYEDA RIJA ALI [23K-0057]"<<endl<<endl;

    ReconDrone rd(98.7 , -115.4 , 500 , 120 , 32 , 55);
    rd.takeoff();
    rd.navigateTo(100.5 , -15.4 , 700);
    rd.scanArea(8);
    rd.land();

    return 0;
}

