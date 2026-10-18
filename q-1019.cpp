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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        ListNode* temp=head;
        while(temp!=NULL){
            values.push_back(temp->val);
            temp=temp->next;
        }

        stack<int> st;
        vector<int> ans(values.size());

        for(int i=0;i<values.size();i++){
            while(!st.empty() && values[i]>values[st.top()]){
                ans[st.top()]=values[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
