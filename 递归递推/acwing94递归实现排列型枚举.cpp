/*
递归思路:
    事实上就是全排列问题
    由于所有数都要用上所以就只有两种状态 
    即 该位上这个数选 或 不选
        1代表选     0代表不选
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 10;

int n;
int a[N];
bool st[N];

void dfs(int u){
    if(u>n){
        for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
        return;
    }
    
    for(int i=1;i<=n;i++){
        if(!st[i]){
            st[i] = true;
            a[u] = i;
            dfs(u+1);
            st[i] = false;
        }
    }
}

int main(){
    scanf("%d",&n);
    dfs(1);
    return 0;
}