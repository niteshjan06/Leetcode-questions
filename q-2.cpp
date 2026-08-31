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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead;
        int carry=0;

        ListNode* t1=l1;
        ListNode* t2=l2;
        
        while(t1!=NULL || t2!=NULL){
            int sum=0;
            
            if(t1){
                sum+=t1->val;
            }
            if(t2){
                sum+=t2->val;
            }
             
            if(sum%10+carry>=10){
                temp->next = new ListNode(0);
                carry=1;
            }else{
                temp->next = new ListNode(sum%10+carry);
                carry=sum/10;
            }

            temp=temp->next;

            if(t1!=NULL){
                t1=t1->next;
            }
            if(t2!=NULL){
                t2=t2->next;
            }
        }

        if(carry){
            temp->next = new ListNode(carry);
        }
        return dummyHead->next;
    }
};
