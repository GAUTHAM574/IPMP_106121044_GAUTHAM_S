/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * @input B : Integer
 * 
 * @Output head pointer of list.
 */
 
ListNode* reverse(ListNode* head,int B, int n){
    ListNode * next;
    ListNode * prev = NULL;
    ListNode *curr = head;
    for(int i = 0; i < B; i++){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = curr;
    if(curr == NULL){return prev;}
    for(int i = 0 ; i < B && head!=NULL; i++){
        head = head->next;
    }
    head->next = reverse(head->next,B,n-B-B);
    return prev;
} 
 

ListNode* solve(ListNode* A, int B) {
    int n = 0;
    ListNode* curr = A;
    while(curr!=NULL){
        curr=curr->next;
        n++;
    }
    return reverse(A,B,n);
}