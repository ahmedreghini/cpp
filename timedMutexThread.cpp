#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

int myAmount;
std::timed_mutex tmtx;

void increament(int i) {
    if(tmtx.try_lock_for(std::chrono::seconds(2))){ // with try_lock_for the thread will wait for certain time to enter if the scoop is already looked
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "Thread: " << i << " entred" << "\n";
        tmtx.unlock();
    } else {
        cout << "Thread: " << i << " coulsn't enter" << "\n";
    }
}

int myAmount2 = 2;
std::timed_mutex tmtx2;
void decreament(int i){
    auto now = std::chrono::steady_clock::now(); // take the time of now
    if(tmtx2.try_lock_until(now + std::chrono::seconds(2))){ // with try_lock_untel the thread will wait until certain time to enter if the scoop is already looked
        --myAmount2;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        tmtx2.unlock();
        cout << "Thread: " << i << " entred" << endl;
    } else {
        cout << "Thread: " << i << " Couldn't enter" << endl;
    }
}

int main(int argc, char const *argv[])
{
    std::thread th1 (increament, 1);
    std::thread th2 (increament, 2);
    if(th1.joinable()) th1.join();
    if(th2.joinable()) th2.join();

    cout << "my amount: " << myAmount << endl;

    std::thread th3 (decreament, 3);
    std::thread th4 (decreament, 4);
    if(th3.joinable()) th3.join();
    if(th4.joinable()) th4.join();

    cout << "my amount 2: " << myAmount2 << endl;
    return 0;
}
