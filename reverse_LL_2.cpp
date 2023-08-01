#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail, int d) {
    if (head == NULL) {
        Node* node = new Node(d);
        head = node;
        tail = node;
    } else {
        // Create new node
        Node* node = new Node(d);

        // Inserting
        node->next = head;
        head = node;
    }
}

void reverseBetween(Node* &head, int left, int right) {
    if (head == NULL || head->next == NULL || left == right) {
        return;
    }

    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;

    for (int i = 0; i < left - 1; i++) { 
        prev = prev->next;
    }

    Node* curr = prev->next;
    Node* next_node = curr->next;

    for (int i = 0; i < right - left; i++) {
        curr->next = next_node->next;
        next_node->next = prev->next;
        prev->next = next_node;
        next_node = curr->next;
    }

    head = dummy->next;
    delete dummy;
}

void display(Node* &head) {
    Node* node = head;
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(10);

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 6);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 7);

    display(head);

    reverseBetween(head, 2, 4);
    display(head);
}


/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL || left==right){
            return head;
        }

        ListNode* temp=new ListNode();
        temp->next=head;
        ListNode* prev=temp;

        for(int i=0; i<left-1; i++){
            prev=prev->next;
        }

        ListNode* curr=prev->next;
        ListNode* next_node=curr->next;

        for(int i=0; i<right-left;i++){
            curr->next=next_node->next;
            next_node->next=prev->next;
            prev->next=next_node;
            next_node=curr->next;
        }

        head=temp->next;
        delete temp;

        return head;
    }
};
*/



