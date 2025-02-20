#include <bits/stdc++.h>
using namespace std;

int main(){
    // Singly Linked List
    // No insertions via tail/end
    forward_list<int> flist = {10,20,30};
    flist.push_front(5);
    flist.push_front(0);
    // Traversal 1 -> For Each Loop
    for(int x : flist){
        cout << x << " ";
    }
    cout << endl;
    // Traversal 2 -> Using Iterator
    for(auto it = flist.begin(); it != flist.end(); ++it){
        cout << *it << " ";
    }cout << endl;
    // What is the 'auto' keyword in iterator actually replacing?
    for(forward_list<int>::iterator it = flist.begin(); it != flist.end(); ++it){
        cout << *it << " ";
    }cout << endl;
    // Traversal 3 -> For Each Loop with auto
    for(auto x : flist){
        cout << x << " ";
    }cout << endl;
    // It is not allowed to insert element at the end / tail.
    // How do we do it manually?
    // By traversing till the end & insert using iterator
    auto it = flist.begin();
    while (next(it) != flist.end())
    {
        ++it;
    }
    flist.insert_after(it, 50);
    it++;
    flist.insert_after(it, 40);
    for(auto x : flist){
        cout << x << " ";
    }cout << endl;
    it++;
    flist.insert_after(it, 100);
    for(auto x : flist){
        cout << x << " ";
    }cout << endl;
    return 0;
}