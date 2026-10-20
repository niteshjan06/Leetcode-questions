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

        while(nxt!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nxt;

            nxt=nxt->next;
        }
        curr->next=prev;
        return curr;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        ListNode* temp1=l1;
        ListNode* temp2=l2;

        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;

        int carry=0;
        while(temp1!=NULL || temp2!=NULL){
            int sum=0;
            if(temp1) sum+=temp1->val;
            if(temp2) sum+=temp2->val;

            int total=sum+carry;
            temp->next=new ListNode(total%10);
            carry=total/10;
            temp=temp->next;
        
            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;
        }
        if(carry){
            temp->next=new ListNode(carry);
        }
        return reverseLL(dummyNode->next);
    }
};
