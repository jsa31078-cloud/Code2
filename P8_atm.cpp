#include <iostream>
using namespace std;
int main()
{
double balance = 5000, amount;
int choice;
do
{
cout << "\n1. Check balance";
cout << "\n2. Deposit";
cout << "\n3. Withdraw";
cout << "\n4. Exit";
cout << "\nEnter choice: ";
cin >> choice;
try
{
if (cin.fail())
throw "Invalid input";
if (choice == 1)
{
cout << "Balance = " << balance << endl;
}
else if (choice == 2)
{
cout << "Enter deposit amount: ";
cin >> amount;
if (cin.fail() || amount <= 0)
throw "Invalid amount";
balance += amount;
cout << "Amount deposited.\n";
}
else if (choice == 3)
{
cout << "Enter withdrawal amount: ";
cin >> amount;
if (cin.fail() || amount <= 0)
throw "Invalid amount";
if (amount > balance)
throw "Insufficient funds";
balance -= amount;
cout << "Please collect your cash.\n";
}
else if (choice != 4)
{
throw "Invalid menu choice";
}
}
catch (const char* message)
{
cout << "Error: " << message << endl;
cin.clear();
cin.ignore(1000, '\n');
}
// C++ has no 'finally' block; this section runs after try/catch.
}
while (choice != 4);
cout << "Thank you for using ATM.\n";
return 0;
}
