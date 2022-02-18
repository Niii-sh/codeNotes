/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    原题LC剑指offer 022
    基本与我想的差不多
    都是两个思路
    只不过哈希还不如 我之前想的染色来的便捷 不过这题规定了不能修改结点那也就只能是哈希了
    然后是这个快慢指针 还听巧妙的可以写一下 挺好的一个思路
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow = head;
        ListNode*fast = head;
        
        while(fast){
            slow = slow->next;
            fast=fast->next;
            if(!fast)
                return nullptr;
            fast=fast->next;
            
            if(fast==slow){
                ListNode* ptr=head;
                //最终将在入环处相遇
                while(ptr!=slow){
                    ptr=ptr->next;
                    slow=slow->next;
                }
                return ptr;
            }
        }

        return nullptr;
    }
};