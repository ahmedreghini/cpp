#include<iostream>
using namespace std;

class Polygon { //base class
    protected:
    int width, height;
    public:
    void set_values (int a, int b) 
    {width=a;height=b;}
};

class Rectangle : public Polygon { //derived class rectangle
    public:
    int area () {return width*height;}
};

class Triangle : public Polygon { //derived class triangle
    public:
    int area () {return width*height/2;}
};

int main(int argc, char const *argv[])
{
    Rectangle rect; // rectangle obj
    Triangle trgl; // triangle obj
    Polygon* ppoly1 = &rect; // polygon pointer , point to rect obj adress
    Polygon* ppoly2 = &trgl; // polygon pointer , point to rect obj adress
    ppoly1->set_values(4, 5); // base class pointer can only access it's members
    ppoly2->set_values(4, 5); // accessing set_values member function
    cout << rect.area() << "\n"; // we can access area() membre only from its class not from the pointer of polygon type cause it can't access it's derived class members
    cout << trgl.area() << "\n";
    return 0;
}
