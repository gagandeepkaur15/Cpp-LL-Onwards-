#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> s;

    MinStack() {
    }

    void push(int val) {
        if (s.empty()) {
            s.push({val, val});
        } else {
            int newMin = min(val, s.top().second);
            s.push({val, newMin});
        }
    }

    void pop() {
        if (s.empty()) {
            cout << "Stack Underflow" << endl;
        } else {
            s.pop();
        }
    }

    int top() {
        if (s.empty()) {
            return -1;
        } else {
            return s.top().first;
        }
    }

    int getMin() {
        if (s.empty()) {
            return -1;
        } else {
            return s.top().second;
        }
    }
};
