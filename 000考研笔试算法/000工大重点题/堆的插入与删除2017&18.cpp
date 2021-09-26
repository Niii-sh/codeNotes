/*
    堆的插入:
    基本思路将元素插入堆的末端:
        堆的大小要加1
        然后下而上对堆进行调整
    堆的删除
    基本思路:
        将堆末端元素赋值给堆顶
        然后自上而下对堆进行调整
    以大根堆为例
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1E5+10;
int heap[N];

void siftUp(int nodeIndex){
    bool flag=false;    //用来标记是否需要上调
    if(nodeIndex==1)    //已经调制堆顶则不需要继续上调
        return;
    
    while(!flag&&nodeIndex>1){
        int parentIndex = nodeIndex/2;
        if(heap[nodeIndex]>heap[parentIndex]){
            swap(heap[nodeIndex],heap[parentIndex]);
            nodeIndex/=2;
        }
        else
            flag=1; //该结点小于其父结点符合堆的定义不需要继续上调
    }
    
}

void siftDown(int heapSize){
    int i=1;    //从1开始调整
    int tmp=0;          //parent结点应该与左右两个孩子中更大的孩子进行交换
    int len = heapSize-1;
    while(i*2<=len){
        tmp = i;
        if(heap[i]>heap[i*2])
            tmp = i*2;
        if(i*2+1<=len)
            if(heap[i*2+1]>heap[i*2])
                tmp= i*2+1;
        if(tmp!=i)
            swap(heap[i],heap[tmp]);
        i++;
    }
    
}

void insertion(int &heapSize,int data){
    heapSize++;
    heap[heapSize-1]=data;
    siftUp(heapSize-1);
}

void deletion(int &heapSize){
    heap[1]=heap[heapSize-1];
    heapSize--;
    siftDown(heapSize);
}

void showHeap(int heapSize){
    for(int i=1;i<=heapSize-1;i++)
        cout<<heap[i]<<' ';
    cout<<endl;
}


int main(){
    int heapSize=1;    //表示堆的初始大小
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        insertion(heapSize,v);
    }
    
    showHeap(heapSize);
    deletion(heapSize);
    showHeap(heapSize);
    insertion(heapSize,99);
    showHeap(heapSize);
    deletion(heapSize);
    showHeap(heapSize);
    
    
    return 0;
}