#include<iostream>
using namespace std;

//pointer & const
void increment_all (int* start, int* stop)
{
    int* current = start;
    while (current != stop)
    {
        ++(*current);
        ++current;
    }
    
}

void print_all (const int* start, const int* stop)
{
    const int* current = start;
    while (current != stop)
    {
       cout << *current << "\n";
       ++current;
    }
    
}

//void pointer : we use it when we dont have the type of pointer (char, int...) and to dereference we have to define its type exemple :
void increase (void* data, int psize)
{
    if (psize == sizeof(char))
    {
        char* pchar; 
        pchar = (char*)data; 
        ++(*pchar);
    } else if (psize == sizeof(int))
    {
        int* pint; 
        pint = (int*)data; 
        ++(*pint);
    }
    
    
}


int main(int argc, char const *argv[])
{
    /* int numbers[] = {10, 20, 30};
    increment_all(numbers, numbers+3);
    print_all(numbers, numbers+3); */

    char a = 'x';
    int b = 1602;
    increase(&a, sizeof(a));
    increase(&b, sizeof(b));
    cout << a << ", " << b << "\n";
    return 0;
}
