/*
其实难度还行不是很难
但是第二遍做的时候不能秒A 还是有些不应该
递归这块感觉还是不行
*/
/*
递归思路:
    主要还是要明确搜索的顺序 
    并且注意由于这题指数型枚举
    每一个数可以选或不选 也可以不用
    而不用!=不选
    故需要定义3个状态 0 1 2
    0代表不用 1代表选 2代表不选
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 20;
int st[N];
int n;
void dfs(int u){
    if(u>n){
        for(int i=1;i<=n;i++)
            if(st[i]==1)
                printf("%d ",i);
        printf("\n");
        return;
    }
    
    st[u] = 1;      //状态 选
    dfs(u+1);       //恢复现场
    st[u] = 0;
    
    st[u] = 2;
    dfs(u+1);
    st[u] = 0;
    
}

int main(){
    scanf("%d",&n);
    dfs(1);
    
    return 0;
}