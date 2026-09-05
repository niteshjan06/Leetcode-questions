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
    ListNode* removeElements(ListNode* head, int value) {
        if(head==NULL){
            return head;
        }

        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* del=head;

        while(temp!=NULL && temp->next!=NULL){
            if(head->val == value){
                del=head;
                head=head->next;
                temp=head;
                delete del;
                continue;
            }
            if(temp->val == value){
                prev->next=temp->next;
                delete temp;
                temp=prev->next;
            }else{
                prev=temp;
                temp=temp->next;
            }
        }
        if(temp->val == value && (head==NULL || head->next==NULL)){
            return NULL;
        }else if(temp->val == value){
            prev->next=NULL;
        }
        return head;
    }
};
