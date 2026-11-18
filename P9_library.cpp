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
Library b;
b.getData();
b.display();
return 0;
}
