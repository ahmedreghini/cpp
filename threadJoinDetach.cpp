#include<iostream>
#include<chrono>
#include<thread>
using namespace std;

void run (int count) {
    while (count --> 0)
    {
        cout << count << " CppNuts" << endl;
    }
    std::this_thread::sleep_for(chrono::seconds(2));
}

int main(int argc, char const *argv[])
{
    std::thread th1(run, 5);
    cout << "main()" << endl;
    //th1.join(); // the main() thread will wait until th1 thread to complete
    // when we use to th1.join() two times 
    //an error will appear
    //so we have to know if this thread is joinable
    //if(th1.joinable()) th1.join();

    th1.detach(); 
    if(th1.joinable()) th1.detach();
    //th1 will detach from the parent thread wich in our case the main() thread 
    //so the main() thread will completed (return) without waiting for th1 thread because it's not it's child anymore 
    
    cout << "main() after" << endl;
    std::this_thread::sleep_for(chrono::seconds(5));
    return 0;
}
