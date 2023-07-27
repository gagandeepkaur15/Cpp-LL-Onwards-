#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*prev;
    Node*next;

    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }

    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data"<<val<<endl;
    }
};

void print(Node* head){
    Node* node=head;
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

int getLength(Node* head){
    int len=0;
    Node* node=head;
    while(node!=NULL){
        len++;
        node=node->next;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int d){
    if(head==NULL){
        Node* node=new Node(d);
        head=node;
        tail=node;
    } else { 
        Node* node = new Node(d);
        node->next=head;
        head->prev=node;
        head=node;
    }
}

void insertAtEnd(Node* &head, Node* &tail, int  d){
    if(tail==NULL){
        Node* node=new Node(d);
        tail=node;
        head=node;
    }else{
        Node* node = new Node(d);
        tail->next=node;
        node->prev=tail;
        tail=node;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }
    Node* node = head;
    int cnt=1;
    while(cnt<position-1){
        node=node->next;
        cnt++;
    }

    if(node->next==NULL){
        insertAtEnd(head,tail,d);
        return;
    }

    //Creating a node
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next=node->next;
    node->next->prev=nodeToInsert;
    node->next=nodeToInsert;
    nodeToInsert->prev=node; 
}

void deleteNode(int position, Node* &head, Node* &tail){
    //First node
    if(position==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;    
        }
        if(curr->next==NULL){
            tail=prev;
        }
        curr->prev=NULL; 
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main(){
    // Node* node = new Node(10);
    // Node* head = node;
    // Node* tail = node;

    Node* head=NULL;
    Node* tail=NULL;

    print(head);
    int len=getLength(head);
    cout<<len<<endl;
    
    insertAtHead(head,tail,12);
    print(head);

    insertAtEnd(head,tail,40);
    print(head);

    insertAtEnd(head,tail,100);
    print(head);

    insertAtPosition(head,tail,2,500);
    print(head);

    deleteNode(4,head,tail);
    print(head);
    cout<<tail->data;

    return 0;
}