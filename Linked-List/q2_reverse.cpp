#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};


class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node *prev = NULL;
        Node * curr = head;
        Node * next;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev =curr;
            curr = next;
        }
        return prev;
    }
    
};

int main(){
    Solution s;
    return 0;
}
    