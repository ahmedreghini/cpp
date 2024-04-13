#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<deque>
using namespace std;

std::mutex mtx;
std::condition_variable cv;
deque<int> buffer;
const unsigned int maxBufferSize = 50;

void producer(int val)
{
    while (val)
    {
        std::unique_lock<std::mutex> locker(mtx);
        cv.wait(locker, [](){return buffer.size() < maxBufferSize;});
        buffer.push_back(val);
        cout << "Produced: " << val << endl;
        val--;
        locker.unlock();
        cv.notify_one();
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "I had slept after i did my job" << endl;
    
}

void consumer()
{
    while (true)
    {
        std::unique_lock<std::mutex> locker(mtx);
        cv.wait(locker, [](){return buffer.size() > 0;});
        int val = buffer.back();
        buffer.pop_back();
        cout << "Consumed: " << val << endl;
        locker.unlock();
        cv.notify_one();
    }
}

int main(int argc, char const *argv[])
{
    std::thread th1 (producer, 100);
    std::thread th2 (consumer);

    th1.join();
    th2.join();
    return 0;
}