#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>& myStack, int x){
    //Base Case
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int num=myStack.top();
    myStack.pop();

    //Recursive Call
    insertAtBottom(myStack,x);

    //Returning to previous call
    myStack.push(num);
}

void reverseStack(stack<int> &stack) {
    //Base Case
    if(stack.empty()){
        return;
    }

    int num=stack.top();
    stack.pop();

    //Recursive Call
    reverseStack(stack);

    //Returning to previous call and inserting at bottom
    insertAtBottom(stack,num);
}