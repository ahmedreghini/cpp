#include<iostream>
using namespace std;

template <class T> // return a template of costomize type thus we can add any type of data to the class members we named this type T
class MyPair {
    T a, b; // we declared two variable with T type
    public:
    MyPair(T first, T second) : a(first), b(second) {}; // constructor can inisialize variable members with the template T type
    T getmax(); // declaring a function membre return T type
};

template<class T> //after we declared the getmax function we will initialise it here, we right the template class T again 
T MyPair<T>::getmax(){ // type "T" class<type "T">::memberfunction
    T retroval;
    retroval = a>b? a : b;
    return retroval;
}

int main(int argc, char const *argv[])
{
    MyPair<int> myobj(100, 75); //we add the type of T is int in this object exemple
    cout << myobj.getmax() << endl;
    return 0;
}
