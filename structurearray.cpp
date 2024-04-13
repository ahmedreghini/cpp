#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct movies_t
{
    string title;
    int year;
} film[3];

void printmovie(movies_t movie);

int main(){
    string mystr;
    int n;
    for(n=0; n<3; n++){
        cout << "enter a title: ";
        getline(cin, film[n].title);
        cout << "enter a year: ";
        getline(cin, mystr);
        stringstream(mystr) >> film[n].year;
    }
    cout << "You have entred these movies: \n";
    for(n=0; n<3;n++){
        printmovie(film[n]);
    }
}

void printmovie(movies_t movie){
    
        cout << movie.title ;
        cout << " ("<< movie.year << ")\n";
}
