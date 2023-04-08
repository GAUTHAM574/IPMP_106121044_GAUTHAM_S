#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    int data = x;
	    next = NULL;
	}
};

// Complete this function
void deleteAlt(struct Node *head){
    Node * p = head;
    while(p!=NULL && p->next!=NULL){
        p->next = p->next->next;
        p = p->next;
    }
}