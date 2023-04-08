#include<iostream>
using namespace std;


struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; 

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int len1 = 0;
    int len2 = 0;
    Node * p1 = head1;
    Node * p2 = head2;
    while(p1!=NULL){
        p1 = p1->next;
        len1++;
    }
    while(p2!=NULL){
        p2 = p2->next;
        len2++;
    }
    
    int diff = abs(len1 - len2);
    Node * longer = len1 >= len2 ? head1 : head2;
    Node * shorter = len1 < len2 ? head1 : head2;
    for(int i = 0 ; i < diff ; i++){
        longer = longer->next;
    }
    while(longer!=shorter && longer!=NULL){
        longer = longer->next;
        shorter = shorter->next;
    }
    return longer!=NULL? longer->data : -1;
}