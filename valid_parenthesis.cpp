#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            } else if (!st.empty() &&
                       (s[i] == '}' && st.top() == '{' ||
                        s[i] == ']' && st.top() == '[' ||
                        s[i] == ')' && st.top() == '(')) {
                st.pop();
            } else {
                return false;  // Mismatched bracket or stack empty
            }
        }
        return st.empty();  // Check if the stack is empty after processing all characters
    }
};