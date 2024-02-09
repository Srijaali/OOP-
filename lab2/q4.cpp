#include <iostream>
#include <string>
using namespace std;

struct Register{
    int courseId;
    string courseName;
};

struct Student : public Register {
    int studentId;
    string firstName;
    string lastName;
    int cellno;
    string email;
};

int main(){

        Student s1[5];

// Taking inputs
        for(int i=0; i<5; i++){ 
            cout << "Enter the details for students " << i+1 << ":" << endl;
    cout <<"\t" << endl;
            cout << "Enter Course ID: ";
            cin >> s1[i].courseId;
            cout << "Enter Course Name: ";
            cin >> s1[i].courseName;
            cout << "Enter Student ID: ";
            cin >> s1[i].studentId;
            cout << "Enter First Name: ";
            cin >> s1[i].firstName;
            cout << "Enter Last Name: ";
            cin >> s1[i].lastName;
            cout << "Enter Cell No.: ";
            cin >> s1[i].cellno;
            cout << "Enter Email: ";
            cin >> s1[i].email;

            cout<< "\n"<< endl;
        }
// Displaying Information
        cout << "STUDENT INFORMATION:" << endl;

        for(int i=0; i<5; i++){
            cout << "Students' Information for student " << i+1 << ":" <<endl;
            cout <<  "Course ID is: " << s1[i].courseId << endl;
            cout << "Course Name is: " << s1[i].courseName << endl;
            cout << "Student ID is: " << s1[i].studentId << endl;
            cout << "First Name is: " << s1[i].firstName << endl;
            cout << "Last Name is: " << s1[i].lastName << endl;
            cout << "Cell Number is: " << s1[i].cellno << endl;
            cout << "Email ID is: " << s1[i].email << endl;
        
        }
            return 0;
}
