#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

// Approach 1- By changing data in nodes
Node* sortList(Node *head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp != NULL){
        if(temp->data==0){
            zeroCount++;
        }
        else if(temp->data==1){
            oneCount++;
        }
        else if(temp->data==2){
            twoCount++;
        }
        temp=temp->next;
    }

    temp=head;
    while(temp!=NULL){
        if(zeroCount!=0){
            temp->data=0;
            zeroCount--;
        }
        else if(oneCount!=0){
            temp->data=1;
            oneCount--;
        }
        else if(twoCount!=0){
            temp->data=2;
            twoCount--;
        }
        temp=temp->next;
    }
    return head;
}

// Approach 2- By changing pointers

void insertAtTail(Node* &tail, Node* curr){
    tail->next=curr;
    tail=curr;
}

Node* sortList(Node *head){
    //LL with dummy nodes
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    //Insertion will be done at tail 
    Node* zeroTail=zeroHead;
    Node* oneTail=oneHead;
    Node* twoTail=twoHead;

    Node* curr=head;

    while(curr!=NULL){
        int value=curr->data;
        if(value==0){
            insertAtTail(zeroTail,curr);
        }
        else if (value==1){
            insertAtTail(oneTail,curr);
        }
        else if (value==2){
            insertAtTail(twoTail,curr);
        }
        curr=curr->next;
    }

    //Merge LL
    if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
    }
    else{
        zeroTail->next=twoHead->next;
    }
    oneTail->next=twoHead->next;
    twoTail->next=NULL;

    head=zeroHead->next;

    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}