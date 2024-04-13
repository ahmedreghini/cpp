#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int counter = 0;
std::mutex mtx;
void increaseCounter() {
    for (size_t i = 0; i < 100000; i++)
    {
        if (mtx.try_lock()) //if it's already locked the second thread will skeep this part of code and continue running
        {
            ++counter;
            mtx.unlock();
        }
        
    }
}

int main(int argc, char const *argv[])
{
    std::thread th1(increaseCounter);
    std::thread th2(increaseCounter);

    th1.join();
    th2.join();

    cout << " counter could increases upto: " << counter << endl;
    return 0;
}
