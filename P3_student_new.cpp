#include <iostream>
#include <string>
using namespace std;
class Student
{
string name, studentClass, division, dob;
string bloodGroup, address, contact;
int rollNo;
static int count;
public:
// Constructor
Student()
{
count++;
}
// Input student details using this pointer
void getData()
{
cout << "\nEnter Name: ";
getline(cin, this->name);
cout << "Enter Roll Number: ";
cin >> this->rollNo;
cin.ignore();
cout << "Enter Class: ";
getline(cin, this->studentClass);
cout << "Enter Division: ";
getline(cin, this->division);
cout << "Enter Date of Birth: ";
getline(cin, this->dob);
cout << "Enter Blood Group: ";
getline(cin, this->bloodGroup);
cout << "Enter Address: ";
getline(cin, this->address);
cout << "Enter Contact Number: ";
getline(cin, this->contact);
}
// Friend function
friend void display(Student &s);
// Static member function
static void showCount();
};
// Initialize static data member
int Student::count = 0;
// Static member function definition
void Student::showCount()
{
cout << "\nTotal Students: " << count << endl;
}
// Friend function definition
void display(Student &s)
{
cout << "\n----- Student Information -----";
cout << "\nName: " << s.name;
cout << "\nRoll Number: " << s.rollNo;
cout << "\nClass: " << s.studentClass;
cout << "\nDivision: " << s.division;
cout << "\nDate of Birth: " << s.dob;
cout << "\nBlood Group: " << s.bloodGroup;
cout << "\nAddress: " << s.address;
cout << "\nContact: " << s.contact << endl;
}
int main()
{
// Dynamic memory allocation
Student *s = new Student;
s->getData();
// Calling friend function
display(*s);
// Calling static member function
Student::showCount();
// Free allocated memory
delete s;
return 0;
}
