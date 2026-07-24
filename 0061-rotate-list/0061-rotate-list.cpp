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
    ListNode* rotateRight(ListNode* head, int k) {
        if(! head || ! head->next||k ==0) return head;

        int len=1;
        ListNode* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
            len++;
        }
        k=k%len;
        if(k==0) return head;
        temp->next = head;
        int steps = len-k;
        ListNode* newtemp = head;
        for(int i=1;i<steps;i++){
            newtemp = newtemp->next;
        }
        ListNode* newHead = newtemp-> next;
        newtemp->next = NULL;
        return newHead ;
        
    }
};