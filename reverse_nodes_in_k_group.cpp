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
    int len(ListNode* &head) {
        int count=0;
        ListNode* node = head;
            while (node != NULL) {
            count++;
            node = node->next;
        }
        return count;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = len(head);
        if (length < k) {
            return head;
        }

        //base case if we want to reverse the remaining nodes that are <k 
        // if(head==NULL){
        //     return NULL;
        // }

        //Reverse first k nodes
        ListNode* next=NULL;
        ListNode* curr=head;
        ListNode* prev=NULL;
        int count=0;

        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }

        //Recursive call
        if (next != NULL) {
            ListNode* restHead = reverseKGroup(next, k);
            head->next = restHead;
        }

        return prev;
    }
};