#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    }

    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory is free for node with data"<<value<<endl;
    }
};

//No need to make head only tail will work

void insertNode(Node* &tail, int element, int d){
    if(tail==NULL){
        Node* newNode=new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }else{
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }

        Node* node=new Node(d);
        node->next=curr->next;
        curr->next=node;
    }
}

void deleteNode(Node* &tail, int value){
    if(tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    } else {
        Node* prev=tail;
        Node* curr=prev->next;

        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;

        //If single node is there
        if(curr==prev){
            tail=NULL;
        }

        //To handle tail for >=2 nodes
        if(tail==curr){
            tail=prev;
        }

        curr->next=NULL;
        delete curr;
    }
} 

void print(Node* tail){
   Node* node=tail;

   if(tail==NULL){
    cout<<"List is empty"<<endl;
    return;
   }

//    To print single node
//     cout<<tail->data<<" ";

//    while(tail->next!=node){
//     cout<<tail->data<<" ";
//     tail=tail->next;
//    } 
//    cout<<endl;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    } while (tail!=node);
    cout<<endl;
}

int main(){
    Node* tail = NULL;

    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

    insertNode(tail,3,7);
    print(tail);

    insertNode(tail,5,9);
    print(tail);

    insertNode(tail,5,2);
    print(tail);

    deleteNode(tail,3);
    print(tail);
    
    deleteNode(tail,2);
    print(tail);

    deleteNode(tail,7);
    print(tail);
}