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


/*
    简化版 
    按照我自己的理解写了一下似乎就满简单的 不知道为什么网上的代码要搞得这么复杂
    堆的基本操作 插入与删除
    关键是了解 其基本步骤
    然后就是考验代码能力了 此处以大根堆为例
    插入: 先将元素加在最后最后一个位置然后自下而上进行调整
    删除: 将堆元素用最后一个元素取代 自上而下进行调整
*/
#include<iostream>
#include<algorithm>

using namespace std;

const int N=1E5+10;

int heap[N];    //为了方便操作 堆初始下标为1
int n;  //表示heap的当前长度

void insert(int heap[],int&n,int item){
    n++;
    heap[n]=item;
    for(int i=n;i/2>=1;i--){    
        int u=i/2;
        if(heap[i]>heap[u]){
            swap(heap[i],heap[u]);
        }
    }
}

void dele(int heap[],int&n){
    heap[1]=heap[n];
    n--;
    for(int i=1;i<=n;i++){
        int u=i;
        if(i*2<=n&&heap[i*2]>heap[i])
            u=i*2;
        if(i*2+1<=n&&heap[i*2]>heap[u])
            u=i*2+1;
        swap(heap[u],heap[i]);
    }
    
}

void traverse(int heap[],int n){
    for(int i=1;i<=n;i++)
        printf("%d ",heap[i]);
    puts("");
}

int main(){
    int x=5;
    
    for(int i=0;i<x;i++){
        int num;
        cin>>num;
        insert(heap,n,num);
        puts("插入后的结果为:");
        traverse(heap,n);
    }
    
    for(int i=0;i<2;i++){
        dele(heap,n);
        puts("删除后的结果为:");
        traverse(heap,n);
    }   
    
    return 0;
}