/*
    基数排序
    基本思路:
    1.初始化 设置r个空队列 Qr-1,Qr-2...Q0(10进制数就是10个0-9)
        按照各个关键字位权重递增的次序 等于d个关键字分别做分配和收集
    2.分配：
        顺序扫描每个元素 若当前处理的关键字位=x 则将x插入队尾
    收集: 把Qr-1 Qr-2...Q0 各个队列中的结点一次出队
    
    获得递减序列 则 从高到底
        递增序列 则 从低到高
*/

/*
    简化计算默认对10进制 这里对10进制数进行基数排序
    即r=10
*/

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

vector<int>q;   //表示待排序数组

void show(vector<int>&q){
    for(int i=0;i<q.size();i++)
        printf("%d ",q[i]);
    printf("\n");
}

//按递增排序
//r表示数制 w表示有多少位 
void radixSort(vector<int>&q,int w){
    queue<int>b[10];
    int n = q.size();
    int k=1;
    for(int i=0;i<w;i++){
        //进行收集
        for(int j=0;j<n;j++){
            b[q[j]/k%10].push(q[j]);
        }
        //进行分配
        int index = 0;
        for(int j=0;j<10;j++){
            while(b[j].empty()==false){
                q[index++]=b[j].front();
                b[j].pop();
            }
        }
        
        k*=10;
        //展现每趟分配的结果可忽略
        show(q);
    }
}

int main(){
    int n=10;

    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        q.push_back(v);
    }
    
        
    radixSort(q,3);
    
    return 0;
}
