#include<iostream>
#include<map>
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

Node* removeDuplicatesByIteration(Node* &head){
    Node* curr=head;

    while(curr!=NULL){
        Node* next_node=curr->next;
        Node* prev=curr;
        while(next_node!=NULL){
            if(curr->data==next_node->data){
                prev->next=next_node->next;
                delete(next_node);
                next_node=prev->next;
            }
            else{
                next_node=next_node->next;
                prev=prev->next;
            }
        }
        curr=curr->next;
    }
    return head;
}

Node *removeDuplicatesByMap(Node * &head) {
    Node *curr = head;
    Node *prev = NULL;
    map<int,bool> visited;

    if (curr == NULL){
        return NULL;
    }

    while (curr != NULL) {
        if (visited[curr->data]==true) {
            Node *temp = curr;
            curr = curr->next;
            delete (temp);
            prev->next = curr;
        }
        else {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }         
    }
    return head;
}

void display(Node* &head){
    Node* node = head;
    while(node != NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<endl;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;

    insertAtHead(head,tail,2);
    insertAtHead(head,tail,2);
    insertAtHead(head,tail,4);
    insertAtHead(head,tail,5);
    insertAtHead(head,tail,2);
    insertAtHead(head,tail,4);

    cout<<"Before removal"<<endl;
    
    display(head);

    cout<<"After removal"<<endl;

    Node * newHead = removeDuplicatesByIteration(head);
    // Node * newHead = removeDuplicatesByMap(head);
    display(newHead);
}