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
    void remove(ListNode* head){
        ListNode* temp=head->next;
        head->next=head->next->next;

        delete temp;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        
        ListNode* slow=head;
        ListNode* fast=head;

        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==NULL){
            head=head->next;
            return head;
        }
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }

        remove(slow);
        return head;
    }
};
