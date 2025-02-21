#include <iostream>
using namespace std;
class GSSSIETW {
    int i; // 4 bytes
    char c; // 1 byte
    short s; // 2 bytes
    
};
int main(){
    GSSSIETW obj;
    // By default a class is allocated 1 byte of memory by the CPU
    cout << "Size of the class: " << sizeof(obj) << " Bytes." << endl;  
    return 0;
}