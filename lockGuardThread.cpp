#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex mtx;

int buffer = 0;

void task(const char* threadNumber, int loopfor) 
{
    std::lock_guard <mutex> lock(mtx);
    for(int i =0; i < loopfor; ++i)
    {
        ++buffer;
        cout << threadNumber << buffer << endl;
    }
}

int main(int argc, char const *argv[])
{
    std::thread th1(task, "Th1: ", 5);
    std::thread th2(task, "Th2: ", 5);
    if(th1.joinable()) th1.join();
    if(th2.joinable()) th2.join();
    return 0;
}
