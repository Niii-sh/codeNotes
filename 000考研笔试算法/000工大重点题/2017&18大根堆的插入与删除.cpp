/*
    堆的插入:
    基本思路将元素插入堆的末端:
        堆的大小要加1
        然后下而上对堆进行调整
    堆的删除
    基本思路:
        将堆末端元素赋值给堆顶
        然后自上而下对堆进行调整
*/
/*
    本题以小根堆为例
    核心还是在down的这个过程中
    不过为了考试的看起来更规范 还是将该操作分离出来 写为heapAdjust
    然后使用在插入 和 删除过程中
    慢了一些 但是目前 是调整最为适合考试的版本
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1E5+10;

int heap[N]; // 堆

void traverse(int heap[],int len){
    for(int i=1;i<=len;i++)
        cout<<heap[i]<<' ';
    cout<<endl;
}

//现在看来还是这个递归的算法最为精彩
//u表示当前结点所在的位置 len表示堆的长度
void heapAdjust(int heap[],int u,int len){
    int t=u;
    //左子树存在 且值小于根
    if(u*2<=len&&heap[2*u]<heap[t])
        t=2*u;
    
    //右子树存在 且值大于根
    //用t是因为 根要满足比左右子树都小 所以是比较两次 
    //还是比较巧妙的这里面的设计 
    if(u*2+1<=len&&heap[2*u+1]<heap[t])
        t=2*u+1;
    
    //证明当前结点不符合 根的定义
    //故进行交换 同时下继续进行调整
    if(u!=t){
        swap(heap[u],heap[t]);
        heapAdjust(heap,t,len);
    }
    
}

//有了heapAdjust后其余两个操作就很好办了
void insert(int heap[],int &len,int data){
    len++;
    heap[len]=data;
    for(int i=len/2;i;i--)
        heapAdjust(heap,i,len);
    //traverse(heap,len);
}

void pop(int heap[],int &len){
    heap[1]=heap[len];
    heapAdjust(heap,1,len);//从顶点开始调整
    len--;
}

int main(){
    int n,m;
    cin>>n>>m;
    
    int len=0;
    
    memset(heap,0x3f,sizeof heap);//由于是小根堆 所以将堆初始化为最大
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(heap,len,x);
    }
    
    //排序
    
    for(int i=0;i<m;i++){
        cout<<heap[1]<<' ';
        pop(heap,len);
    }
    
    
    return 0;
}