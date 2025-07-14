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
        ListNode* last=reverseLL(head->next);
        head->next->next=head;
        head->next=NULL;
        return last;
    }
    int getDecimalValue(ListNode* head) {
       head=reverseLL(head);
       int r=0;
       int power=0;
       while(head){
        r+=pow(2,power)*head->val;
        head=head->next;
        power++;

       }
       return r;
    }
};