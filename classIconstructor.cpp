#include<iostream>
using namespace std;

class Rectangle {
    int width, height;
    public:
    Rectangle();
    Rectangle(int,int);
    int area(){return width * height;}
};
// this constructor called one type to build new object of the class, so we can add arguments or initialase some values with it in the first time we make an object
Rectangle::Rectangle() {
    width = 5;
    height = 6;
}

Rectangle::Rectangle (int a, int b) {
    width = a;
    height = b;
}

int main(int argc, char const *argv[])
{
    Rectangle rect (3, 4);
    Rectangle rectb;
    cout << "rect area: " << rect.area() << endl;
    cout << "rectb area " << rectb.area() << endl;
    return 0;
}
