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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* current=head;
        ListNode* prev=NULL;
        ListNode* nxt=current->next;

        while(current->next!=NULL){
            current->next=prev;
            prev=current;
            current=nxt;
            nxt=nxt->next;
        }
        current->next=prev;
        return current;
    }
};
