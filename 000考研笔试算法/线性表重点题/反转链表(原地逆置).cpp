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
    原题LC 206
    基本思路:迭代  也可以理解为原地逆置吧
    时间复杂度O(n) 空间复杂度O(1)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*prev = nullptr;
        ListNode*cur = head;
        
        while(cur){
            ListNode*tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        return prev;
    }
};