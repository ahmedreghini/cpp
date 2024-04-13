#include<iostream>
#include<thread>
//#include<algorithm>
//#include<chrono>
#include<future>
using namespace std;
//using namespace std::chrono;
typedef unsigned long long ull;

void findOdd(std::promise<ull>&& oddSumPromise, ull start, ull end)
{
    ull oddSum = 0;
    for(ull i = start; i <= end; ++i)
    {
        if(i & 1) {oddSum += i;}
    }
    oddSumPromise.set_value(oddSum);
}

int main() {
    ull start = 0, end = 1900000000;

    std::promise<ull> oddSum; //promise is a setter (set values or expressions)
    std::future<ull> oddFuture = oddSum.get_future(); //future is a 1.getter (get values from promise), 2.(ask promise if the value is available), 3.(wait for the prosise)
    cout << "Thread created!" << endl;
    std::thread th1(findOdd, std::move(oddSum), start, end);
    cout << "Waiting for Result!!" << endl;
    cout << "oddSum: " << oddFuture.get() << endl;
    cout << "Completed!!" << endl;
    th1.join();
    return 0;
}


