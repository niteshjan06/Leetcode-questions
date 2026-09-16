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
    ListNode* swapNodes(ListNode* temp, ListNode* kthNode){
        temp->next=NULL;
        kthNode->next=temp;
        return kthNode;
    }
    bool swapPossible(ListNode* head){
        if(head==NULL || head->next==NULL){
            return false;
        }
        return true;
    }

    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* temp=head;
        ListNode* prev=NULL;

        while(temp!=NULL){
            if(!swapPossible(temp)){
                if(prev) prev->next=temp;
                return head;
            }

            ListNode* kthNode=temp->next;
            ListNode* nextNode=kthNode->next;
            kthNode->next=NULL;

            swapNodes(temp,kthNode);

            if(temp==head){
                head=kthNode;
            }

            if(prev){
                prev->next=kthNode;
            }

            prev=temp;
            temp=nextNode;
        }
        return head;
    }
};
