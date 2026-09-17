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

        while(curr!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(nxt)nxt=nxt->next;
        }
        // curr->next=prev;
        return curr;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* leftNode=head;
        ListNode* rightNode=head;
        ListNode* l=NULL;
        ListNode* r=NULL;

        while(left!=1){
            l=leftNode;
            leftNode=leftNode->next;
            left--;
        }

        while(right!=1){
            rightNode=rightNode->next;
            if(rightNode){
                r=rightNode->next;
            }else{
                r=NULL;
            }
            right--;
        }

        
        if(leftNode==head && rightNode->next==NULL){
            reverseLL(leftNode);
            return rightNode;
        }
        if(leftNode==head){
            if(r){
                rightNode->next=NULL;
                reverseLL(leftNode);
                leftNode->next=r;
                return rightNode;
            }
        }else if(rightNode->next==NULL){
            if(l){
                l->next=NULL;
                reverseLL(leftNode);
                l->next=rightNode;
            }
        }else{
            l->next=NULL;
            rightNode->next=NULL;
            reverseLL(leftNode);
            l->next=rightNode;
            leftNode->next=r;
        }
        return head;
    }
};
