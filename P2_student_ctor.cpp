#include <iostream>
#include <string>
using namespace std;
class Student
{
string name, studentClass, division, dob, bloodGroup, address, contact;
int rollNo;
public:
Student()
{
name = "Unknown";
rollNo = 0;
studentClass = "-";
division = "-";
dob = "-";
bloodGroup = "-";
address = "-";
contact = "-";
}
Student(string n, int r, string c, string d, string date,
string bg, string a, string phone)
{
name = n;
rollNo = r;
studentClass = c;
division = d;
dob = date;
bloodGroup = bg;
address = a;
contact = phone;
}
Student(const Student& s)
{
name = s.name;
rollNo = s.rollNo;
studentClass = s.studentClass;
division = s.division;
dob = s.dob;
bloodGroup = s.bloodGroup;
address = s.address;
contact = s.contact;
}
void display()
{
cout << "\nName: " << name;
cout << "\nRoll number: " << rollNo;
cout << "\nClass: " << studentClass;
cout << "\nDivision: " << division;
cout << "\nDate of birth: " << dob;
cout << "\nBlood group: " << bloodGroup;
cout << "\nAddress: " << address;
cout << "\nContact: " << contact << endl;
}
~Student()
{
cout << "\nStudent object destroyed.\n";
}
};
int main()
{
Student s1;
Student s2("Amit", 12, "SY", "A", "10-05-2005",
"O+", "Nashik", "9876543210");
Student s3(s2);
cout << "\nDefault constructor object:";
s1.display();
cout << "\nParameterized constructor object:";
s2.display();
cout << "\nCopy constructor object:";
s3.display();
return 0;
}
