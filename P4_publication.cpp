#include <iostream>
#include <string>
using namespace std;
class Publication
{
protected:
string title;
float price;
public:
void getPublication()
{
cout << "Enter title: ";
cin >> title;
cout << "Enter price: ";
cin >> price;
}
void showPublication()
{
cout << "\nTitle: " << title;
cout << "\nPrice: " << price;
}
};
class Book : public Publication
{
int pages;
public:
void getBook()
{
getPublication();
cout << "Enter number of pages: ";
cin >> pages;
}
void showBook()
{
showPublication();
cout << "\nPages: " << pages << endl;
}
};
class Tape : public Publication
{
float playingTime;
public:
void getTape()
{
getPublication();
cout << "Enter playing time in minutes: ";
cin >> playingTime;
}
void showTape()
{
showPublication();
cout << "\nPlaying time: " << playingTime << " minutes\n";
}
};
int main()
{   Book b;
Tape t;
cout << "Enter book details:\n";
b.getBook();
cout << "\nEnter tape details:\n";
t.getTape();
cout << "\nBook details:";
b.showBook();
cout << "\nTape details:";
t.showTape();
return 0;
}
