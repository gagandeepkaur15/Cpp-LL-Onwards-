#include<iostream>
#include<vector>
using namespace std;

// APPROACH 1 - WITH TC-O(N) AND SC-O(N)
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

bool checkPalindrome(vector<int> arr){
    int n=arr.size();
    int s=0;
    int e=n-1;

    while(s<=e){
        if(arr[s]!=arr[e]){
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}

bool isPalindrome(Node *head)
{
    vector<int> arr;
    Node* temp=head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    return checkPalindrome(arr);
}

// APPROACH 2 - WITH TC-O(N) AND SC-O(1)

/****************************************************************

    Following is the class structure of the Node class:

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

*****************************************************************/
Node* getMid(Node* head){
    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

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

bool isPalindrome(Node *head)
{
    if(head==NULL || head->next==NULL){
        return true;
    }

    // Finding middle
    Node* middle=getMid(head);

    // Reversing LL after middle
    Node* temp = middle->next;
    middle->next=reverse(temp);

    // Comparing both halves
    Node* head1=head;
    Node* head2=middle->next;

    while(head2!=NULL){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }

    // Reversing the LL again
    temp=middle->next;
    middle->next=reverse(temp);

    return true;
}