/* 
the implcit members 

The six special members functions described above are members implicitly declared on classes under certain circumstances:

Member function	implicitly defined:	default definition:
Default constructor:	if no other constructors	does nothing
Destructor:	if no destructor	does nothing
Copy constructor:	if no move constructor and no move assignment	copies all members
Copy assignment:	if no move constructor and no move assignment	copies all members
Move constructor:	if no destructor, no copy constructor and no copy nor move assignment	moves all members
Move assignment:	if no destructor, no copy constructor and no copy nor move assignment	moves all members

 */
#include<iostream>
#include<string>
using namespace std;

class Rectangle {
    int width, height; //private variables
    public:
    Rectangle(int x, int y) : width(x), height(y) {} // constructor with arguments
    Rectangle () = default; // default costructor when we don't have arguments
    Rectangle (const Rectangle& other) = delete; // delete copy obj membres values
    int area() {return width*height;} // return the area of rectangle

};

int main(int argc, char const *argv[])
{
    Rectangle foo; // it uses the default constructor
    Rectangle bar(5, 3); // it uses the costomized constructor 

    cout << "bar's area: " << bar.area() << endl; // print object area
    return 0;
}
