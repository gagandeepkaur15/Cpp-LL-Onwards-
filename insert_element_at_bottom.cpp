#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& myStack, int x){
    //Base Case
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    int num=myStack.top();
    myStack.pop();

    //Recursive Call
    solve(myStack,x);

    //Returning to previous call
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack,x);
    return myStack;
}
