#include <iostream>
#include <string>
using namespace std;
class Library
{
int bookID;
string bookName, author;
float price;
public:
Library()
{
bookID = 0;
bookName = "Unknown";
author = "Unknown";
price = 0;
}
Library(int id, string name, string auth, float pr)
{
bookID = id;
bookName = name;
author = auth;
price = pr;
}
void getData()
{
cout << "Enter book ID: ";
cin >> bookID;
cout << "Enter book name: ";
cin >> bookName;
cout << "Enter author name: ";
cin >> author;
cout << "Enter price: ";
cin >> price;
}
void display()
{
cout << "\nBook ID: " << bookID;
cout << "\nBook name: " << bookName;
cout << "\nAuthor: " << author;
cout << "\nPrice: " << price << endl;
}
};
int main()
{
Library b1;                                   // default constructor
Library b2(102, "Wings_of_Fire", "Kalam", 450); // parameterized constructor
cout << "Enter details of first book:\n";
b1.getData();
cout << "\nFirst book:";
b1.display();
cout << "\nSecond book (parameterized constructor):";
b2.display();
return 0;
}
