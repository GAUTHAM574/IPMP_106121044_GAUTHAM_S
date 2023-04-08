

#include<iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};



Node* findIntersection(Node* head1, Node* head2)
{
   Node dummy = Node(0);
   Node * head3 = &dummy;
   Node * p3 = head3;
   while(head1!=NULL && head2!=NULL){
      if(head1->data == head2->data){
          Node * temp = (Node *)malloc(sizeof(Node));
          temp->data = head1->data;
          p3->next = temp;
          p3 = p3->next;
          head1 = head1->next;
          head2 = head2->next;
      } 
      else if( head1->data > head2->data){
          head2 = head2->next;
      }
      else if( head1->data < head2->data){
          head1 = head1->next;
      }
   }
   return head3->next;
   
   
}