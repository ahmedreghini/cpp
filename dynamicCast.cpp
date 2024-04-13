#include<iostream>
using namespace std;

class Base {virtual void dammy() {}};


class Derived : public Base {int a;};


int main(int argc, char const *argv[])
{
    try {
    
    Base* pbd = new Derived;
    Base* pbb = new Base;
    Derived* pd;

    pd = dynamic_cast<Derived*> (pbd);
    if (pd==0) cout << "Null-pointer on first type_cast. \n";
    pd = dynamic_cast <Derived*> (pbb);
    if (pd==0) cout << "Null pointer on second type_cast. \n";
    } catch (exception& e) {cout << "Exeption: " << e.what();}

    return 0;
}
