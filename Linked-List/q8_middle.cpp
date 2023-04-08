#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        int len = 0;
        Node * p = head;
        while(p!=NULL){
            p=p->next;
            len++;
        }
        //bool flag = len%2 == 0 ? true : false;
        len = len/2;
        p = head;
        for(int i = 0 ; i < len; i++ ){
            p = p->next;
        }
        return p->data;
    }
};