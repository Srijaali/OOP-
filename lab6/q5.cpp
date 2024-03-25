/*
Name: Rija Ali
ID: 23k-0057
desc: School management system
*/

#include <iostream>
#include <string>

using namespace std;

class Course {
private:
    string course_code;
    string course_name;
    int course_credhr;

public:
    Course() {
        course_code = " ";
        course_name = " ";
        course_credhr = 0;
    }

    Course(string code, string cname, int chr) {
        course_code = code;
        course_name = cname;
        course_credhr = chr;
    }

    string getCourseCode() const {
        return course_code;
    }

    string getCourseName() const {
        return course_name;
    }

    int getCourseCredHr() const {
        return course_credhr;
    }
};

class Student {
private:
    string stud_ID;
    string stud_name;
    Course* enrolled_courses;
    int num_courses;

public:
    Student(string id, string name, Course* courses, int coursenum) {
        stud_ID = id;
        stud_name = name;
        num_courses = coursenum;
        enrolled_courses = new Course[num_courses]; // Allocate memory for courses
        for (int i = 0; i < num_courses; i++) {
            enrolled_courses[i] = courses[i]; // Copy courses
        }
    }

    void enroll(const Course& course) {
        Course* temp = new Course[num_courses + 1];
        for (int i = 0; i < num_courses; i++) {
            temp[i] = enrolled_courses[i];
        }
        temp[num_courses] = course;
        delete[] enrolled_courses; // Delete old array
        enrolled_courses = temp;
        num_courses++;
    }

    void drop(const Course& course) {
        int j = -1;
        for (int i = 0; i < num_courses; i++) {
            if (enrolled_courses[i].getCourseCode() == course.getCourseCode()) {
                j = i;
                break;
            }
        }

        if (j != -1) {
            Course* temp = new Course[num_courses - 1];
            for (int i = 0; i < j; i++) {
                temp[i] = enrolled_courses[i];
            }
            for (int i = j + 1; i < num_courses; ++i) {
                temp[i - 1] = enrolled_courses[i];
            }
            delete[] enrolled_courses;
            enrolled_courses = temp;
            num_courses--;
        }
    }

    int getTotalCreditHour() {
        int totalCrdHrs = 0;
        for (int i = 0; i < num_courses; i++) {
            totalCrdHrs += enrolled_courses[i].getCourseCredHr();
        }
        return totalCrdHrs;
    }

    void displayEnrolledCourses() {
        cout << "Enrolled Courses for Student: " << stud_name << " " << "ID: " << stud_ID << ":\n";
        for (int i = 0; i < num_courses; i++) {
            cout << "Course Code: " << enrolled_courses[i].getCourseCode() << endl;
            cout << "Course Name: " << enrolled_courses[i].getCourseName() << endl;
            cout << "Course Credit Hours: " << enrolled_courses[i].getCourseCredHr() << endl;
        }
    }

    ~Student() {
        delete[] enrolled_courses; // Deallocate memory
    }
};

int main() {
    Course course1("com104", "Computer", 3);
    Course course2("Mth103", "Maths", 3);
    Course course3("Phy101", "Physics", 3);
    Course course4("E100", "English", 2);
    Course course5("Chm102", "Chemistry", 3);

    Course courses[] = { course1, course2, course3 };

    Student student("21k-101", "Ali", courses, 3);

    student.displayEnrolledCourses();

    student.enroll(course5);
    student.drop(course4);

    cout << "\nAfter changing courses:\n";
    student.displayEnrolledCourses();

    cout << "\nTotal Credit Hours: " << student.getTotalCreditHour() << endl;

    return 0;
}
