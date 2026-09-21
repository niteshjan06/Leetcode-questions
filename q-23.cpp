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

class Compare{
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> min_heap;

        for(ListNode* head:lists){
            if(head!=NULL){
                min_heap.push(head);
            }
        }

         ListNode* dummyNode = new ListNode(-1);
         ListNode* temp=dummyNode;

        while(!min_heap.empty()){
            temp->next=min_heap.top();
            min_heap.pop();
            temp=temp->next;
            if(temp->next!=NULL){
                min_heap.push(temp->next);
            }
        }
        return dummyNode->next;
    }
};
