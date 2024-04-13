//there are 5 ways to create threads in c++11 
//1.Function pointers
//2.Lamda Functions
//3.Functors
//4.Member functions
//5.Static Member functions

//For this exemple we will use "1.function pointer" way
//Find the qddition of all Odd number from 1 to 1900000000
//and all Even number from 1 to 1900000000

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void findEven (ull start, ull end) {
    auto stt = high_resolution_clock::now();
    for (ull i = start; i <= end; ++i) {
        if ((i & 1) == 0){
            evenSum += i;
        }
    }
    auto spt = high_resolution_clock::now();
    cout << evenSum << endl;
    auto duration = duration_cast<seconds> (spt - stt);
    cout << "findEven duration: " << duration.count() << endl;
}

void findOdd (ull start, ull end) {
    auto stt = high_resolution_clock::now();
    for (ull i = start;i <= end; ++i) {
        if ((i & 1) == 1) {
            oddSum += i;
        }
    }
    auto spt = high_resolution_clock::now();
    cout << oddSum << endl;
    auto duration = duration_cast<seconds> (spt - stt);
    cout << "findOdd duration: " << duration.count() << endl;
}

int main(int argc, char const *argv[])
{
    ull start = 0, end = 1900000000;

    //*************Multithreaed tasks**************
    cout << "Multithreading tasks: " << "\n\n";
    auto stt = high_resolution_clock::now();
    std::thread th1(findEven, start, end);
    std::thread th2(findOdd, start, end);
    th1.join();
    th2.join();
    auto spt = high_resolution_clock::now();
    auto duration = duration_cast<seconds> (spt - stt);
    cout << "Total duration: " << duration.count() << endl;

    //***************without multithreading (one thread)*************
    cout << "Without multithreading: " << "\n\n";

    stt = high_resolution_clock::now();
    findEven(start, end);
    findOdd(start, end);
    spt = high_resolution_clock::now();
    duration = duration_cast<seconds> (spt - stt);
    cout << "Total duration: " << duration.count() << endl;
    return 0;
}



