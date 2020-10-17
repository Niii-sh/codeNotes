/*
数组一定要开的够大很玄学
但树状数组用起来是真的很舒服
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 1e7+10;

typedef long long LL;

int tr[N*4];
int w[N];
int n;

int lowbit(int x){
	return x&-x;
}

void add(int x,int v){
	for(int i=x;i<=N;i+=lowbit(i))
		tr[i]+=v;
}

int query(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		res+=tr[i];
	return res;
}

int main(){
	scanf("%d",&n);
	
	LL sum=0;

	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		sum+=query(N)-query(w[i]);
		add(w[i],1);
	}

	printf("%lld",sum);

	return 0;
}