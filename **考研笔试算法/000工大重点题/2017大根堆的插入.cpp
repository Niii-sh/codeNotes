/*
    工大2017堆中插入元素
    基本思路:
        就是用代码模拟堆的插入过程就完事了
        1.将元素加到当前当前堆的末端heap[heapSize-1] = value;
        2.heapSize++;
        3.向上调整 parentIndex=nodeIndex/2 
        由于是大根堆 
        if heap[parentIndex]<heap[nodeIndex]
        则swap
        然后直到nodeIndex<1为止 即调整到顶部(堆从1开始)
*/

#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+10;

int heapSize;   //由于是从1开始的 heapsize记得初始值设为1
int heap[N];

void siftUp(int nodeIndex){
    int parentIndex=nodeIndex/2;
    if(parentIndex<1)
        return;
    if(heap[parentIndex]<heap[nodeIndex])
        swap(heap[parentIndex],heap[nodeIndex]);
    siftUp(parentIndex);
}

void insert(int value){
    heapSize++;
    heap[heapSize-1]=value;
    siftUp(heapSize-1);
}




int main(){
    int n=6;
    heapSize=1;    
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        insert(v);
    }
    
    for(int i=1;i<=6;i++)
        cout<<heap[i]<<' ';
    
    return 0;
}

