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
    bool palindrome(ListNode* i,ListNode* j){
        while(j!=NULL){
            if(i->val != j->val){
                return false;
            }
            i=i->next;
            j=j->next;
        }
        return true;
    }

    void reverseLL(ListNode* mid,ListNode* curr){
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* nxt=curr->next;

            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        mid->next=prev;
    }


    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        reverseLL(slow,slow->next);

        return palindrome(head,slow->next);
    }
};
