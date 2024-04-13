#include<iostream>
using namespace std;

class Rectangle {
    int width, height;
    public:
    Rectangle() {}
    Rectangle (int x, int y) : width(x), height(y) {}
    int area() {return width*height;}
    friend Rectangle duplicate (const Rectangle&);
};

Rectangle duplicate (const Rectangle& param) {
    Rectangle res;
    res.width = param.width*2;
    res.height = param.height*2;
    return res;
}

int main(int argc, char const *argv[])
{
    Rectangle foo;
    Rectangle bar (3, 5);
    foo = duplicate(bar);
    cout << "foo's area after duplicate bar values: " << foo.area() << endl;
    return 0;
}
