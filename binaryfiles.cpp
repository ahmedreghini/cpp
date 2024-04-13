#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    streampos size;
    char* memoryblock;

    ifstream myfile ("exemple.bin", ios::in | ios::binary | ios::ate);
    if(myfile.is_open()) {
        size = myfile.tellg();
        memoryblock = new char[size];
        myfile.seekg(0, ios::beg);
        myfile.read(memoryblock, size);
        myfile.close();
        cout << "the entire file content is in memory!";
        delete[] memoryblock;
    } else {cout << "Enable to open file!";}
    return 0;
}
