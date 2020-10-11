#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e5+10;
const int M = 2*N;
int h[N],e[M],ne[M],w[M],idx;
int dist[N];
int n;

void add(int a,int b,int c){
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

int dfs(int u,int father,int distance){
	dist[u] = distance;
	for(int i=h[u] ; i!=-1;i=ne[i]){
		int j = e[i];
		if(j==father)
			continue;
		dfs(j,u,distance+w[i]);
	}
}

int main(){
	cin>>n;
	
	memset(h,-1,sizeof h);
	
	for(int i=0;i<n-1;i++){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	
	dfs(1,-1,0);
	
	int u=1;
	
	for(int i=1;i<=n;i++){
		if(dist[i]>dist[u])
			u=i;
	}
	
	dfs(u,-1,0);
	
	for(int i=1;i<=n;i++){
		if(dist[i]>dist[u])
			u=i;	
	}
	
	int  s = dist[u];
	
	printf("%lld\n",s*10+s*(s+1ll)/2);
	
	return 0;
}