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
        ListNode* nxt=head->next;

        while(curr->next!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            nxt=nxt->next;
        }

        curr->next=prev;
        return curr;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* temp=reverseLL(head);
        ListNode* h1=temp;
        ListNode* prev=temp;
        int carry=0;
        
        while(temp!=NULL){
            int total=temp->val*2+carry;
            temp->val=total%10;
            carry=total/10;
    
            prev=temp;
            temp=temp->next;
        }
        if(carry){
            prev->next=new ListNode(carry);
        }
        return reverseLL(h1);
    }
};
