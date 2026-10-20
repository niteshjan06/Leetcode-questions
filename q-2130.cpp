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

    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nxt=curr->next;
        while(curr->next!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            nxt=nxt->next;
        }
        curr->next=prev;
        return curr;
    }

    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* temp1=head;
        ListNode* temp2=reverseLL(slow);

        int maxi=INT_MIN;
        while(temp2!=NULL){
            maxi=max(maxi,temp1->val+temp2->val);

            temp1=temp1->next;
            temp2=temp2->next;
        }
        return maxi;
    }
};
