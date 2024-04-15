/*
Name: Rija Ali
ID: 23k-0057
desc: a payroll management system for a small company. 
*/

#include <iostream>
#include <cmath>
using namespace std;

class Employee{
    private:
    int emp_id;
    string emp_name;

    public:
    Employee(int emp_id , string emp_name) : emp_id(emp_id) , emp_name(emp_name) {}

    virtual ~Employee() {}

    virtual double calculatePay() const {
        return 0.0;
    }

    virtual void displayDetails() const {
        cout << "Employee ID: " << emp_id << endl;
        cout << "Employee Name: " << emp_name << endl;
    }
};

class FulltimeEmployee : public Employee{
    private:
    int monthly_salary;
    
    public:
    FulltimeEmployee(int emp_id, string emp_name, int monthly_salary) : Employee(emp_id,emp_name), monthly_salary(monthly_salary) {}

    double calculatePay() const override{ 
      //  cout << "Enter the Monthly Salary" << endl;
        //cin >> monthly_salary;

         return monthly_salary;
    }
    void displayDetails() const override {
        Employee :: displayDetails();
        cout << "The Monthly salary is: " << monthly_salary << endl;
    }
    
};

class PartTimeEmployee : public Employee {
    private:
    int hourly_wage;
    int hrs_worked;

    public:
    PartTimeEmployee(int emp_id, string emp_name, int hourly_wage,int hrs_worked) : Employee(emp_id,emp_name), hourly_wage(hourly_wage) , hrs_worked(hrs_worked) {}

    double calculatePay()const override{
      int pay;
        pay = hourly_wage * hrs_worked;
        return pay;
    }

    void displayDetails() const override {
        Employee :: displayDetails();
        cout << "Hourly wage: " << hourly_wage << endl;
        cout << "Hours worked: " << hrs_worked << endl;
        cout << "PartTime Employee pay: " << calculatePay() << endl;
    }
}; 

int main() {
    FulltimeEmployee ft(101 , "AAA" , 5000);
    PartTimeEmployee pt(102 , "BBB" , 15 , 40);

    Employee* e1 = new FulltimeEmployee(101 , "AAA" , 5000);
    e1 -> displayDetails();
    delete e1;

    Employee* e2 = new PartTimeEmployee(102 , "BBB" , 15 , 40);
    e2 -> displayDetails();
    delete e2;

    return 0;

}
