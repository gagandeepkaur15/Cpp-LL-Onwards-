#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
Node* reverse(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    } 
    return prev;
}

void insertAtTail(Node* &head, Node* &tail, int d){
    if(tail==NULL){
        Node* node=new Node(d);
        tail=node;
        head=node;
    }else{
        //Creating new node
        Node* node = new Node(d);

        //Inserting
        tail->next= node;
        tail=node;
    }
}

Node* add(struct Node* first, struct Node* second){
    int carry=0;
    Node* ansHead=NULL;
    Node* ansTail=NULL;

    while(first!=NULL && second!=NULL){
        int sum=carry+first->data+second->data;
        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
        first=first->next;
        second=second->next;
    }
    while(first!=NULL){
        int sum=carry+first->data;
        int digit=sum%10;
        insertAtTail(ansHead, ansTail, digit);     
        carry=sum/10;
        first=first->next;
    }
    while(second!=NULL){
        int sum=carry+second->data;
        int digit=sum%10;
        insertAtTail(ansHead, ansTail, digit);     
        carry=sum/10;
        second=second->next;
    }
    //When both LL have equal length but carry remains at the end
    while(carry!=0){
        int sum=carry;
        int digit=sum%10;
        insertAtTail(ansHead, ansTail, digit);     
        carry=sum/10;
    }
    return ansHead;
}

struct Node* addTwoLists(Node* first, Node* second) {
        // Reverse the 2 LL
        first=reverse(first);
        second=reverse(second);

        // Add two LL
        Node* ans=add(first,second);

        ans=reverse(ans);
        return ans;
    }
};