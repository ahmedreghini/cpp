#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::recursive_mutex rmtx; // we use this recursive mutex  to lock recursive functions
int buffer = 0;

void recursive(int c, int loopFor) 
{
    if(loopFor < 0) return;
    rmtx.lock();
    
    recursive(c, --loopFor);
    cout << "Locked by Thread " << c << " buffer = " << buffer++ << endl;
    cout << "Unlocked by Thread " << c << " " << endl;
    rmtx.unlock();
}

std::recursive_mutex rmtx2;

int main () {

//Exemple recursion mutex with recursive function    
    std::thread th1(recursive, 1, 3);
    std::thread th2(recursive, 2, 3);
    th1.join();
    th2.join();

//Exemple recursive mutex with for loop
    for(int i=0; i < 3; i++) 
    {
        rmtx2.lock();
        cout << "locked " << i << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        rmtx2.unlock();
        cout << "unlocked " << i << endl;
    }
    


    return 0;
}