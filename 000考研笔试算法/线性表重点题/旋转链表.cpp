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
    原题LC 61 旋转结点
    思路加入一个哑巴结点 主要是方便表头的插入
    然后先遍历依次统计一下长度
    对于k取个模 防止重复移动 提高效率

    主要是边界比较恶心 卡了好几次 不过基本思路标答是完全一致的
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next||!k)
            return head;
        ListNode*last = head;
        int n=0;    //用于标记链表的长度

        //找到尾结点的位置 顺便记录下链表的长度
        while(last->next){
           n++;
           last=last->next;
        }

        n++;
        int m = k%n;    //真正需要移动的次数

        if(!m)
            return head;

        ListNode* dummy = new ListNode;
        dummy->next = head;

        ListNode *p = head;

        //先把last指向第一个元素
        //然后再让dummy->next指向n-m这个元素(p)的位置即可

        //找到第n-m个元素的位置
        for(int i=0;i<n-m;i++)
            p=p->next;
        
        last->next=dummy->next;
        dummy->next=p;

        for(int i=0;i<n-1;i++)
            p=p->next;
        
        p->next=nullptr;

        return dummy->next;
    }
};