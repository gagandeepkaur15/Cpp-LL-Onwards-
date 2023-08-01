#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*prev;
    Node*next;

    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
};

void print(Node* head){
    Node* node=head;
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

void insertAtEnd(Node* &head, Node* &tail, int  d){
    if(tail==NULL){
        Node* node=new Node(d);
        tail=node;
        head=node;
    }else{
        Node* node = new Node(d);
        tail->next=node;
        node->prev=tail;
        tail=node;
    }
}

Node* reverse(Node* &head){
    Node* ptr1=head;
    Node* ptr2=ptr1->next;
    ptr1->next=NULL;
    ptr1->prev=ptr2;

    while(ptr2!=NULL){
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    head=ptr1;
    return head;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;

    insertAtEnd(head,tail,1);
    insertAtEnd(head,tail,2);
    insertAtEnd(head,tail,3);
    insertAtEnd(head,tail,4);
    insertAtEnd(head,tail,5);

    print(head);

    reverse(head);
    print(head);
}

