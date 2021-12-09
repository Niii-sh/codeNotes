/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    基本思路:
    1.迭代原地逆置
    2.先遍历一遍 然后复制完相应元素 然后反向建立 (这里用个栈可能会更舒服一些)
*/

//思路一迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //表空 或只有一个结点则直接返回
        if(!head||!head->next)
            return head;
        ListNode*pre=NULL,*cur=head;
        ListNode* p = cur->next;
        while(cur){
            p = cur->next;
            cur->next=pre;
            pre = cur;
            cur = p ;
        }

        return pre;
    }
};

//思路二 结合栈 先复制后 再新建
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int>stk;
        ListNode*p = head;
        while(p){
            stk.push(p->val);
            p=p->next;
        }   

        ListNode* dummy = new ListNode;
        ListNode*cur = dummy;
        
        while(!stk.empty()){
            int data = stk.top();
            stk.pop();
            ListNode*s = new ListNode(data);
            cur->next = s;
            cur=cur->next;
        }

        return dummy->next;
    }
};