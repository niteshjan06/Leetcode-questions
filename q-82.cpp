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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* del=NULL;
        int duplicate=101;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->val == temp->next->val){
                duplicate=temp->val;
            }

            if(temp->val==duplicate){
                del=temp;
                if(prev){
                    prev->next=temp->next;
                    temp=temp->next;
                }else{
                    temp=temp->next;
                    head=head->next;
                }
                delete del;
                continue;
            }

            prev=temp;
            temp=temp->next;
        }

        if(temp->val==duplicate){
                del=temp;
                if(prev){
                    prev->next=temp->next;
                    temp=temp->next;
                }else{
                    temp=temp->next;
                    head=head->next;
                }
                delete del;
            }
        return head;
    }
};
