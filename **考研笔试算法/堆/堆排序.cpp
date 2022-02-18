/*
原题 Acwing 838
堆排序实际包括两个步骤
1.建堆
    a.堆的插入
        b.堆的调整
2.排序
    排序是每次弹出堆顶元素 加入以排序的序列
    然后末端元素移到堆顶
    进行调整
*/

//根据题意输出 前m小的元素 故本题的堆为小根堆
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1E5+10;
const int M = 2*N+10;

int h[M];   //存储堆的元素

void heapAdujust(int u,int len){
    int t=u;
    //左子树存在 且该结点小于左子树 则进行调整即交换
    if(u*2<=len&&h[t]>h[u*2])
        t=2*u;
    //右子树存在 且该结点小于右子树 则进行调整即交换
    if(u*2+1<=len&&h[t]>h[u*2+1])
        t=2*u+1;
    
    //即如果发生了交换
    //那么按照堆 自上向下进行调整的定义 
    //需要递归的以该结点为根再进行调整
    if(u!=t){
        swap(h[u],h[t]);
        heapAdujust(t,len);
    }
}

void bulidHeap(int len){
    //从后往前调整所有非终端结点(所以要len/2)
    for(int i=len/2;i;i--){
        heapAdujust(i,len);
    }
}


int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    
    bulidHeap(n);
    
    //heapSort环节
    //要输出前m个
    //每次输出已经排好序的堆顶元素
    //然后将最后一个元素移至堆顶 然后重新进行调整 即建堆
    
    int len = n;
        
    while(m--){
        printf("%d ",h[1]);
        h[1]=h[len];
        heapAdujust(1,len);
        len--;
    }
    
    return 0;
}
