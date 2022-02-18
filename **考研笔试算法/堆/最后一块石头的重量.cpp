/*
    原题LC 1046
    这题就是满满的哈夫曼树的感觉 即最大堆的应用问题
    这题可以说是模拟题了吧 就是运用了堆的性质
    完全有可能考 就是不知道到时候在考场上能不能反应过来
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>heap;
        for(auto&val:stones){
            heap.push(val);
        }

        while(heap.size()>1){
            int y=heap.top();
            heap.pop();
            int x=heap.top();
            heap.pop();
            if(y==x)
                continue;
            else
                heap.push(y-x);
        }

        if(heap.size()==0)
            return 0;
        else
            return heap.top();
        
    }
};