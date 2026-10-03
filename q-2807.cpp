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

    int gcd(int a, int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* t1=head;
        ListNode* t2=head->next;

        while(t2!=NULL && t1!=NULL){
            int newVal=gcd(t1->val,t2->val);

            ListNode* newNode=new ListNode(newVal);

            t1->next=newNode;
            newNode->next=t2;

            t1=t2;
            t2=t2->next;
        }
        return head;
    }
};
