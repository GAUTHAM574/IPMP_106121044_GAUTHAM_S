//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    void split(Node * head, Node ** a, Node **b){
        if(head->next == NULL){
            *a = head;
            *b = NULL;
            return;
        }
        Node * fast = head->next;
        Node * slow = head;
        while(fast!=NULL){
            fast = fast->next;
            if(fast){
                slow = slow->next;
                fast = fast->next;
            }
        }
        *a = head;
        *b = slow->next;
        slow->next = NULL;
        
    }
    
    Node * merge(Node * a, Node * b){
        if(a == NULL){return b;}
        if(b == NULL){return a;}
        Node * head = (Node*)malloc(sizeof(Node));
        head->next = NULL;
        Node * prev = head;
        while(a!=NULL && b!=NULL){
            if(a->data <= b->data){
                prev->next = a;
                prev = a;
                a = a->next;
            }
            else if(a->data > b->data){
                prev->next = b;
                prev = b;
                b = b->next;
            }
        }
        if(a!=NULL){
            prev->next = a;
        }
        if(b!=NULL){
            prev->next = b;
        }
        return head->next;
    }
    
    Node* mergeSort(Node* head) {
        if(head == NULL || head->next == NULL){return head;}
        Node * a ;
        Node * b;
        split(head,&a,&b);
        a=mergeSort(a);
        b=mergeSort(b);
        return merge(a,b);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends
