#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }

        ListNode* curr = head;

        while(curr!=NULL){
            if(curr->next!=NULL && curr->val==curr->next->val){
                ListNode* next = curr->next->next;
                ListNode* nodeToDelete = curr->next;
                delete(nodeToDelete); // First deleted then pointer updated so that track is not lost
                curr->next=next;
            }
            else {
                curr=curr->next;
            }
        }
        return head;
    }
};