/* 
Thread or process syncronize to access a critical section
Critical section is one or collection of program statements wich should be executed by one thread or one process
- in this example we have the bankBalance variable as critical section so we add mutex lock to access it by thread at a time.
 */
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
using ull = unsigned long long ;

std::mutex mtx;
ull bankBalance = 0;

void addMoney(ull value) 
{
    mtx.lock();
    bankBalance += value;
    cout << "Bank balance: " << bankBalance << endl;
    mtx.unlock();
}

int main() 
{
    thread th1(addMoney, 100);
    thread th2(addMoney, 200);
    th1.join();
    th2.join();
}

