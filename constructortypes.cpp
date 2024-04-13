#include<iostream>
using namespace std;

class Circle {
    double radius;
    public:
    Circle (double r) {radius = r;}
    double circum () {return 2*radius*3.14159265;}
};

int main(int argc, char const *argv[])
{
    Circle foo (10.0); // functional form
    Circle bar = 20.0; // assignment unit (single argument)
    Circle baz {30.0}; // uniform unit
    Circle qux = {40.0}; //uniform unit with optional assignment(=) 

    cout << "functional form----------------> Circle foo (10.0); " << foo.circum() << endl;
    cout << "assignment unit----------------> Circle bar = 20.0; " << bar.circum() << endl;
    cout << "uniform unit-------------------> Circle baz {30.0}; " << baz.circum() << endl;
    cout << "uniform unit with optional (=)-> Circle qux = {40.0}; " << endl;


    return 0;
}
