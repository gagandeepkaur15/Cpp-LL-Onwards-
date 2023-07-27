#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //Constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value=this->data;
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data"<<value<<endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, int d){
    if(head==NULL){
        Node* node=new Node(d);
        head=node;
        tail=node;
    }else{
        //Create new node
        Node* node = new Node(d);

        //Inserting
        node -> next = head;
        head = node; 
    }
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

void display(Node* &head){
    Node* node = head;
    while(node != NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    //Insert at beg
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
        insertAtTail(head,tail,d);
        return;
    }

    //Creating a node
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next=node->next;
    node->next=nodeToInsert;
}

void deleteNode(int position, Node* &head, Node* &tail){
    //First node
    if(position==1){
        Node* temp=head;
        head=head->next;
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
        //To handle if the deleted node is tail
        if(curr->next==NULL){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main() {
    Node* node1 = new Node(10);

    //Head pointer
    // Node* head = node1;
    //Tail pointer
    // Node* tail=node1;

    Node* head=NULL;
    Node* tail=NULL;

    insertAtHead(head,tail,12);
    insertAtTail(head,tail,15);
    insertAtTail(head,tail,35);
    insertAtTail(head,tail,45);
    insertAtPosition(head,tail,4 ,100);

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    display(head);

    deleteNode(6,head,tail);
    display(head);
    cout<<tail->data<<endl;
}