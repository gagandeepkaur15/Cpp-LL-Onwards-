#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str="";
    string reverse="";

    cout<<"Enter the string"<<endl;
    cin>>str;

    stack<char> st;

    for(int i=0; i<str.length(); i++){
        st.push(str[i]);
    }

    while(!st.empty()){
        reverse.push_back(st.top());
        st.pop();
    }
    
    cout<<reverse<<endl;

    return 0;
}