/*
Name: Syeda Rija Ali
ID: 23K-0057
*/

#include <iostream>
using namespace std;

class RollerCoaster {
public:
    string name;
    int height, length, currentNumRiders, capacity;
    int speed;
    bool rideInProgress;

    RollerCoaster() : name("roller coaster"), height(500), length(200), capacity(20), speed(0), rideInProgress(false) {}

    RollerCoaster(string name, int height, int length, int capacity)
        : name(name), height(height), length(length), speed(0), rideInProgress(false)
    {
        this->capacity = capacity % 3 == 0 || capacity % 2 == 0 ? capacity : capacity - 1;
    }

    string getname() {
        return name;
    }
    void setname(string name) {
        this->name = name;
    }

    int getheight() {
        return height;
    }
    void setheight(int height) {
        this->height = height;
    }

    int getlength() {
        return length;
    }
    void setlength(int length) {
        this->length = length;
    }

    int getspeed() {
        return speed;
    }
    void setspeed(int speed) {
        this->speed = speed;
    }

    int getcap() {
        return capacity;
    }
    void setcap(int capacity) {
        this->capacity = capacity % 3 == 0 || capacity % 2 == 0 ? capacity : capacity - 1;
    }

    int getCurrentNumRiders() {
        return currentNumRiders;
    }
    void setCurrentNumRiders(int currentNumRiders) {
        this->currentNumRiders = currentNumRiders;
    }

    bool isRideInProgress() {
        return rideInProgress;
    }
    void setRideInProgress(bool rideInProgress) {
        this->rideInProgress = rideInProgress;
    }

    int seatriders(int riders) {
        if (rideInProgress) {
            cout << "Ride is in progress\n" << endl;
            return capacity;
        }

        this->setCurrentNumRiders(riders > capacity ? capacity : riders);
        return riders >= capacity ? riders - capacity : 0;
    }

    int start() {
        if (rideInProgress) {
            cout << "\n Ride is in progress\n" << endl;
            return -1;
        }

        this->setRideInProgress(true);
        return currentNumRiders != capacity ? capacity - currentNumRiders : 0;
    }

    void stop() {
        if (rideInProgress) this->setRideInProgress(false);
    }

    void unload() {
        if (!rideInProgress) this->setCurrentNumRiders(0);
    }

    void accelerate(string roll) {
        for (int i = 4 - 1; i >= 0; i--) {
            if (roll[i] == '0') {
                continue;
            } else {
                int digit = roll[i] - '0';
                int newSpeed = speed + digit;
                setspeed(newSpeed);
                return;
            }
        }
    }

    void decelerate(string roll) {
        for (int i = 0; i < 4; i++) {
            if (roll[i] == '0') {
                continue;
            }
            int digit = roll[i] - '0';
            int newSpeed = speed - digit;
            setspeed(newSpeed);
            return;
        }
    }
};

int main()
{
    RollerCoaster obj1;
    RollerCoaster obj2("\n SPEEDOO roller coaster ", 800, 1500, 31);

    cout << obj2.getname() << " has capacity of " << obj2.getcap() << " seats." << endl;

    obj2.start();
    obj2.seatriders(27);
    obj2.stop();

    cout << "Riders not seated: \n" << obj2.seatriders(39) << endl;
    cout << "Current riders: \n" << obj2.getCurrentNumRiders() << endl;
    cout << "Unoccupied seats:\n " << obj2.start() << endl;

    cout << "Speed Initially: \n" << obj2.getspeed() << endl<<endl;

    for (int i = 0;i<5;i++)
    obj2.accelerate("0057");
    cout << "Speed after acceleration: \n" << obj2.getspeed() << endl<<endl;

    for (int i = 0;i < 7;i++)
    obj2.decelerate("0057");
    cout << "Speed after deceleration: \n" << obj2.getspeed() << endl<<endl;

    obj2.stop();
    cout<<"Ride stopped.\n"<<endl;
    cout << "Ride status: \n" << obj2.isRideInProgress() << endl<<endl;

    obj2.unload();
    cout<<"Riders unloaded.\n"<<endl;
    cout << "Current riders: \n" << obj2.getCurrentNumRiders() << endl;

    return 0;
}
