#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct movies_t{
    string title;
    int year;
};

struct friends_t{
    string name;
    string email;
    movies_t favoritemovie;
} charlie, maria;

void printmovie(movies_t movie);

int main(int argc, char const *argv[])
{
    /* string mystr;
    movies_t amovie;
    movies_t *pmovie;
    pmovie = &amovie;

    cout << "enter a title: ";
    getline(cin, pmovie->title);
    cout << "enter a year: ";
    getline(cin, mystr);
    (stringstream) mystr >> pmovie->year;

    cout << "You have entred: \n";
    cout << pmovie->title << "\n";
    cout << (*pmovie).year << "\n"; */

    string mystr;
    friends_t *pcharlie = &charlie;
    movies_t *pcharliemovie = &charlie.favoritemovie;

    cout << "enter your name: ";
    getline(cin, charlie.name);
    cout << "enter your email: ";
    getline(cin, charlie.email);
    cout << "enter your favorite movie name: ";
    getline(cin, charlie.favoritemovie.title);
    cout << "enter " << charlie.favoritemovie.title << " year";
    getline(cin, mystr);
    (stringstream) mystr >> pcharliemovie->year;


    cout << "your name is " << charlie.name << "\n";
    cout << "your email is " << charlie.email << "\n";
    cout << "your favorite movie is: ";
    printmovie(charlie.favoritemovie);
    return 0;
}

void printmovie(movies_t movie){
    cout << movie.title << " (" << movie.year << ") \n";
}
