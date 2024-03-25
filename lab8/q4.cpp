/*
Name: Syeda Rija Ali
ID:23K-0057
desc:  using hybrid inheritance creating a program for a school that needs to keep track of its students and teachers
LAB 8 Q4
*/

#include <iostream>
#include <string>

using namespace std;

class Person{
    protected:
    string name;
    int age;

    public:
    Person(string name, int age) : name(name) , age(age) {}

    void displayPerson(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
    protected:
    int id;
    int grade_level;

    public:
    Student(string name,int age,int id,int grade_level) : Person(name,age) , id(id) , grade_level(grade_level) {}

    void displayStudent(){
        Person :: displayPerson();
        cout << "Student ID: " << id << endl;
        cout << "Grade Level: " << grade_level << endl;
    }
};

class Teacher : public Person {
    protected:
    string subject;
    int room_num;

    public:
    Teacher(string name, int age, string subject, int room_num) : Person(name,age) , subject(subject) , room_num(room_num){}

    void displayTeacher() {
        Person :: displayPerson();
        cout << "Subject: " << subject << endl;
        cout << "Room number: " << room_num << endl;
    }
};

class GraduateStudent : public Student , public Teacher{
    public:
    GraduateStudent(string name, int age, int id, int grade_level, string subject, int room_num) : Student(name,age,id,grade_level) , Teacher(name,age,subject,room_num) {}

    void displayGradStudent(){
        Student :: displayStudent();
       // Teacher :: displayTeacher();
       cout << "Teaching Subject: " << subject << endl;
       cout << "Room number: " << room_num << endl; 
    }
};

int main() {
    GraduateStudent gs("Hareem", 19, 101, 12 , "maths", 10);
    gs.displayGradStudent();

    return 0;
}

