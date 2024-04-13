#include<iostream>
using namespace std;

class Polygon {
    protected:
    int width, height;
    public:
    void set_values (int a, int b) {width=a;height=b;}
    virtual int area () {return 0;} // when we add vertual word we can access to the same member function as this from the derived classes with reference from base class
};

class Rectangle : public Polygon {
    public:
    int area () {return width*height;}
};

class Triangle : public Polygon {
    public:
    int area () {return width*height/2;}
};

int main(int argc, char const *argv[])
{
    Rectangle rect;
    Triangle trgl;
    Polygon poly;
    Polygon* ppoly1 = &rect;
    Polygon* ppoly2 = &trgl;
    Polygon* ppoly3 = &poly;
    ppoly1->set_values(4, 5); //all the set value member function, from polygon base class 
    ppoly2->set_values(4, 5);
    ppoly3->set_values(4, 5);
    cout << ppoly1->area() << "\n"; //we will use the area func member of rectangle class, it pointed to by base class pointer thus because of virtual word
    cout << ppoly2->area() << "\n"; //we will use the area func member of triangle class which derived from polygon class, it pointed to it by base class pointer thus because of virtual word
    cout << ppoly3->area() << "\n"; // we will use the area member func of polygon class 
    return 0;
}
