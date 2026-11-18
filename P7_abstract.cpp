#include <iostream>
using namespace std;
class Employee
{
public:
virtual void calculateSalary() = 0;
};
class PermanentEmployee : public Employee
{
float monthlySalary;
public:
void calculateSalary()
{
cout << "Enter monthly salary: ";
cin >> monthlySalary;
cout << "Permanent employee salary = " << monthlySalary << endl;
}
};
class ContractEmployee : public Employee
{
float dailyWage;
int days;
public:
void calculateSalary()
{
cout << "Enter daily wage and number of days: ";
cin >> dailyWage >> days;
cout << "Contract employee salary = " << dailyWage * days << endl;
}
};
int main()
{
PermanentEmployee p;
ContractEmployee c;
p.calculateSalary();
c.calculateSalary();
return 0;
}
