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
    原题 LC：876
    做链表题 最好画个图思路简单 但细节很容易出错 
    基本思路: 双指针 快慢指针
    快指针p每步走2 慢指针q每步走1
    1.偶数个节点时 
        p到了 则返回q->next(因为题目要返回中间结点第二个节点)
    2.奇数个节点时
        p到了 返回q即可
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode* p = head;
        ListNode* q = head;

        while(p){
            p=p->next;
            if(!p){ //奇数点的情况 直接返回q
                return q;
            }
            q=q->next;
            p=p->next;
        }

        return q;
    }
};