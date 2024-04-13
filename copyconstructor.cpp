#include<iostream>
#include<string>
using namespace std;

class Exemple5 {
    string* ptr;
    public:
    Exemple5 (const string& str) : ptr(new string(str)) {} // constructor
    ~Exemple5 () {delete ptr;} // destructor
    Exemple5 (const Exemple5& x) : ptr(new string(x.content())) {} // personnel copy constructor
    const string& content () const {return *ptr;} // content func that return the value of pointed to by ptr
};

int main(int argc, char const *argv[])
{
    Exemple5 foo ("Exemple");
    Exemple5 bar = foo;
    cout << "bar's content" << bar.content() << "\n";
    return 0;
}
