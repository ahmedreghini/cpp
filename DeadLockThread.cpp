/*Problem: this one of deadlock exemple when a 
thread lock mutex and the other want it 
and the other thread lock an other mutex
that the first thread want it
thread1() {mtx1.lock(); mtx2.lock(); bla bla bla mtx1.unlock();mtx2.unlock();}
thread2() {mtx2.lock(); mtx1.lock(); bla bla bla mtx2.unlock();mtx1.unlock();}  */

/* Solution: we have to lock and unlock the mutexes 
in the same order for the two threads.
thread1() {mtx1.lock(); mtx2.lock(); bla bla bla mtx1.unlock();mtx2.unlock();}
thread2() {mtx1.lock(); mtx2.lock(); bla bla bla mtx1.unlock();mtx2.unlock();}  */
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex mtx1;
std::mutex mtx2;

void thread1()
{
    mtx1.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mtx2.lock(); //Can't access locked by thread 2
    cout << "Critical Section of Thread: Thread One\n";
    mtx1.unlock();
    mtx2.unlock();
}

void thread2()
{
    mtx2.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mtx1.lock(); //Can't access it locked by thread 1
    cout << "Critical Section of Thread: Thread Two\n";
    mtx2.unlock();
    mtx1.unlock();
}

int main(int argc, char const *argv[])
{
    thread th1(thread1);
    thread th2(thread2);

    th1.join();
    th2.join();
    return 0;
}
