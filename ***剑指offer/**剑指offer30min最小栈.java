/**
    维护一个辅助stk2
    每次主栈入栈时 和辅助栈栈顶元素比较 如果比其小则入栈
    每次主栈出栈时 与栈顶元素比较 如果相等则一起出栈
 */
class MinStack {
    private Stack<Integer> stk1 = new Stack<Integer>();
    private Stack<Integer> stk2 = new Stack<Integer>(); 

    /** initialize your data structure here. */
    public MinStack() {
        stk1.clear();
        stk2.clear();
    }
    
    public void push(int x) {
        stk1.add(x);
        
        if(stk2.empty() || x<=stk2.peek())
            stk2.push(x);
    }
    
    public void pop() {
        int x = stk1.pop();
        if(x==stk2.peek()){
            stk2.pop();
        }
    }
    
    public int top() {
        return stk1.peek();
    }
    
    public int min() {
        return stk2.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.min();
 */