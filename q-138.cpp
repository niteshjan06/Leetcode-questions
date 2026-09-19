/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* extractLL(Node* head){
        Node* dummyNode=new Node(-1);
        Node* temp=dummyNode;
        Node* one=head;
        Node* curr=head->next;
        Node* two=curr->next;

        while(curr!=NULL){
            two=curr->next;
            temp->next=curr;
            temp=temp->next;

            curr=curr->next;
            if(curr) curr=curr->next;
            one->next=two;
            one=one->next; 
        }
        return dummyNode->next;
    }

    void pointRandom(Node* head){
        Node* curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }else{
                curr->next->random=NULL;
            }
            curr = curr->next->next;
        }
    }

    void doubleLL(Node* head){
        Node* curr=head;
        while(curr!=NULL){
            Node* nxt=curr->next;
            Node* newNode = new Node(curr->val);

            curr->next=newNode;
            newNode->next=nxt;
            curr=nxt;
        }
    }

    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        doubleLL(head);
        pointRandom(head);
        return extractLL(head);
    }
};
