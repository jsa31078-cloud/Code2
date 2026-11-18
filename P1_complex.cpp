#include <iostream>
using namespace std;
class Complex
{
int real, imag;
public:
Complex() { real = 0; imag = 0; }
Complex(int r, int i)
{
real = r;
imag = i;
}
Complex operator+(Complex c)
{
return Complex(real + c.real, imag + c.imag);
}
Complex operator*(Complex c)
{
return Complex(real * c.real - imag * c.imag,
real * c.imag + imag * c.real);
}
friend istream& operator>>(istream& in, Complex& c)
{
cout << "Enter real part: ";
in >> c.real;
cout << "Enter imaginary part: ";
in >> c.imag;
return in;
}
friend ostream& operator<<(ostream& out, Complex c)
{
out << c.real << " + " << c.imag << "i";
return out;
}
};
int main()
{
Complex c1, c2, sum, product;
cout << "Enter first complex number:\n";
cin >> c1;
cout << "Enter second complex number:\n";
cin >> c2;
sum = c1 + c2;
product = c1 * c2;
cout << "Addition = " << sum << endl;
cout << "Multiplication = " << product << endl;
return 0;
}
