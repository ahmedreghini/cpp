#include<iostream>
#include<thread>
#include<future>
using namespace std;

typedef unsigned long long ull;

ull findOdd(ull start, ull end)
{
    ull oddSum = 0;
    for(ull i = start; i <= end; ++i)
    {
        if(i & 1){ oddSum += i;}
    }
    return oddSum; // this time we used return instead of prom.set_value() in the promise future exemple
}

int main(int argc, char const *argv[])
{
    ull start = 0, end = 1900000000;
    cout << "Thread created if policy is std::lunch::async!!" << endl;
    std::future<ull> oddSum = std::async(std::launch::deferred, findOdd, start, end); // std::async(type(async/deffered), method, methodeVar, methodVar)
    cout << "waiting for result!" << endl;
    // we call the result of variable "oddSum.get()"" so if the type of async:deffered then the future func will start here 
    // if the std::launch::async the future function is already started in it's declaretion statement std:: future<ull> oddSum = returned oddSum value from findOdd
    cout << "oddSum: " << oddSum.get() << endl;
    cout << "Completed!!";
    return 0;
}
