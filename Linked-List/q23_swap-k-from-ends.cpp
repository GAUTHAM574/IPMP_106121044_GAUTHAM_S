/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode * curr = head;
        while(curr!=NULL){
            curr = curr->next;
            n++;
        }
        curr = head;
        ListNode * n1;
        int loopi = max(k, n-k+1);
        int n_i = min(k,n-k+1);
        for(int i = 1 ; i <= loopi && curr!=NULL ; i++){
            if(i == n_i ){
                n1 = curr;
            }
            if( i == loopi){
                int temp = curr->val;
                curr->val = n1->val;
                n1->val = temp;
            }
            curr = curr->next;
        }
        return head;
    }
};
