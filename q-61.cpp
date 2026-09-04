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
    // function for finding the tail of the LL
    ListNode* tail(ListNode* head){
        while(head->next!=NULL){
            head=head->next;
        }
        return head;
    }
    // function for finding the length of the LL
    int lengthLL(ListNode* head){
        int count=1;
        while(head->next!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        if(k==0){
            return head;
        }
        int length = lengthLL(head);
        int rotate = length-(k%length);

        if(rotate==length){
            return head;
        }
        ListNode* temp=head;
        int count=1;
        while(temp!=NULL && count!=rotate){
            count++;
            temp=temp->next;
        }

        ListNode* rotateNode = temp->next;
        tail(head)->next=head;
        temp->next=NULL;

        return rotateNode;
    }
};
