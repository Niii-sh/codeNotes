#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e4+10;
const int M = 2*N;
const int INF = 0x3f3f3f3f;

int h[N],e[M],ne[M],w[M],idx;   //表头 节点 next值 权值
int d1[N],d2[N];    //向下的最大值 向下的次大值
int up[N];      //向上走的最大值
int p1[N];    //最大值的转移点 
bool is_leaf[N];    //判断是否叶子节点


//加边 
void add(int a,int b,int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

//向下寻找 寻找向下走的最大值
//用父节点更新子节点 
int dfs_d(int u,int father){
    d1[u] = d2[u] = -INF;
    
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(j==father)
            continue;
        int d = dfs_d(j,u) + w[i];
        
        if(d>=d1[u]){
            p1[u] = j;
            d2[u] = d1[u];
            d1[u] = d;
        }
        else if(d>d2[u]){
            d2[u] = d;
        }
      
    }
    
    //该节点从来没有更新过
    //即该节点 叶子节点 无向下的距离 即距离为0
    if(d1[u]==-INF){
        d1[u] = d2[u] = 0;
        is_leaf[u] = true;
    }
    
    return d1[u];
    
}

void dfs_u(int u,int father){
    
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(j==father)
            continue;
        //向上走过该点 返回次大值
        if(p1[u] == j){
            up[j] = max(up[u],d2[u]) + w[i];
        }
        else
            up[j] = max(up[u],d1[u]) + w[i];
        
        dfs_u(j,u);
    }
}


int main(){
    int n;
    cin>>n;
    
    memset(h,-1,sizeof h);
    
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    
    dfs_d(1,-1);
    
    dfs_u(1,-1);
    
    
    int res=d1[1];
    
    for(int i=2;i<=n;i++){
        if(is_leaf[i]){
            res = min(res,up[i]);
        }
        else
            res = min(res,max(d1[i],up[i]));
    }
    
    printf("%d",res);
    
    return 0;
}