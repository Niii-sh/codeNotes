/*
原题LC 剑指offer09
基本思路:
两个栈 st1用于入队 st2用于出队
由于队列是先进后出  栈是先进先出
所以每次需要出队时 就先判断st2是否为空 非空则直接从st2 pop
否则将st1中的元素全部入栈的st2  经过这一操作后st1中最先入栈的被排到了st2的栈底将要最后出栈 既符合队列这一特性
然后从st2 pop即可
*/
class CQueue {
stack<int>st1,st2;
public:
    CQueue() {
        while(!st1.empty())
            st1.pop();
        while(!st2.empty())
            st2.pop();
    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }

        if(st2.empty())
            return -1;
        else{
            int t = st2.top();
            st2.pop();
            return t;
        }
            
        return -1;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */