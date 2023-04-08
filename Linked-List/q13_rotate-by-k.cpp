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




class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        int n = 0;
        Node * p = head;
        while( p != NULL ){
            p = p->next;
            n++;
        }
        Node * fakhead = (Node*)malloc(sizeof(Node));
        fakhead->next = head;
        Node * after_k = head;
        k = k%n;
        if(k == 0){
            return head;
        }
        Node * par = fakhead;
        for(int i = 0 ; i < k ; i++ ){
            par = after_k;
            after_k = after_k->next;
        }
        par->next = NULL;
        Node * newHead = after_k;
        while(after_k->next!=NULL){
            after_k = after_k->next;
        }
        after_k->next = head;
        return newHead;
    }
};
    