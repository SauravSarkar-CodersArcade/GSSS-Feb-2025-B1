#include <bits/stdc++.h>
#include<map> // Sorted / Alphabetical Order
#include<unordered_map> // Hashing Order // HashMap
using namespace std;

int main(){
    map<string, string> stateLanguages;
    stateLanguages.insert(pair<string, string>("Karnataka", "Kannada"));
    stateLanguages.insert(pair<string, string>("Kerala", "Malayalam"));
    stateLanguages.insert(pair<string, string>("Goa", "Konkani"));
    stateLanguages.insert(pair<string, string>("Maharashtra", "Marathi"));
    stateLanguages.insert(pair<string, string>("West Bengal", "Bengali"));
    stateLanguages["Andhra Pradesh"] = "Telugu";
    // stateLanguages.clear(); Deletes everything
    stateLanguages.erase("West Bengal");
    for(auto data : stateLanguages){
        cout << "State: " << data.first << "<-> Language: " <<
        data.second << endl;
    }
    return 0;
}