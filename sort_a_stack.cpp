#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &stack, int n){
	//Base Case
	if(stack.empty() || n>stack.top()){
		stack.push(n);
		return;
	}

	int num=stack.top();
	stack.pop();

	//Recursive call
	sortedInsert(stack,n);

	//Returning to previous call
	stack.push(num);
}

void sortStack(stack<int> &stack)
{
	//Base Case
	if(stack.empty()){
		return;
	}

	int num=stack.top();
	stack.pop();

	//Recursive call 
	sortStack(stack);

	//Returning to previous call
	sortedInsert(stack, num);
}