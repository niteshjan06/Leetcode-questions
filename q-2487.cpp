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

        while(curr->next!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            nxt=nxt->next;
        }
        curr->next=prev;
        return curr;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* newHead = reverseLL(head);
        ListNode* temp=newHead;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* dum=dummyNode;

        stack<int> st;
        while(temp!=NULL){
            if(st.empty()){
                st.push(temp->val);
                dum->next=temp;
                dum=dum->next;
            }
            else if(st.top()<=temp->val){
                dum->next=temp;
                dum=dum->next;
                st.pop();
                st.push(temp->val);
            }
            temp=temp->next;
        }
        dum->next=NULL;
        return reverseLL(dummyNode->next);
    }
};
