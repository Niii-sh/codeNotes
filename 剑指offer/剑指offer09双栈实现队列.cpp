/*
    双栈思路一个用于:
    一个栈用于插入 另一个用于删除
*/

class CQueue {
    stack<int>stk1,stk2;
public:
    CQueue() {
        // 数据初始化 清空栈 
        while(!stk1.empty())
            stk1.pop();
        while(!stk2.empty())
            stk2.pop();
    }
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        int deletElem;
        if(stk2.empty()){
            while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        if(stk1.empty()&&stk2.empty())
            deletElem = -1;
        else{
            deletElem = stk2.top();
            stk2.pop();
        }
           
        return deletElem;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */