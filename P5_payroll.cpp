#include <iostream>
#include <string>
using namespace std;
class Employee
{
protected:
int id;
string name;
public:
void getEmployee()
{
cout << "Enter employee ID: ";
cin >> id;
cout << "Enter employee name: ";
cin >> name;
}
};
class Salary : public Employee
{
protected:
float basic, allowance;
public:
void getSalary()
{
getEmployee();
cout << "Enter basic salary: ";
cin >> basic;
cout << "Enter allowances: ";
cin >> allowance;
}
};
class Payroll : public Salary
{
float gross;
public:
void calculate()
{
getSalary();
gross = basic + allowance;
}
void display()
{
cout << "\nEmployee ID: " << id;
cout << "\nEmployee name: " << name;
cout << "\nBasic salary: " << basic;
cout << "\nAllowances: " << allowance;
cout << "\nGross salary: " << gross << endl;
}
};
int main()
{
Payroll p;
p.calculate();
p.display();
return 0;
}
