#include <iostream> // std c++
#include <string> // we add it to manage the string types variables 
#include <mutex> // we add it to lock part of program when a thread doing something in that part of program (works with condition variable)
#include <vector> //we add it to store the threads,thread ids, in a vector (type like the array)
#include <condition_variable> // we add it to use condition variable and wait for something to happen to let thread access part of program
#include <thread> //we add it to use threads
#include <chrono> //we add it to use timing

using namespace std; //we added it to not type "std::cout <<", only we type "cout <<" without std

class MyPrinter {
private:
   string str; //we will store here the string that the user want to print it (exemple: abcd)
   int char_count; //this the input by the user (how many caracter, he want to print repeatedly) exemple char_count=2; th1 will print ab, th2 will print cd, th3 will print ab
   int thread_count; //how many thread the user want to use to print the caracters exemple if thread_count=3; then we have three threads to print the str inputed from user
   vector<thread> threads; //all threads had created then stored in a vector named "threads"
   vector<std::thread::id> thread_ids; //the thread ids is also stored in a vector named "thread_ids"
   int thread_id; //we will use it to store the thread id as thread_id=1; its the same thread of thread_ids<1> but it's a hummun readable id not like the real one
   int allowed_thread; //to store the thread Id that allowed to run
   mutex mutex_lock; //the lock that we will used to syncronize the the threads
   condition_variable cv; //the condition variable we will use it to notify the other threads that the current thread is completed and the mutex is unlocked
   int next_char; //we will store here the id of the char, that the next thread will begin with it (exemplle th1Print:abc th2:dab th2:cda ...) 

public:

    MyPrinter(string s, int c_count, int t_count) { //in this constructor we will initialize the private variables
        str = s; //s is added by user to assign the string that the user want to print it (exemple: abcd)
        char_count = c_count;//c_count is added by user
        thread_count = t_count; //is added by user (the number of thread we want to use it)
        thread_id = 0; //we use it to store the thread real IDs and we can call it with a simple int id (0, 1, 2...)
        next_char = 0; //we use this variable to store the after last caracter index that is printed by the last thread ran, to begin printing the next char by the new thread
        allowed_thread = 0; //we initialize allowed_thread to 0 so the first thread in threads (vector) will run first. (we use this variable to organize threads)
    }

    int getCurrentThreadId (const std::thread::id& id) { //it takes the real thread id and return the correspondent thread id from thread_id vector.
        int thread_id = 0;
        for(auto& e : thread_ids) {//for every element in thread_ids vector
            if(e == id) return thread_id; // check if this thread id is the same with the element, if yes so return the correspondent thread_id in the vector 
            thread_id++; // if not then check the next element 
        }
        return -1; //if the thread id is not exist return -1 (we use -1 to say there is an error)
    }

    void run() {

        for (int i = 0; i < thread_count; i++) { //initialize the threads (create threads as the user want "thread_count")
            thread t(&MyPrinter::print_thread, this); //create a thread t and pass method print_thread of this instance with is "MyPrinter p" wich declared in the main()
            cout << "Thread " << t.get_id() <<  " is " << i << endl; // cout the real id of the thread and it's acronom in our threa_ids vector
            thread_ids.push_back(t.get_id()); //store the thread id to thread_ids vector
            threads.push_back(move(t)); //move the thread t to the vector "threads"
        }

        for (int i = 0; i < thread_count; i++){
            threads[i].join(); // join every thread before ending the program
        }
    }

    // This function won't allow printing untill all the threads are started.
    void waitforallthreadinit() {
        while(1) {
            if(thread_count == thread_ids.size()) return;
        }
    }

    void print_thread() {
        while(1) {
            waitforallthreadinit(); //wait until all threads created
            std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //don't do anything for one second
            unique_lock<mutex> lock(mutex_lock); // make a unique_lock obj "lock" to use it with condition variable
            cv.wait(lock, [this] { return std::this_thread::get_id() == thread_ids[allowed_thread]; }); //wait for the first thread to run to syncronize the threads from th[0] to th[n] respectevely
            print_chars(); //know go and print "char_count" time from "str" chars. (print until str[char_cout])
            allowed_thread+=1; // then make the thread n+1 allowed to print_chars() for the next time
            if(allowed_thread == thread_count) allowed_thread = 0; //if all threads have been ran, return to the first thread to run it again (as a cycle)
            if(next_char >= str.length()) next_char -= str.length(); //the next thread begins with the char n+1 of "str" to print it
            lock.unlock(); // know unlock this section 
            cv.notify_all(); // and notify all the other threads if they want to use this part of code (this section)
        }
    }

    void print_chars() {
        cout << "ThreadId " << getCurrentThreadId(std::this_thread::get_id()) << " : "; //call this function to print the thread id from thread_id vector and pass this thread id as arg
        int printcount = 0; // initialize the number of caracter printed by this thread to 0.
        //we will loop from the after last char printed by the last thread (i=next_cher), 
        //for "char_count" time (printcount < char_count), and if you arrive to the last char in string stop print (i< str.length)
        for(int i=next_char; i < str.length() && printcount < char_count; i++){   
            cout << str[i]; //print str char of index "i"
            printcount++; //increase the number of char that printed by the thread
        }
        //we say to thread if you arrive to the last char in string 
        //and you style not completed the the number of chars that you must print 
        //then return to the first char and complete printing until "char_cout"
        if(printcount < char_count) { //if you style have to print chars. (printcount < char_count)
            for(int i=0; i<char_count - printcount; i++) {//return to the first char (i=0), and print until complete the chars that you have to print
                cout << str[i]; //print str char of index "i"
            }
        }
        next_char = next_char + char_count; //prepare the next char that the next thread will begin with
        cout << endl;//it makes new line (endl like "\n" but momorize the line in the cash memory)
    }
};

int main(int argc, char *argv[]) { // argc(argumentCount), argv(argumentVector)

    if (argc != 4) {//we will check here if the user add all the three variable that we need it to run the program (str, char_count and thread_count)
        cout << "Please provide 3 arguments - a string, char count & thread count" << endl;
        return 1;
    }

    string str = argv[1]; //it takes the first argument as the string we want to print
    int char_count = atoi(argv[2]); //it takes the second argument as how many caracter we want to print per thread. atoi (Asqii TO Integer)will convert the input from string to int
    int thread_count = atoi(argv[3]); //it takes the third argument as the number of thread we want to substruct the str on
    
    MyPrinter p(str, char_count, thread_count); //p is a MyPrinter object that takes the three argument that the user added it, to initialize the printer functions
    p.run();// run() is a mumber function of p obj that will run all the inside func members inside the obj to print what we want

    return 0;
}