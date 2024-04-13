#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>
using namespace std;

int x=0, y=0;
std::mutex mtx1, mtx2;

void takeNap(int seconds) {
    std::this_thread::sleep_for( std::chrono::seconds(seconds));
    }

void increamentXY(int& XorY, std::mutex& m, const char* desc) {
    for(int i=0; i<5; ++i) {
        m.lock();
        ++XorY;
        cout << desc << XorY << "\n";
        m.unlock();
        takeNap(1);
    }
}

void consumeXY() {
    int useCount = 5;
    int XplusY = 0;
    while (1)
    {
        int lockResult = std::try_lock(mtx1, mtx2); // here we try to lock multi Mutual execlusion
        if(lockResult == -1) { //if lockRusult == -1 that means all mutexs locked
            if(x!=0 && y!=0) { // if xand y not 0 (th1 and th2 has completed their job the we locked mtx1 and mtx2)
                --useCount;
                XplusY += x+y;
                x = 0;
                y = 0;
                cout << "XplusY " << XplusY << "\n";
            }
            mtx1.unlock();
            mtx2.unlock();
            if(useCount == 0) break;
        }
    }
    
}

int main(int argc, char const *argv[])
{
    std::thread th1 (increamentXY, std::ref(x), std::ref(mtx1), "x ");
    std::thread th2 (increamentXY, std::ref(y), std::ref(mtx2), "y ");
    std::thread th3 (consumeXY);

    if(th1.joinable()) th1.join();
    if(th2.joinable()) th2.join();
    if(th3.joinable()) th3.join();
    return 0;
}
