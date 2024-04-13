#include<iostream>
#include<string>
using namespace std;
//when we don't declared a constructor there is a default constructor implecitly declared 
//when we declare a constructor the default constructor is removed
//and we want to make an object without argument we have to declare a constructor like the default one explicitly
class Exemple3 {
    string data;
    public:
    Exemple3 (const string& str) : data(str) {} // constructor with argument
    Exemple3 () {} // constructor without argument
    const string& content () {return data;}
};

int main(int argc, char const *argv[])
{
    Exemple3 foo; //constructed by the normal constructor
    Exemple3 bar ("Exemple"); //constructed with the constructor with argument
    cout << "this is the value of bar: " << bar.content() << endl;
    return 0;
}
