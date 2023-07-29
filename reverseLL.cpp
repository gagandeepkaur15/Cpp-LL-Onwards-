#include<iostream>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode* next;

    ListNode(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};

//USING RECURSION (I)

/* 
class Solution {
public:
    void reverse(ListNode* &head, ListNode* &curr, ListNode* &prev){
      //base case
      if(curr==NULL){
        head=prev;
        return;
      } 

      ListNode* forward=curr->next;
      reverse(head, forward, curr);
      curr->next=prev;      
    }
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode* curr=head;
        ListNode* prev=NULL;

        reverse(head,curr,prev);
        return head;
    
        return prev;
    }
};

*/

/*
USING RECURSION (2)

class Solution {
public:
    //Returns head of reverse list
    ListNode* reverse2(ListNode* head){
        //Base Case
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* smallHead=reverse2(head->next);
        head->next->next=head;
        head->next=NULL;

        return smallHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        
        return reverse2(head);

    }
};

*/