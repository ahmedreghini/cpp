#include<iostream>
using namespace std;


int addition (int a, int b)
{
    return (a+b);
}

int subtruction (int a, int b)
{
    return (a-b);
}

int operation (int x, int y, int (*functocall)(int, int))
{
    int g;
    g = (*functocall)(x, y);
    return (g);
}


int main(int argc, char const *argv[])
{
  /*   
    int m, n;
    int (*minus)(int, int) = subtruction;
    m = operation(7, 5, (addition));
    cout << m << "\n";
    n = operation(20, m, (minus));
    cout << n;
 */
    char a;
    char* b;
    char** c; 
    char*** d;

    a = 'z';
    b = &a;
    c = &b;
    //d = &c;

    cout << "a: " << a << "\n";
    cout << "b: " << b << "\n";
    cout << "c: " << c << "\n";
    cout << "*c: " << *c << "\n";
    cout << "**c: " << **c << "\n";
   // cout << "***d: " << *d << "\n";

    return 0;
}
