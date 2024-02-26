/*
Name: Syeda Rija Ali
ID: 23K-0057
Desc: Vet Management system
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const string health[2] = {"healthy", "sick"};

class Pet {
public:
    string healthstatus;
    string name;
    int hungerlevel;
    int happinesslevel;
    string skills[10];

    void displayPetDetails() {
        cout << "Health Status: " << healthstatus << endl;
        cout << "Hunger: " << hungerlevel << endl;
        cout << "Happiness: " << happinesslevel << endl;
        cout << "Skills:" << endl;
        for (int i = 0; i < 10 && skills[i] != ""; i++) {
            cout << skills[i] << endl;
        }
    }

    void updateHunger(int hunger) {
        hungerlevel = hunger;
        if (hunger >= 50)
            happinesslevel += rand() % 10 + 1;
        else
            happinesslevel -= rand() % 10 + 1;
    }

    void updateHealth(string health) {
        healthstatus = health;
    }

    void updateHappiness(int happiness) {
        happinesslevel = happiness;
    }
};

class Adopter {
public:
    string adpname, adpnum;
    Pet petrecords[50];
    int petsadpted = 0;

    Adopter(string name, string num) : adpname(name), adpnum(num) {}

    void adoptPet(Pet &pet) {
        petrecords[petsadpted++] = pet;
    }

    void returnPet(string name) {
        for (int i = 0; i < petsadpted; i++) {
            if (petrecords[i].name == name) {
                for (int j = i; j < petsadpted - 1; j++)
                    petrecords[j] = petrecords[j + 1];
                --petsadpted;
                break;
            }
        }
    }

    void displayAdoptedPets() {
        for (int i = 0; i < petsadpted; i++) {
            cout << "Name: " << petrecords[i].name << endl;
            petrecords[i].displayPetDetails();
            cout << "\n";
        }
    }
};

void menu() {
    cout << "PET ADOPTION SYSTEM" << endl;
    cout << "\t1. Add pet" << endl;
    cout << "\t2. Show all pets" << endl;
    cout << "\t3. Adopt pet" << endl;
    cout << "\t4. Show adopted pets" << endl;
    cout << "\t5. Interact with pet" << endl;
    cout << "\t6. Return pet" << endl;
    cout << "\t7. Exit" << endl;
}

string inputPetName() {
    string name;
    cout << "Enter pet name: ";
    getline(cin, name);
    return name;
}

void inputSkills(string skills[]) {
    cout << "Select skills (enter 0 to exit)\n";
    int count = 0;
    while (true) {
        string skill;
        cout << "Enter skill: ";
        getline(cin, skill);

        if (skill == "0" || count >= 10)
            break;
        skills[count++] = skill;
    }
}

Pet addPet() {
    Pet pet;
    pet.name = inputPetName();
    inputSkills(pet.skills);
    pet.healthstatus = "Healthy";
    pet.happinesslevel = 60;
    pet.hungerlevel = 60;
    return pet;
}

void showAllPets(Pet list[], int numPets) {
    for (int i = 0; i < numPets; i++) {
        cout << "Name: " << list[i].name << endl;
        list[i].displayPetDetails();
        cout << "\n";
    }
}

void adoptPet(Adopter &adopter, Pet list[], int &numPets) {
    string name = inputPetName();
    for (int i = 0; i < numPets; i++) {
        if (list[i].name == name) {
            adopter.adoptPet(list[i]);
            for (int j = i; j < numPets - 1; j++)
                list[j] = list[j + 1];
            --numPets;
            cout << "Pet adopted" << endl;
            return;
        }
    }
    cout << "Pet not found" << endl;
}

void returnPet(Adopter &adopter, Pet list[], int &numPets) {
    string name = inputPetName();
    for (int i = 0; i < adopter.petsadpted; i++) {
        if (adopter.petrecords[i].name == name) {
            list[numPets++] = adopter.petrecords[i];
            adopter.returnPet(name);
            cout << "Pet returned" << endl;
            return;
        }
    }
    cout << "Pet not found" << endl;
}

void interact(Pet &pet) {
    pet.displayPetDetails();
    int choice;
    cout << "Select pet interaction\n";

    cout << "\t1. Make pet happy/unhappy" << endl;
    cout << "\t2. Feed pet/Make pet hungry" << endl;

    cin >> choice;

    if (choice == 1) {
        int happiness;
        cout << "Enter happiness value: ";
        cin >> happiness;
        pet.updateHappiness(happiness);
    } else if (choice == 2) {
        int hunger;
        cout << "Enter hunger value: ";
        cin >> hunger;
        pet.updateHunger(hunger);
    } else {
        cout << "Incorrect option choosed" << endl;
        return;
    }

    if (pet.hungerlevel >= 60 && pet.happinesslevel >= 60)
        pet.updateHealth(health[0]);
    else
        pet.updateHealth(health[1]);
}

void interactWithPet(Adopter &adopter) {
    cout << "Select pet name to interact with\n";
    string name = inputPetName();

    for (int i = 0; i < adopter.petsadpted; i++) {
        if (name == adopter.petrecords[i].name) {
            interact(adopter.petrecords[i]);
            return;
        }
    }
    cout << "Pet not found" << endl;
}

int main() {
    srand(time(0));
    Pet petsList[50];
    int numPets = 0;

    string name;
    cout << "Enter adopter's name: ";
    getline(cin, name);

    string num;
    cout << "Enter phone number: ";
    getline(cin, num);

    Adopter adopter(name, num);

    int choice;
    do {
        menu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                if (numPets < 50) {
                    petsList[numPets++] = addPet();
                    cout << "Pet added successfully!" << endl;
                } else {
                    cout << "No more pets can be entered." << endl;
                }
                break;
            case 2:
                showAllPets(petsList, numPets);
                break;

            case 3:
                adoptPet(adopter, petsList, numPets);
                break;
            case 4:
                adopter.displayAdoptedPets();
                break;
            case 5:
                interactWithPet(adopter);
                break;
            case 6:
                returnPet(adopter, petsList, numPets);
                break;
            case 7: 
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 7." << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}



