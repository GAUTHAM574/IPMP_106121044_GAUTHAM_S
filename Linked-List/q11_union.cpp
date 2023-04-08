#include<bits/stdc++.h>
using namespace std;

// structure of the node is as follows

struct node
{
	int data;
	struct node* next;
	
	node(int x){
	    data = x;
	    next = NULL;
	}
	
};



struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    set<int> s;
    Node temp = Node(-1);
    Node * p = &temp;
    p->next = head1;
    Node * p1 = head1;
    while(p1->next !=NULL){
        p1=p1->next;
    }
    if(!head1){p->next = head2;}
    else{
        p1->next = head2;
    }
    p1 = p->next;
    while(p1 != NULL && p1->next != NULL){
        if(s.find(p1->data) != s.end()){
            p->next = p1->next;
        }
        else{
            s.insert(p1->data);
            p = p1;
        }
        p1 = p1->next;
    }
    // cout<<p->data<<endl;
    // cout<<p1->data<<endl;
    if(p1!=NULL && s.find(p1->data) != s.end()){
        p->next = NULL;
    }
    else if(p1!=NULL){
        s.insert(p1->data);
    }
    p1 = temp.next;
    for(auto i : s){
        p1->data = i;
        p1=p1->next;
    }
    return temp.next;
}