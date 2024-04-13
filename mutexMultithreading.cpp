#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex carMutex;

void driveCar (string driverName) {
    unique_lock<mutex> carLock (carMutex);
    cout << driverName << " is driving" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << driverName << " is done driving" << endl;
    carLock.unlock();
}

int main(int argc, char const *argv[])
{
    thread t1(driveCar, "Ahmed");
    thread t2 (driveCar, "Amani");

    t1.join();
    t2.join();
    return 0;
}
