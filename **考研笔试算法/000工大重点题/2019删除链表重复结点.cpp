/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    原题LC 面试题02.01
    基本思路:使用set
        1.当表空 或者表中只有唯一元素则直接返回
        2.边遍历边将元素插入set中
        3.如果与set中的元素已存在 则p->next=p->next->next删除结点 否则则将结点加入set
    注意 set中判断结点是否存在用的是count 而非find find是返回迭代器 count是返回匹配数量 即1 即存在
*/

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(!head||!head->next)  //如果链表为空 或者链表只有一个元素则直接返回
            return head;
        set<int>myset;
        myset.insert(head->val);
        ListNode*p = head;
        while(p->next){
            int v=p->next->val;
            if(myset.count(v))
                p->next=p->next->next;
            else{
                myset.insert(v);
                p=p->next;
            }

        }

        return head;
    }
};