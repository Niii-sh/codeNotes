/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*
    原题LC:剑指18
    基础训练题 唯一就是考虑头节点的情况 可以直接设置哑结点 也可以选择将情况分出来单独讨论
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode*dummy = new ListNode;
        //用于便于解决删除头节点的情况
        dummy->next=head;
        ListNode*curr=head;
        ListNode*prev = dummy;
        while(curr){
            if(curr->val==val){
                prev->next=prev->next->next;
                break;
            }
            curr=curr->next;
            prev=prev->next;
        }


        return dummy->next;
    }
};