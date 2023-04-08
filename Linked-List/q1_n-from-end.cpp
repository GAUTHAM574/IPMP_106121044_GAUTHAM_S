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


//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       int l = 0; // Length of the string
       Node * curr = head;
       while(curr!=NULL){
           curr=curr->next;
           l++;
       }
       if(n>l){return -1;}
       curr = head;
       //travsersing length - n from start
       for(int i = 0; i <l-n;i++){
           curr=curr->next;
       }
       return curr->data;
}