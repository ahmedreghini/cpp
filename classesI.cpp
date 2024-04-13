#include<iostream>
using namespace std;

class Rectangle {
    int width, height;
public:
    void set_values (int,int);
    int area () {return width*height;}
};
//initialize privet members from constructor
void Rectangle::set_values (int x, int y) {
    height = x;
    width = y;
}


int main(int argc, char const *argv[])
{
    Rectangle rect, rectb; // declare two object of type Rectancle
    rect.set_values(4,5); // add params values to member function of of the rect object
    rectb.set_values(5,6);
    cout << "rect area: " << rect.area() << endl;
    cout << "rect areab: " << rectb.area() << endl;
    return 0;
}
