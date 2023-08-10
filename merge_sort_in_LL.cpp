#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }

        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;

        while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }
        while(left!=NULL){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        while(right!=NULL){
            temp->next=right;
            temp=right;
            right=right->next;
        }
        ans=ans->next;
        return ans;
    }

    ListNode* sortList(ListNode* head) {
        //Base Case
        if(head==NULL || head->next==NULL){
            return head;
        }

        //Split Linked List in two halves
        ListNode* mid=findMid(head);

        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;

        //Recursive Call in both halves
        left=sortList(left);
        right=sortList(right);

        //Merge the two halves
        ListNode* result=merge(left,right);

        return result;
    }

    void insertAtHead(ListNode* &head, ListNode* &tail, int d){
    if(head==NULL){
        ListNode* node=new ListNode(d);
        head=node;
        tail=node;
    }else{
        //Create new node
        ListNode* node = new ListNode(d);

        //Inserting
        node -> next = head;
        head = node; 
    }
}

void display(ListNode* &head){
    ListNode* node = head;
    while(node != NULL){
        cout<<node->val<<" ";
        node=node->next;
    }
    cout<<endl;
}

int main() {
    ListNode* head=NULL;
    ListNode* tail=NULL;

    insertAtHead(head,tail,12);
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,2);
    insertAtHead(head,tail,17);
    insertAtHead(head,tail,6);
    insertAtHead(head,tail,10);

    display(head);

    ListNode* ans=sortList(head);
    display(ans);
}