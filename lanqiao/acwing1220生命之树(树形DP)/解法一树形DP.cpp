/*
第一次自己写的时候 树形DP的形基本上已经写出来了
数组模拟单链表那里也基本上写的是对的
就是到具体的DP递归思路那里还有一些问题
不过这题思路还是比较简单的
主要还是被 那种求直径的树形DP影响太深了吧
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 1e5+10;
const int M = 2*N;

int h[N],e[M],ne[M],idx,w[N];
LL dp[N];
int n;

void add(int a,int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int dfs(int u,int father){
	dp[u] = w[u];
	for(int i=h[u];i!=-1;i=ne[i]){
		int j = e[i];
		if(j==father)	
			continue;
		dfs(j,u);
		dp[u]+= max(0ll,dp[j]);
	}
}

int main()
{
	scanf("%d",&n);
    
    memset(h,-1,sizeof h);
    
	for(int i=1;i<=n;i++)	
		scanf("%d",&w[i]);

	for(int i=0;i<n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}

	dfs(1,-1);

	LL res=dp[1];

	for(int i=2;i<=n;i++)
		res=max(res,dp[i]);

	printf("%lld",res);

	return 0;
}