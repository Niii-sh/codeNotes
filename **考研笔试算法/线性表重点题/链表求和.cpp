/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    不难 但边界情况真的有很多需要考虑进去
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;

        ListNode *dummy= new ListNode ;
        ListNode* curr=dummy;

        int c=0;//表示余数

        while(p&&q){
            int temp = p->val+q->val+c;
            curr->next = new ListNode(temp%10);
            c=temp/10;
            curr=curr->next;
            p=p->next;
            q=q->next;
        }

        while(p){
            int temp = p->val+c;
            curr->next=new ListNode(temp%10);
            c=temp/10;
            curr=curr->next;
            p=p->next;
        }
            
        while(q){
            int temp = q->val+c;
            curr->next= new ListNode(temp%10);
            c=temp/10;
            curr=curr->next;
            q=q->next;
        }

        if(c)
            curr->next = new ListNode(c);

        return dummy->next;
    }
};