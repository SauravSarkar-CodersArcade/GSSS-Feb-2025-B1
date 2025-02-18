#include <iostream>
using namespace std;
namespace sahana{
    int x = 500;
    void add(int a, int b){

    }
}
namespace ramya{
    int x = 200;
    void add(int a, int b){

    }
} 

int main(){
    int a = 10;
    int * ptr = &a;
    cout << ptr << endl;
    cout << &ptr << endl; // 2000
    int ** dPtr = &ptr;
    cout << dPtr << endl; // 2000
    cout << **dPtr << endl; // value of a
    ramya::add(1,2); // :: Scope Resolution Operator
    sahana::x;
    return 0;
}