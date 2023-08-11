#include<iostream>
#include<map>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node *merge(Node *l1, Node *l2) {
 
 if(l1==NULL) return l2;
 if(l2==NULL) return l1;


  Node *dummy = new Node(-1);
  Node *ptr = dummy;

  while (l1 != NULL && l2 != NULL) {
    if (l1->data <= l2->data) {
      ptr->bottom = l1;  
      ptr = l1;
      l1 = l1->bottom;
    } else {
      ptr->bottom = l2;
      ptr = l2;
      l2 = l2->bottom; 
    }
  }
  while (l1 != nullptr) {
    ptr->bottom = l1;
    ptr = l1;
    l1 = l1->bottom;
  }
  while (l2 != NULL) {
    ptr->bottom = l2;
    ptr = l2;
    l2 = l2->bottom;
  }
  dummy =dummy->bottom;
  return dummy;
}    
    
    
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL || root->next==NULL) return root;
   
   Node* down = root;
   Node* right  = flatten(root->next);
   
   down->next = NULL;
   
   Node*ans = merge(down , right);
   return ans;
}