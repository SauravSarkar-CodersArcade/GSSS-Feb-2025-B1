#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, list<string>> studentFavFood;
    list<string> Monisha {"Biryani","Rasam","Tomato Bath"};
    list<string> Varshini {"Masala Dosa","Mudde","Vada"};
    list<string> Firdaus {"Pizza","Burger","Noodles"};
    studentFavFood.insert(
        pair<string, list<string>>("Monisha", Monisha)
    );
    studentFavFood.insert(
        pair<string, list<string>>("Varshini", Varshini)
    );
    studentFavFood.insert(
        pair<string, list<string>>("Firdaus", Firdaus)
    );
    // Traversal of the map with list of strings
    for(auto pair : studentFavFood){
        // This is for the first element in the pair "Name"
        cout << "Name: " << pair.first << " <-> Food: ";
        // This is for all the food items for each student
        for(auto food : pair.second){
            cout << food << ", ";
        }  
        cout << endl;
    }
    // std::make_pair(x,y); -> This converts two values into a pair
    return 0;
}