#include <iostream>
using namespace std;
class Shape
{
public:
virtual void calculateArea() = 0;
};
class Circle : public Shape
{
float radius;
public:
void calculateArea()
{
cout << "Enter radius: ";
cin >> radius;
cout << "Area of circle = " << 3.14 * radius * radius << endl;
}
};
class Rectangle : public Shape
{
float length, breadth;
public:
void calculateArea()
{
cout << "Enter length and breadth: ";
cin >> length >> breadth;
cout << "Area of rectangle = " << length * breadth << endl;
}
};
class Triangle : public Shape
{
float base, height;
public:
void calculateArea()
{
cout << "Enter base and height: ";
cin >> base >> height;
cout << "Area of triangle = " << 0.5 * base * height << endl;
}
};
int main()
{
Circle c;
Rectangle r;
Triangle t;
Shape *s;
s = &c;
s->calculateArea();
s = &r;
s->calculateArea();
s = &t;
s->calculateArea();
return 0;
}
