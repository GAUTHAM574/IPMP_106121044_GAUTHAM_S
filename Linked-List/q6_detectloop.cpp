//User function template for C++
#include<iostream>
using namespace std;

struct Node
{
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
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        if(head == NULL){return false;}
        Node * slow = head;
        Node * fast = head->next;
        while(slow!=NULL && fast!=NULL){
            if(slow == fast){return true;}
            slow = slow->next;
            fast = fast->next;
            if(fast!=NULL){fast = fast->next;}
        }
        return false;
    }
};