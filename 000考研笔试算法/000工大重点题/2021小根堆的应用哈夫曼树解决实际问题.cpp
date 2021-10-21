/*
    工大这题 和acwing149合并果子本质一毛一样
    就是哈夫曼树的应用就是会写最小的stl即可
    priority_queue<int,vector<int>,greater<int>>    为小根堆
    C++ 默认的priority_queue为大根堆
    或者大根堆存负数 当然这是在题目规定所有数的符号均相同的情况下
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;

const int N = 1E4+10;

int main(){
    priority_queue<int,vector<int>,greater<int>>minHeap;
    
    int n;
    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        minHeap.push(x);
    }
    
    int ans=0;
    
    while(minHeap.size()>1){
        int a = minHeap.top();
        minHeap.pop();
        int b = minHeap.top();
        minHeap.pop();
        ans+=a+b;
        minHeap.push(a+b);
    }
    
    cout<<ans;
    
    return 0;
}
