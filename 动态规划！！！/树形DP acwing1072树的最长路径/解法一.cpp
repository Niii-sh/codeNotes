/*
除了树形DP知识内容外
链表的表示与存储都很值得学习
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 10010,M = N*2;

int n;
int h[N],e[M],ne[M],idx;    //链表的头节点 节点值 next值 idx值
int w[M];   //边权值
int ans;

//把b加到a上
void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int u,int father){
    int dist = 0;   //表示从当前点往下走的最大长度
    int d1=0,d2=0;  //表示最大值和次大值
    
    for(int i=h[u];i!=-1;i=ne[i]){
        int j = e[i];
        //防止向上搜索
        if(j==father)
            continue;
        
        int d = dfs(j,u) + w[i];
        dist = max(dist,d);
        
        //更新最大值
        if(d>=d1){
            d2=d1;
            d1=d;
        }
        //更新次大值
        else if(d>d2){
            d2=d;
        }
    }
    
    ans = max(ans,d1+d2);
    
    return dist;
    
}

int main(){
    cin>>n;
    
    //初始化链表头节点
    memset(h,-1,sizeof h);
    
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        //无向边所以加两次
        add(a,b,c);
        add(b,a,c);
    }
    
    dfs(1,-1);
    
    cout<<ans;
    
    return 0;
}



