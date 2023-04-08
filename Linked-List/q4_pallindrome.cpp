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


class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        int n = 0;
        Node * curr = head;
        while(curr!=NULL){
            curr = curr->next;
            n++;
        }
        if(n==1){return true;}
        if(n==2){return head->data == head->next->data;}
        Node * revhead = head;
        for(int i = 0; i<n/2;i++){
            revhead=revhead->next;
        }
        Node * revcurr = revhead->next;
        if(n%2==0){revcurr = revhead;}
        Node * prev = NULL;
        Node * next;
        while(revcurr!=NULL){
            next = revcurr->next;
            revcurr->next = prev;
            prev = revcurr;
            revcurr = next;
        }
        revcurr = prev;
        curr = head;
        while(curr!=NULL && revcurr!=NULL){
            if(curr->data!=revcurr->data){return false;}
            curr = curr->next;
            revcurr = revcurr->next;
        }
        return true;
    }
};

int main(){
    Solution s;
    return 0;
}