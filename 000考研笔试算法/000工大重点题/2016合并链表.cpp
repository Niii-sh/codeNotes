/*
    和LC21 这道题是完全一样的
*/
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode;

        auto p = dummy;

        while(l1&&l2){
            auto s = new ListNode;
            if(l1->val<l2->val){
                s->val = l1->val;
                p->next=s;
                p=p->next;
                l1=l1->next;
            }
            else{
                s->val = l2->val;
                p->next=s;
                p=p->next;
                l2=l2->next;
            }
        }


        while(l1){
            auto s= new ListNode(l1->val);
            p->next=s;
            p=p->next;
            l1=l1->next;
        }

        while(l2){
            auto s= new ListNode(l2->val);
            p->next=s;
            p=p->next;
            l2=l2->next;
        }

        return dummy->next;
    }
};