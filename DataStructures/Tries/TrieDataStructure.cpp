#include <iostream>
#include <vector>
#include <string>
using namespace std;
class TrieNode {
    public:
    TrieNode* children[26]; // Alphabets A-Z or a-z
    bool wordEnd;
    TrieNode(){
        wordEnd = false;
        for(int i=0; i<26; i++){
            children[i] = nullptr; // Initially no nodes are present
        }
    }
};
void insert_word(TrieNode* root, string& word){
    // A R Y A N
    TrieNode* current = root;
    for(auto c : word){
        if(current->children[c-'a'] == nullptr){
            // Node is not present in the trie, so create new node
            TrieNode* newNode = new TrieNode();
            current->children[c-'a'] = newNode;
        }
        current = current->children[c-'a'];
        current->wordEnd = true; // or 1
    }
}
bool search_word(TrieNode* root, string& word){
    TrieNode* current = root;
    for(auto c : word){
        if(current->children[c-'a'] == nullptr){
            // Node is not present in the trie, return false
            return false;
        }
        current = current->children[c-'a'];
    }
    return current->wordEnd;
}
using namespace std;
int main(){
    TrieNode* root = new TrieNode();
    vector<string> input_words = 
    {"ashwini", "vamshi", "sanjana", "poornima", "supreetha"};
    for(int i=0; i<input_words.size(); i++){
        insert_word(root, input_words[i]);
    }
    vector<string> search_words = 
    {"ashwini", "vamshi","ramya", "sanjana", "poornima", "supreetha", "uma", "prema"};
    for(int i=0; i<search_words.size(); i++){
        if(search_word(root, search_words[i])){
            cout << search_words[i] << " is present in the Trie." << endl;
        }else{
            cout << search_words[i] << " is not present in the Trie." << endl;
        }
    }
    return 0;
}