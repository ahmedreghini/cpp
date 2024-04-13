#include<iostream>
using namespace std;

class Rectangle {
    int width, height; //these members automatic declared as privet member
    public:
    Rectangle(int x, int y) : width(x), height(y) {} // we use this constructor to pass the data to privet variables width & heith
    int area (void) {return width * height;} // this function return the area of the rectangle obj
};

int main(int argc, char const *argv[]) // int argc (argument count),char const argv (argument vector) to pass every word input as member of array of string 
{
    Rectangle obj (3,4);
    Rectangle * foo, * bar, *baz; //new pointer declaration without inintialisation
    foo = &obj; //foo pointer pointed at rectangle obj adress
    bar = new Rectangle (5, 6); // new object pointed to by bar
    baz = new Rectangle[2] {{1, 3},{5, 5}}; // new many objects pointed to by baz

    //All of these print the values of objects member pointed to by pointers 
    cout << "obj's area: " << obj.area() << endl;
    cout << "foo area: " << (*foo).area() << endl;
    cout << "bar area: " << bar->area() << endl;
    cout << "first baz area: " << baz[0].area() << endl;
    cout << "second baz area: " << baz[1].area() << endl;
    delete bar; //delete object bar
    delete[] baz; //delete all object of the array baz

    return 0;
}
