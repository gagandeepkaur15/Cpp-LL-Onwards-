#include<iostream>
#include<stack>
using namespace std;

//IMPLEMENTATION OF STACK USING ARRAY
class Stack{
    public:
        int *arr;
        int top;
        int size;
    
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int element) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
        } else {
            top++;
            arr[top] = element;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }
    
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    // //Creation
    // stack<int> s;

    // //Push
    // s.push(2);
    // s.push(3);
    // s.push(6);
    // s.push(1);

    // //Pop
    // s.pop();

    // //Top 
    // cout<<"Top Element: "<<s.top()<<endl;

    // if(s.empty()){
    //     cout<<"Stack is empty"<<endl;
    // } else {
    //     cout<<"Stack is not empty"<<endl;
    // }

    // cout<<"Stack size: "<<s.size()<<endl;

    Stack st(5);

    st.push(5);
    st.push(9);
    st.push(2);
    st.push(7);

    cout<<"Top: "<<st.peek()<<endl;
    st.pop();
    cout<<"Top: "<<st.peek()<<endl;

    if(st.isEmpty()){
        cout<<"Stack is empty"<<endl;
    } else{
        cout<<"Stack is not empty"<<endl; 
    }

    stack<int> s;
    s.push(2);
    s.push(9);
    s.push(3);
    s.push(1);
    s.push(7);

    int count=0;
    int middleIndex=s.size()/2;
    
     

    return 0;
}