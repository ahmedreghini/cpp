#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex mtx;
int buffer = 0;

void task(const char* threadNumber, int loopFor)
{
    //std::unique_lock<mutex> lock(mtx); //this lock without spetialise the type, act like gard lock 
    std::unique_lock<mutex> lock(mtx, defer_lock); //we initialise the unique lock but we will used next (scoop steel unlocked)
    lock.lock(); // here we lock the scoop with the lock that we initialized in the line above
    for(int i=0; i<loopFor; ++i)
    {
        buffer++;
        cout << threadNumber << buffer << endl;
    }
}

int main(int argc, char const *argv[])
{
    thread th1(task, "Th1: ", 5);
    thread th2(task, "Th2: ", 5);
    if(th1.joinable()) th1.join();
    if(th2.joinable()) th2.join();
    return 0;
}
