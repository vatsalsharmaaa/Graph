/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
  
  Node *Merge(Node *l1,Node *l2){
      if(!l1) return l2;
      if(!l2) return l1;
      
      if(l1->data < l2->data){
          l1->bottom= Merge(l1->bottom,l2);
          return l1;
      }
      
      else{
          l2->bottom= Merge(l1,l2->bottom);
          return l2;
      }
      return NULL;
  }
    Node *flatten(Node *head) {
        if(head==NULL){
            return NULL;
        }
        Node *head2= flatten(head->next);
        return Merge(head,head2);
        
    }
};