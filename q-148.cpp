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

    ListNode* MergeLL(ListNode* left, ListNode* right){

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                temp->next = left;;
                temp=temp->next;
                left=left->next;
            }else{
                temp->next = right;
                temp=temp->next;
                right=right->next;
            }
        }

        if(left){
            temp->next=left;
        }

        if(right){
            temp->next=right;
        }

        ListNode* answer = dummyNode->next;
        delete dummyNode;
        return answer;
    }

    ListNode* middleNode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* middle=middleNode(head);
        
        ListNode* right=middle->next;
        middle->next=NULL;

        ListNode* left=head;
        
        left=sortList(left);
        right=sortList(right);

        return MergeLL(left,right);

    }
};
