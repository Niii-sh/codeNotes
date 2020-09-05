/*
此题有多种解法
第1种为递归搜索 (不是一种好的解法 但对理解递归 练习递归枚举很有好处)
第2种为DP
*/

//解法1递归搜索
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=20+10;

int q[N][N];
int s[4];
int ans;
int l,r;

void dfs(int u,int i,int &cost){
    if(u>s[i]){
        cost = min(cost,max(l,r));
        return;
    }

    l+=q[i][u];
    dfs(u+1,i,cost);
    l-=q[i][u];

    r+=q[i][u];
    dfs(u+1,i,cost);
    r-=q[i][u];
}

int main(){

    for(int i=0;i<4;i++)
        cin>>s[i];
    
    for(int i=0;i<4;i++)
        for(int j=0;j<s[i];j++)
            cin>>q[i][j];
    
    for(int i=0;i<4;i++){
        int cost=1e9;
        l=r=0;
        dfs(0,i,cost);
        ans+=cost;
    }
    
    cout<<ans<<endl;

    return 0;
}