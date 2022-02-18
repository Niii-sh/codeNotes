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



/*
    2021 11 18
    考前练习版 
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int N=1e5+10;

void show(vector<int>q){
    for(int i=0;i<q.size();i++)
        printf("%d ",q[i]);
    puts("");
}

//q为需要进行基数排序的数组
//w表示位数 方便起见 不然要全部算一次 用于决定基数排序的趟数
void radixSort(vector<int>&q,int w){
    
    //开始进行基数排序
    int k=1; //用于每次取出各个位置的数
    //开始基数排序的分配和收集动作
    for(int i=0;i<w;i++){
        queue<int>b[10];    //默认为10进制数 故需要收集0-9
        for(int j=0;j<q.size();j++){
            b[q[j]/k%10].push(q[j]);
        }
        vector<int>tmp;
        for(int j=0;j<q.size();j++){
            while(!b[j].empty()){
                tmp.push_back(b[j].front());
                cout<<b[j].front()<<endl;
                b[j].pop();
            }
        }
        
        q=tmp;
        k*=10;
        show(q);
    }
    
}

int main(){
    
    vector<int>q;
    
    for(int i=0;i<5;i++){
        int x;
        cin>>x;
        q.push_back(x);
    }
    
    radixSort(q,3);
    
    return 0;
}
