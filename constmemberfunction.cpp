//constant objects and constant member function
#include<iostream>
using namespace std;

class MyClass {
    int x;
    public:
    MyClass(int val) : x(val) {}; //if we make const obj the constructor steal can initialise members
    int& get() {return x;} // if we make cons obj we can't call non const function
    const int& get() const {return x;} 
    // we can overload a function as we know, this function declared with the first const for const return value and the second one to declar it as const func 
};

int main(int argc, char const *argv[])
{
    MyClass foo(10); //new normal obj so it will use the normal func get()
    const MyClass bar(20); // new const obj si it will use the const func get()
    foo.get() = 15; // it's normale to modify this obj cause it is a normal obj
    //bar.get() = 15; // we can't modify this obj cause it's const obj
    cout << foo.get() << endl; // it will print x == 15 not 10
    cout << bar.get() << endl; // it will print x == 20 never changes cause const obj
    return 0;
}
