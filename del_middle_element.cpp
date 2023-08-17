#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&inputStack, int count, int size){
   //Base Case
   if(count==size/2){
      inputStack.pop();
      return;
   }

   int num=inputStack.top();
   inputStack.pop();

   //Next Call
   solve(inputStack,count+1,size);

   //Returning to Previous Call
   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
   int count=0;
   solve(inputStack, count, N);   
}