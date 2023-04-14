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
    ListNode* oddEvenList(ListNode* head) {
        ListNode * ohead = (ListNode *)malloc(sizeof(ListNode));
        ListNode * ehead = (ListNode *)malloc(sizeof(ListNode));
        ListNode *oc = ohead;
        ListNode *ec = ehead;
        oc->next = NULL;
        ec->next = NULL;
        ListNode * curr = head;
        while(curr!=NULL){
            if(curr->val % 2 == 0){
                ec->next = curr;
                ec = ec->next;
            }
            else{
                oc->next = curr;
                oc = oc->next;
            }
            curr = curr->next;
        }
        ec->next = ohead->next;
        oc->next = NULL;
        return ehead->next;
    }
};
