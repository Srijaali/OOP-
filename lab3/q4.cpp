/*
Name: Syeda Rija Ali
desc: Phone mangement system
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Smartphone{
private:
    string brand;
    string model;
    int displayResolution;
    int ram;
    int rom;
    int storage;

public:
    Smartphone(string Brand = "", string Model = "", int DisplayResolution = 0, int Ram = 0, int Rom = 0, int Storage = 0) 
    :brand(Brand), model(Model), displayResolution(DisplayResolution), ram(Ram), rom(Rom), storage(Storage) {}

//setter methods:
    void setBrand(string Brand)
    {
        brand = Brand;
    }

    void setModel(string Model)
    {
        model = Model;
    }

    void setDisplayresolution(int DisplayResolution)
    {
        displayResolution = DisplayResolution;
    }

    void setRam(int Ram)
    {
        ram = Ram;
    }

    void setRom(int Rom)
    {
        rom = Rom;
    }

    void setStorage(int Storage)
    {
        storage = Storage;
    }

//getter methods:
    string getBrand()
    {
        return brand;
    }

    string getModel()
    {
        return model;
    }

    int getDisplayResolution()
    {
        return displayResolution;
    }

    int getRam()
    {
        return ram;
    }

    int getRom()
    {
        return rom;
    }

    int getStorage()
    {
        return storage;
    }

    //defining other specific actions:

    void makingphonecalls()
    {
        cout << "Making Phone Call...." << endl;
    }

    void sendingmessages()
    {
        cout << "Sending Message...." << endl;
    }

    void connectingwifi()
    {
        cout << "WIFI is being connected..." << endl;
    }

    void browsinginternet()
    {
        cout << "Browsing internet..." << endl;
    }
};

    void Display(Smartphone smartphone){
        cout << "Displaying Details: " << endl;
        cout << "Brand: " << smartphone.getBrand() << endl;
        cout << "Model: " << smartphone.getModel() << endl;
        cout << "Display Resolution: " << smartphone.getDisplayResolution() << endl;
        cout << "RAM: " << smartphone.getRam() << endl;
        cout << "ROM: " << smartphone.getRom() << endl;
        cout << "Storage: " << smartphone.getStorage() << endl;
    }

    void actions(Smartphone smartphone){
                   cout << "Choose the action you want to perform: " << endl;
            cout << "1. Make Phone Call " << endl;
            cout << "2. Send Message " << endl;
            cout << "3. Connect to WIFI " << endl;
            cout << "4. Browse the Internet " << endl;
            cout << "5. Ext the program!" << endl;

            int choice;
            do{
            cout << "Choose an option: " << endl;
            cin >> choice;

            switch(choice){

                    case 1:
                    smartphone.makingphonecalls();
                    break;

                    case 2:
                    smartphone.sendingmessages();
                    break;

                    case 3:
                    smartphone.connectingwifi();
                    break;

                    case 4:
                    smartphone.browsinginternet();
                    break;

                    case 5:
                    cout << "Exiting the program!" << endl;
                    break; 

                    default: 
                    cout << "Invalid Choice!!" << endl;
                    break;
            }
     }
     while (choice != 5);
    }

int main() {
           
            Smartphone smartphone ("", "", 0, 0, 0, 0);

             string brand, model;
             int resolution, ram, rom, storage;

            cout << "Enter brand name: " << endl;
            getline(cin, brand);
            smartphone.setBrand(brand);

            cout << "Enter model name: " << endl;
            getline(cin, model);
            smartphone.setModel(model);

            cout << "Enter display resolution: " << endl;
            cin >> resolution;
            smartphone.setDisplayresolution(resolution);
            cin.ignore();

            cout << "Enter RAM: " << endl;
            cin >> ram;
            smartphone.setRam(ram);

            cout << "Enter ROM: " << endl;
            cin >> rom;
            smartphone.setRom(rom);

            cout << "Enter Storage: " << endl;
            cin >> storage;
            smartphone.setStorage(storage);

            cout << endl;



  Display(smartphone);
  actions(smartphone);

                return 0;

}
