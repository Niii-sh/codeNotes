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
    堆排序:
    迭代模拟版
    以小根堆为例
    非常慢 但好在比较好理解吧 完全是模拟堆排序手算思路写的
    重点在于关于swap的过程 这里很容易弄错
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

const int N=1E5+10;
int heap[N];    //堆 序号从1开始
int len;    //堆当前的长度

void traverse(int heap[],int len){
    for(int i=1;i<=len;i++)
        printf("%d ",heap[i]);
    cout<<endl;
}

//堆的插入 自底向上进行调整
//注意调整需要对非终端结点进行调整 由非终端结点与其两个孩子相比较
void heapPush(int heap[],int&len,int item){
    heap[++len]=item;
    for(int i=len/2;i>=1;i--){
        int u = i;
        if(i*2<=len&&heap[u]>heap[i*2]){
            u=2*i;
        }
        if(i*2+1<=len&&heap[u]>heap[i*2+1]){
            u=2*i+1;
        }
        if(u!=i)
            swap(heap[u],heap[i]);
    
     
    }
}

//堆的删除
//将堆顶元素的值由最后一个元素替代
//然后自顶向下调整
void heapPop(int heap[],int&len){
    heap[1]=heap[len--];
    for(int i=1;i*2<=len;i++){
        int u = i;
        if(i*2<=len&&heap[u]>heap[i*2]){
            u=2*i;
        }
        if(i*2+1<=len&&heap[u]>heap[i*2+1]){
            u=2*i+1;
        }
        if(u!=i)
            swap(heap[u],heap[i]);

     
    }
}

//完整来说 先将原数组建队
//然后每次出堆堆顶元素
//本题比较特殊需要传入弹出前n元素 所以传入一个m
void heapSort(int heap[],int&len,vector<int> q,int m){
    for(int i=0;i<q.size();i++){
        heapPush(heap,len,q[i]);
    }
    
    for(int i=0;i<m;i++){
        printf("%d ",heap[1]);
        heapPop(heap,len);
    }
}

int main(){
    vector<int>q;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        q.push_back(x);
    }
    
    heapSort(heap,len,q,m);
    
    return 0;
}