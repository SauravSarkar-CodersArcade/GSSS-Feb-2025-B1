#include <bits/stdc++.h>
#include <string>
using namespace std;
class TrieNode {
    public:
    TrieNode* children[26];
    bool isEndOfWord;
    int childrenCount;
    TrieNode(){
        isEndOfWord = false;
        childrenCount = 0;
        for(int i=0; i<26; i++){
            children[i] = nullptr;
        }
    }
};
void insert(TrieNode* root, const string& key){
    TrieNode* current = root;
    for(char c : key){
        int index = c - 'a';
        if(current->children[index] == nullptr){
            // Node doesn't exist, so create a new node containing that character
            current->children[index] = new TrieNode();
            current->childrenCount++;
        }
        // Move to the children for the next characters
        current = current->children[index];
    }
    current->isEndOfWord = true;
}
string longestCommonPrefix(TrieNode* root){
    string prefix = "";
    TrieNode* current = root;
    // There should be a node which is not null
    // There should be only one children
    // We should traverse till the end of the word
    while(current && current->childrenCount == 1 && !current->isEndOfWord){
        for(int i=0; i<26; i++){
            if(current->children[i] != nullptr){
                prefix += i + 'a';
                current = current->children[i];
                break;
            }
        }
    }return prefix;
}
int main(){
    TrieNode* root = new TrieNode();
    vector<string> words = {"flower", "flow", "flight", "flown", "fly", "ab"};
    for(int i=0; i<words.size(); i++){
        insert(root, words[i]);
    }
    string lcp = longestCommonPrefix(root);
    if(lcp.empty()){
        cout << "There's no common prefix among the input words..!" << endl;
    }else{
        cout << "The longest common prefix is: " << lcp << endl;
    }
    return 0;
}