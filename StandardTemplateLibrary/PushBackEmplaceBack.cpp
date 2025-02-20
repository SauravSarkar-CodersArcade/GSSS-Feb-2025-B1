#include <iostream>
#include<vector>
using namespace std;
class Person {
    public:
    string Name;
    int Age;
    Person(string name, int age){
        Name = name;
        Age = age;
    }
};
int main(){
    // push_back -> Not memory efficient -> needs to provide data type
    // emplace_back -> memory efficient -> no data type needed
    vector<Person> people;
    people.push_back(Person("Ashank", 27)); // Just creates a copy not an object
    people.emplace_back("Saurav", 36); // It directly calls the constructor
    for(auto person : people){
        cout << person.Name << " is " << person.Age << " years old." << endl;
    }
    return 0;
}