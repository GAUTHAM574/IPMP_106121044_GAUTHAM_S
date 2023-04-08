#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};



class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if(head == NULL){return;}
        Node * slow = head;
        Node * fast = head->next;
        Node * prev=NULL;
        bool found = false;
        while(slow!=NULL && fast!=NULL){
            if(slow == fast){
                found = true;
                break;
            }
            slow = slow->next;
            fast = fast->next;
            if(fast!=NULL){fast = fast->next;}
        }
        if(found){
            Node * curr = slow;
            int k = 1;
            while(curr->next != slow){
                curr = curr->next;
                k++;
            }
            curr = head;
            Node * curr2 = head;
            for(int i = 0 ; i< k ; i++){
                curr2 = curr2->next;
            }
            while(curr!=curr2){
                curr = curr->next;
                curr2 = curr2->next;
            }
            while(curr2->next!=curr){
                curr2=curr2->next;
            }
            curr2->next = NULL;
        }
    }
};