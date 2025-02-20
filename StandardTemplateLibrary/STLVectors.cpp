#include <bits/stdc++.h>
using namespace std;

int main(){
    // Vector is a Dynamic Array
    vector<int> numbers = {1,2,3,4,5};
    // Traversal 1
    for(auto x : numbers){
        cout << x << " ";
    } cout << endl;
    // Traversal 2
    for(int i=0; i<numbers.size(); i++){
        cout << numbers[i] << " ";
    }cout << endl;

    // Initialisation with size
    vector<int> vector1(5); // 0 0 0 0 0
    vector<int> vector2(5,10); // 10 10 10 10 10

    // Initialisation from array
    int arr[] = {1,2,3};
    vector<int> vector3(arr, arr+3);
    for(auto x : vector3){
        cout << x << " ";
    } cout << endl;

    // Important functions
    vector3.push_back(4);
    vector3.push_back(5);
    for(auto x : vector3){
        cout << x << " ";
    } cout << endl;

    cout << "Size of the vector: " << vector3.size() << endl;

    vector3.resize(10); // The size becomes 10 -> Default 0 values
    for(auto x : vector3){
        cout << x << " ";
    } cout << endl;

    vector3.resize(15, 100); // The size becomes 15 -> Default 100 values
    for(auto x : vector3){
        cout << x << " ";
    } cout << endl;

    cout << vector3.empty() << endl;
    // Insert operations
    // 1. position, value
    // 2. position, count, value
    // 3. position, first, last
    vector3.insert(vector3.begin(), 0); // Inserts 0 at the beginning
    for(auto x : vector3){
        cout << x << " ";
    } cout << endl;
    vector3.insert(vector3.begin()+1, 3, 7); 
    for(auto x : vector3){
        cout << x << " ";
    } cout << endl;
    // Erase
    vector3.erase(vector3.begin()); // Removes first element
    for(auto x : vector3){
        cout << x << " ";
    } cout << endl;
    vector3.erase(vector3.begin(), vector3.begin()+2); // Removes first two
    for(auto x : vector3){
        cout << x << " ";
    } cout << endl;
    // First & Last Elements:
    cout << "First element: " << vector3.front() << endl;
    cout << "Last element: " << vector3.back() << endl;
    return 0;
}