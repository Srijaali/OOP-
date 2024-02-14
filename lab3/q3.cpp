#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Calendar {
private:
    string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int currentYear;
    string task[12][31];

public:
    Calendar(int year) : currentYear(year) {}

    void addTask(int date, int month) {
        if (date < 1 || date > 31) {
            cout << "Invalid date!" << endl;
        } else if (month < 0 || month > 11) {
           cout << "Invalid month entered!" << endl;
        } else {
           cin.ignore();
            getline(cin, task[month][date]);
            cout << "Task added!" << endl;
        }
    }

    void removeTask(int date, int month) {
        if (date < 1 || date > 31) {
            cout << "Invalid date!" << endl;
        } else if (month < 0 || month > 11) {
            cout << "Invalid month entered!" << endl;
        } else {
            task[month][date] = "";
            cout << "Task removed successfully!" << endl;
        }
    }

    void displayTasks() {
        for (int i = 0; i < 12; i++) {
            cout << "Month " << month[i] << ":" << endl;
            for (int j = 0; j < 31; j++) {
                if (!task[i][j].empty()) {
                    cout << "Day " << j + 1 << ": " << task[i][j] << endl;
                }
            }
        }
    }
};

int main() {
    int year;
    cout << "Enter the current year: " << endl;
    cin >> year;

    Calendar myCalendar(year);

    cout << "Calendar Management System: " << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Remove Task" << endl;
    cout << "3. Display Tasks" << endl;
    cout << "4. Exit the program!" << endl;

    int choice;
    do {
        cout << "Choose an option: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                int addDate, addMonth;
                cout << "Enter the date: " << endl;
                cin >> addDate;
                cout << "Enter the month: " << endl;
                cin >> addMonth;
                myCalendar.addTask(addDate, addMonth);
                break;

            case 2:
                int removeDate, removeMonth;
                cout << "Enter the date: " << endl;
                cin >> removeDate;
                cout << "Enter the month: " << endl;
                cin >> removeMonth;
                myCalendar.removeTask(removeDate, removeMonth);
                break;

            case 3:
                myCalendar.displayTasks();
                break;

            case 4:
                cout << "Exiting the program!" << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}

