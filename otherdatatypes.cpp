#include<iostream>
#include<string>
#include<sstream>

typedef char ch;
typedef unsigned int word;
using pchar = char*;

ch var = 'z';
word var2 = 200;
pchar pc = &var;

int main(int argc, char const *argv[])
{
    union mix_t
    {
        int l;
        struct 
        {
            short hi;
            short lo;
        } s;
        char c[4];
        
    } mix;
// enum is declaretion of new data type in array and we it's translated later as black is 1, blue is 2...
    enum colors_t {black, blue, orange, yellow, red, green};
    colors_t mycolor;
    mycolor = blue; //it's the same as mycolor = colort_t[2]
    if(mycolor == green) mycolor = red; //like we are saying if(mycolor == colort_t[6])

    //we made new data type months_t and then an object of that type y2k
    enum class months_t {janvier, fevrier, mars, avril, may, join, juillet, aout, septembre, october, novembre, decembre} y2k;
    //we made a new data type of char type
    enum class personneltype: char {a, anotherone, andanotherone, blue};
    return 0;
}

