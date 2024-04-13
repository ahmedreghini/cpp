#include<iostream>
#include<string>
using namespace std;


class Exemple4 {
    string* ptr;
    public:
    //constructor
    Exemple4 () : ptr(new string) {} // we will call this constructor when we don't have an argument in the object declaration
    Exemple4 (const string& str) : ptr(new string(str)) {} // when we have obj with argument we use this constructor
    //destructor
    ~Exemple4 () {delete ptr;} // this destructor will delete ptr at the end of main func (in this case) and in the end of the livetime of an obj in general
    //access content
    const string& content() const {return *ptr;} // this func return the value of ptr
};

int main(int argc, char const *argv[])
{
    Exemple4 foo;
    Exemple4 bar ("Exemple");
    cout << "bar's content: " << bar.content() << "\n";
    //i think the string value declaretion will be deleted here
    return 0;
}
