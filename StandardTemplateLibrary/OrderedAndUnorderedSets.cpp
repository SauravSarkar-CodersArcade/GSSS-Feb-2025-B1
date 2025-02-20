#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main(){
    set<int> numbers1;
    numbers1.insert(10);
    numbers1.insert(1);
    numbers1.insert(10);
    numbers1.insert(11);
    numbers1.insert(10);
    numbers1.insert(16);

    // Display
    cout << "Elements in the ordered-set (Sorted): ";
    for(auto x : numbers1){
        cout << x << " ";
    }cout << endl;

    unordered_set<int> numbers2;
    numbers2.insert(10);
    numbers2.insert(0);
    numbers2.insert(5);
    numbers2.insert(10);
    numbers2.insert(3);
    numbers2.insert(2);

    cout << "Elements in the unordered-set (Hashed Order): ";
    for(auto x : numbers2){
        cout << x << " ";
    }
    cout << endl;

    // Search for an element in a set
    int searchElement = 100;
    auto it = numbers2.find(searchElement);
    if(it != numbers2.end()){
        cout << "Element: " << searchElement << " Found." << endl;
    }else{
        cout << "Element: " << searchElement << " Not Found." << endl;
    }

    // Remove an element
    numbers2.erase(10);

    cout << "Elements in the unordered-set (Hashed Order) after removing 10: ";
    for(auto x : numbers2){
        cout << x << " ";
    }
    cout << endl;
    cout << "Size of the set: " << numbers2.size() << endl;
    return 0;
}