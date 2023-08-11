#include<iostream>
#include<map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    void insertAtTail(Node* &cloneHead, Node* &cloneTail, int d){
       if(cloneTail==NULL){
           Node* node=new Node(d);
           cloneTail=node;
           cloneHead=node;
       } 
       else{
           Node* node=new Node(d);
           cloneTail->next=node;
           cloneTail=node;
       }
    }

    Node* copyRandomList(Node* head) {
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp=temp->next;
        }

        map<Node*,Node*> oldToNewNode;

        Node* originalNode=head;
        Node* cloneNode=cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL){
            oldToNewNode[originalNode]=cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }

        originalNode=head;
        cloneNode=cloneHead;
        while(originalNode!=NULL){
            cloneNode->random=oldToNewNode[originalNode->random];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }
};