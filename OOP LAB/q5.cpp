#include <iostream>
#include <string>

using namespace std;

struct Event {
    string name;
    string date;
    string venue;
    string organizer;
};

int i;

void addEvents(Event* events, int num) {
    for (i = 0; i < num; i++) {
        cout << "\nEvent " << i + 1 << ":\n";
        
        cout << "Name: ";
        cin>>events[i].name;
        cout << "Date: ";
        cin>>events[i].date;
        cout << "Venue: ";
        cin>>events[i].venue;
        cout << "Organizer: ";
        cin>>events[i].organizer;
    }
}

void printEv(Event* events, int num) {
     cout << "\nAll Events:\n";
    for (i = 0; i < num; i++) {
    	
        cout << "\nEvent " << i + 1 << ":\n";
        cout << "Name: " << events[i].name << endl;
        cout << "Date: " << events[i].date << endl;
        cout << "Venue: " << events[i].venue << endl;
        cout << "Organizer: " << events[i].organizer << endl;
    }
}

void findEvent(Event* events, int num, string& findDate) {
    bool found = false;
    
    for (i = 0; i < num; i++) {
        if (events[i].date == findDate) {
        	
            found = true;
            
            cout << "\nEvent " << i + 1 << ":\n";
            cout << "Name: " << events[i].name << endl;
            cout << "Date: " << events[i].date << endl;
            cout << "Venue: " << events[i].venue << endl;
            cout << "Organizer: " << events[i].organizer << endl;
        }
    }
    if (found==false) {
        cout << "NO EVENTS FOUND"<< endl;
    }
}


int main() {
    int num;

    cout << "Enter the total number of events: ";
    cin >> num;

    Event* events = new Event[num];

    addEvents(events, num);
    printEv(events, num);

    string findDate;
    cout << "\nEnter the date to find events on: ";
    cin >> findDate;
    
    findEvent(events, num, findDate);

    delete[] events;

    return 0;
}
