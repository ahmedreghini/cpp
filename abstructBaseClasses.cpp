#include<iostream>
using namespace std;

class Polygon {
    /* 
Notice that area has no definition; this has been replaced by =0, which makes it a pure virtual function. 
Classes that contain at least one pure virtual function are known as abstract base classes.
 */
    protected:
    int width, height;
    public:
    Polygon (int a, int b) : width(a), height(b) {}
    virtual int area (void) = 0;
    void printarea() {cout << this->area() << "\n";}
};

class Rectangle : public Polygon {
    public:
    Rectangle (int a, int b) : Polygon(a, b) {}
    int area (void) {return width*height;}
};

class Triangle : public Polygon {
    public:
    Triangle (int a, int b) : Polygon(a, b) {}
    int area (void) {return width*height/2;}
};

int main(int argc, char const *argv[])
{
    Polygon* ppoly1 = new Rectangle (4,5);
    Polygon* ppoly2 = new Triangle (4, 5);
    ppoly1->printarea();
    ppoly2->printarea();
    delete ppoly1;
    delete ppoly2;
    return 0;
}
