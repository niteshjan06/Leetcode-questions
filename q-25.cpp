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

    ListNode* findKthNode(ListNode* head, int k){
        int count=1;
        ListNode* temp=head;
        while(temp!=NULL && count!=k){
            count++;
            temp=temp->next;
        }
        if(count!=k){
            return NULL;
        }
        return temp;
    }
    
    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* curr=head;
        ListNode* nxt=head->next;
        ListNode* prev=NULL;

        while(curr!=NULL && curr->next!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            nxt=nxt->next;
        }

        curr->next=prev;
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* temp=head;
        

        ListNode* prevNode=NULL;
        ListNode* nxtNode=NULL;

        while(temp!=NULL){
            ListNode* kthNode = findKthNode(temp,k);
            
            if(kthNode == NULL){
                prevNode->next=temp;
                return head;
            }

            nxtNode=kthNode->next;
            kthNode->next=NULL;

            reverseLL(temp);
            if(temp==head){
                head=kthNode;
            }   

            if(prevNode){
                prevNode->next=kthNode;
            }
            prevNode=temp;
            temp=nxtNode;
        }
        return head;
    }
};
