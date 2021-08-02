/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    原题LC 106
    基本思路:双指针+数学
    1.开始时pa pb分别指向 ha hb
    2.pa pb同时开始走 如果pa先走完 则将pa指向hb 然后再开始走 反之亦然
    3.若相交 则第二次即pa走B pb走时 两者走向重合点 否则两个链表没有交点

    下面给出证明:
    情况1: 两个链表不相交的情况
    记录 A的表长为m B的表长为B  
    A表不相交部分表长为a B表不相交部分表长为b 公共部分表长为c
    则有 a+c=m  b+c=n
    当a=b时 a,b 同时达到汇点 均走过了a=b的距离
    当a!=b时 当a走完A 走了a+c 而当a来到B 再次到达汇点时又走了c
    故a从出发到第二次达到汇点共走了 a+c+b
    对b同理有 b+c+a     
    故a!=b时 pa pb会在第二次同时到达汇点

    情况2:两个链表不相交时
    即c=0
    第二次时虽然都走了 a+b 但由于没有相交 即pa pb均指向了null 同时抵达了空
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*pa = headA;
        ListNode*pb =headB;

        while(pa!=pb){
            pa = pa==nullptr ? headB : pa->next;
            pb = pb==nullptr ? headA : pb->next; 
        }

        return pa;
    }
};