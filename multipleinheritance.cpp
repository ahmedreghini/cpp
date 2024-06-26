#include<iostream>
using namespace std;

class Polygon { //base class 
    protected:
    int width, height;
    public:
    Polygon (int a, int b) : width(a), height(b) {}
};

class Output { // another base class
    public:
    static void print (int i);
};

void Output::print (int i) { // function membre from base class Output
    cout << i << "\n";
}

class Rectangle : public Polygon, public Output { // class inherited from multiple classes (polygon & output)
    public:
    Rectangle (int a, int b) : Polygon(a, b) {}
    int area () {return width*height;}
};

class Triangle : public Polygon, public Output { // class inherited from multiple classes (polygon & output)
    public:
    Triangle (int a, int b) : Polygon(a, b) {}
    int area () {return width*height/2;}
};

int main(int argc, char const *argv[])
{
    Rectangle rect (4, 5);
    Triangle trgl (4, 5);
    rect.print(rect.area());
    Triangle::print(trgl.area());
    return 0;
}
