#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

std::condition_variable cv;
std::mutex mtx;
long balance = 0;

void addMoney(int money) 
{
    std::lock_guard<mutex> lg(mtx);
    balance+= money;
    cout << "Amount added current balance: " << balance << endl;
    cv.notify_one();
}

void withdrowMoney(int money)
{
    std::unique_lock<mutex> ul(mtx);
    cv.wait(ul, [] {return (balance!=0) ? true : false;});
    if(balance>=money)
    {
        balance -= money;
        cout << "Amount deducted: " << money << endl;
    } else {
        cout << "Amount can't be deducted, current balance in less than " << money << endl;
    }
    cout << "Current balance is: " << balance << endl;
}

int main() {
    std::thread th2(addMoney, 500);
    std::thread th1(withdrowMoney, 500);
    if(th1.joinable()) th1.join();
    if(th2.joinable()) th2.join();
    return 0;
}