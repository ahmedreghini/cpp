//overloading operator exemple
#include<iostream>
using namespace std;

class CVector {
    public:
    int x, y;
    CVector () {};
    CVector (int a, int b) : x(a), y(b) {}
    //member function overloaded exemple addition, we add only the second appand
    CVector operator+ (const CVector&);
};
// here we overloaded the + operator to let the compilor know how to add these two objects
CVector CVector::operator+ (const CVector& params) {
    CVector temp;
    temp.x = x + params.x;
    temp.y = y + params.y;
    return temp;
}
//here we let the compilor know how to print an object then another object 
ostream& operator<< (ostream& COUT, CVector params) {
        COUT << "{" << params.x << ", ";
        COUT << params.y << "}" << "\n";
        return COUT;
    }
//non member function overloaded exemple substruct two objects
CVector operator-(const CVector paramone, const CVector paramtwo) {
    CVector temp;
    temp.x = paramone.x - paramtwo.x;
    temp.y = paramone.y - paramtwo.y;
    return temp;
}



int main(int argc, char const *argv[])
{
    CVector foo {3, 5};
    CVector bar(1, 2);
    CVector result;
    CVector baz(6, 9);
    CVector daz(4, 9);
    CVector resultb;
    CVector resultc;
    result = foo + bar;
    resultb = baz + daz + foo + bar;
    cout << result << resultb;
    resultc = result.operator+(resultb);
    operator<<(cout, result.operator+(resultc));
    CVector resultd = foo - bar;
    cout << resultd;
    return 0;
}
