#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=NULL;    
    }
};

class myStack {
    public:
    // Insert at end
void push(Node* &head, Node* &tail, int d){
    if(tail==NULL){
        Node* node=new Node(d);
        tail=node;
        head=node;
   }
   else{
        Node* node=new Node(d);
        tail->next=node;
        tail=node;
   }
}

//Delete from end
void pop(Node* &head, Node* &tail){
    if(tail==NULL){
        cout<<"Stack Underflow"<<endl;
    }
    
    Node *node=head;
    if(node->next==NULL){
        head=NULL;
        tail=NULL;
    }

    while(node->next->next!=NULL){
        node=node->next;
    }
    node->next=NULL;
    tail=node;
}

//Display tail
void top(Node* &head, Node* &tail){
    cout<<tail->data<<endl;
}

void displayALL(Node*& head, Node*& tail) {
        Node* node = head;
        while (node != NULL) {
            cout << node->data << endl;
            node = node->next;
        }
}


void isEmpty(Node* &head, Node* &tail){

}
};



int main(){
    myStack st;

    Node* head=NULL;
    Node* tail=NULL;
    st.push(head, tail, 2); 
    st.push(head, tail, 4); 
    st.push(head, tail, 6); 
    st.push(head, tail, 8);

    cout<<"Top "<<endl;
    st.top(head, tail);
    cout<<"All elements "<<endl;
    st.displayALL(head, tail);

    st.pop(head, tail);
    cout<<"Top "<<endl;
    st.top(head, tail);
    cout<<"All elements "<<endl;
    st.displayALL(head, tail);
}