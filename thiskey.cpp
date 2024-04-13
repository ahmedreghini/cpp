#include<iostream>
using namespace std;

class Dammy {
    public:
    bool isitme (Dammy& param);
};

bool Dammy::isitme(Dammy& param) {
    if (&param == this) return true;
    else return false;
}

int main(int argc, char const *argv[])
{
    Dammy a;
    Dammy* b = &a;
    if(b->isitme(a)) 
    cout << "yes, &a is b \n";
    return 0;
}