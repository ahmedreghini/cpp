#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    streampos begin, end;
    ifstream myfile ("exemple.bin", ios::binary);
    if(myfile.is_open()) {
    begin = myfile.tellg();
    myfile.seekg(0, ios::end);
    end = myfile.tellg();
    myfile.close();

    cout << "size is: " << (end - begin) << " bit";
    } else {
        cout << "file does not exist!";
    }


    return 0;
}