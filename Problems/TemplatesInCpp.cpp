#include <bits/stdc++.h>
using namespace std;
template <typename T>
void swapNumbers(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}
template <typename X>
void addAnything(X &a, X &b){

}
int main() {
	int a = 10;
    int b = 20;
    char c = 'c';
    char d = 'd';
    cout << "Before: c = " << c << " d = " << d << endl;
    swapNumbers(c,d);
    cout << "After: c = " << c << " d = " << d << endl;
}
