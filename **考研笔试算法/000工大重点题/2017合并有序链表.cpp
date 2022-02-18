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

/*
    原题LC21
    把两个链表合并到一个链表里面
    最稳妥的写法
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*dummy = new ListNode(0,nullptr);
        ListNode*p = l1;
        ListNode*q = l2;
        ListNode*h = dummy;
        
        while(p&&q){
            if(p->val<q->val){
                h->next = p;
                p=p->next;
                h=h->next;
            }
            else{
                h->next = q;
                q=q->next;
                h=h->next;
            }

        }

        if(p)
            h->next = p;

        if(q)
            h->next=q;    

        return dummy->next;
    }
};