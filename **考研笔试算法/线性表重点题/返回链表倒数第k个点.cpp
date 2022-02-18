/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    原题LC 剑指offer 22
    基本思路:
    双指针 也是一道很简单的题 可以和 LC.876联系起来看
    快慢指针 
    例如:倒数第一个 即快指针到了 但慢指针刚好在倒数第一个即可 
        即快指针先多走1个 然后慢指针出发
        那么 倒数第k个 即快指针先多走k个 然后在慢指针出发
        快指针到了 慢指针即为相应的倒数第k个
*/

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p = head; //p为快指针
        int cnt = k;
        while(cnt--)
            p=p->next;
        
        ListNode*q = head; //q为慢指针

        while(p){
            p=p->next;
            q=q->next;
        }

        return q;
    }
};