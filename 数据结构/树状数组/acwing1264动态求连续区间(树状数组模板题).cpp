#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1e5+10;

int n,m;

int a[N],tr[N];

//返回2^x次方
int lowbit(int x){
	return x&-x;
}

//在x位置加上v
void add(int x,int v){
	for(int i=x;i<=n;i+=lowbit(i))
		tr[i]+=v;
}

int query(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		res+=tr[i];
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);

	//建树 每个位置加上相应的数
	//即将树状数组建立
	for(int i=1;i<=n;i++)
		add(i,a[i]);

	while(m--){
		int k,x,y;
		scanf("%d%d%d",&k,&x,&y);
		if(k==0)
			printf("%d\n",query(y)-query(x-1));
		else
			add(x,y);
	}

	return 0;
}