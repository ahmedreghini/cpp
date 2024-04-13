#include<iostream>
#include<string>
using namespace std;

class Exemple6 {
    string* ptr;
    public:
    Exemple6 (const string& str) : ptr(new string(str)) {} // constructor
    Exemple6 () {delete ptr;} //destructor
    Exemple6 (Exemple6&& x) : ptr(x.ptr) {x.ptr = nullptr;} // move constructor
    Exemple6& operator= (Exemple6&& x) { //move assignment
        delete ptr;
        ptr = x.ptr;
        x.ptr = nullptr;
        return *this;
    }
    const string& content () const {return *ptr;} //access content
    Exemple6 operator+ (Exemple6& rhs) { // addition
        return Exemple6(content() + rhs.content());
    }
};

int main(int argc, char const *argv[])
{
    Exemple6 foo ("Exem");
    Exemple6 bar = Exemple6("ple"); //move constructor 
    foo = foo + bar; // move assignment
    cout << "foo's content: " << foo.content() << endl;
    return 0;
}
