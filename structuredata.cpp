#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct movies_t {
    string title;
    int year;
} mine, yours;

void printmovie(movies_t movie);

int main(int argc, char const *argv[])
{
    string mystr;
    mine.title = "2001 A space Odessy";
    mine.year = 1968;

    cout << "Enter title: ";
    getline(cin, yours.title);
    cout << "Enter a year: ";
    getline(cin, mystr);
    stringstream(mystr) >> yours.year;
    cout << "my favorite movie is " << "\n";
    printmovie(mine);
    cout << "your favorite movie is " << "\n";
    printmovie(yours);
    return 0;
}


void printmovie(movies_t movie){
    cout << movie.title << "\n";
    cout << movie.year << "\n";
}