/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] reversePrint(ListNode head) {
        Stack<Integer>stk = new Stack<>();
        ListNode tmp = head;
        while(tmp!=null){
            stk.push(tmp.val);
            tmp = tmp.next;
        }

        int[] res = new int[stk.size()];

        for(int i=0;i<res.length;i++){
            res[i] = stk.peek();
            stk.pop();
        }

        return res;
    }
}