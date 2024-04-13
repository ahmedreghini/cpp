/* 
In principle, a publicly derived class inherits access to every member of a base class EXCEPT:

its constructors and its destructor
its assignment operator members (operator=)
its friends
its private members
 */
#include<iostream>
using namespace std;

class Mother {
    public:
    Mother () {
        cout << "Mother no argument \n";
    }
    Mother (int a) {
        cout << "mother with argument \n";
    }
};

class Daughter : public Mother {
    public:
    Daughter (int a) {
        cout << "Daughter: int parameter \n\n";
    }
};

class Son : public Mother {
    public:
    Son (int a) : Mother (a) {
        cout << "Son: int parameter \n\n";
    }
};

int main(int argc, char const *argv[])
{
    Daughter kelly(0);
    Son bud (0);
    return 0;
}
