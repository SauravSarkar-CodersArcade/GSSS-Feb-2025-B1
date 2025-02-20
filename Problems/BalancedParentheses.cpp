#include <bits/stdc++.h>
using namespace std;
bool isBalancedParentheses(const string s){
    stack<char> stk;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            stk.push(s[i]); // Push opening brackets to the stack
        }else{
            if(!stk.empty() && 
        ((stk.top() == '(' && s[i] == ')') ||
         (stk.top() == '{' && s[i] == '}') ||
         (stk.top() == '[' && s[i] == ']'))){
            stk.pop(); // If matching, remove from the stack       
        }else{
            return false; // Mismatch or stack is empty.
        }
    }
}
    return stk.empty(); // If stack is empty, brackets are balanced
}
int main(){
    string s1 = "[()]{}{[()()]()}";
    if(isBalancedParentheses(s1)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    string s2 = "[(])";
    if(isBalancedParentheses(s2)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}