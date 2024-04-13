//this is an exemple for a static member (a static member it's a member of class but it's the same for all object)
#include<iostream>
using namespace std;

class Dummy {
    public:
    static int n; // this static member in the same member for all objects
    Dummy () {n++;}; // every time the constructor constract new object the static member n increase
};

int Dummy::n=0;

int main()
{
    Dummy a; // new object
    Dummy b[5]; // new 5 object
    cout << a.n << endl; // n increase to 6 object (we pointed to n from obj)
    Dummy * c = new Dummy; // another new object 
    cout << Dummy::n << endl; // and increase again to 7 (we pointed to n from class)

    return 0;
}
