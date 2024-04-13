#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int myAmount = 0;
std::mutex mtx;
void addMoney() {
    mtx.lock();
    ++myAmount;
    mtx.unlock();
}

int main(int argc, char const *argv[])
{
    std::thread th1(addMoney);
    std::thread th2(addMoney);

    th1.join();
    th2.join();

    cout << myAmount << endl;

    return 0;
}
