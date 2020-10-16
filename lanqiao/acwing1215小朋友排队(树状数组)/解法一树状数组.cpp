/*
树状数组算是目前为止学到最简单的高级数据结构了
也可以很好来解决我不擅长的以往要用归并排序来解决的求逆序对的问题
这次二刷也想明白了之前一直想不清楚的一个点
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 1e6+10;

int tr[N],h[N];
int sum[N];
int n;

int lowbit(int x){
	return x&-x;
}

void add(int x,int v){
	for(int i=x;i<=N-1;i+=lowbit(i)){
		tr[i]+=v;
	}
}

int query(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i)){
		res+=tr[i];
	}

	return res;
}

int main(){
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
    
    //关于add(h[i],1)
    //整个题目除了逆序思路推导外 代码部分最难理解的一个点
    //由于我们的树状数组存的是某一个高度位置上人的数量
    //但由于我们要求的是逆序
    //所以不能在输入小朋友身高之后统一把树建好 这样就和前缀和的思路没有任何区别了
    //这样的话也只能用O(n2)的方法二重循环求出逆序 也就失去了使用树状数组动态性的意义
    //所以我们采取的是动态插入的方式
    //以加入树状数组的顺序代表小朋友真正的排队次序 依次来求出逆序
	for(int i=1;i<=n;i++){
		sum[i]+=query(N-1) - query(h[i]);
		add(h[i],1);
	}

	memset(tr,0,sizeof tr);

	for(int i=n;i>=1;i--){
		sum[i]+=query(h[i]-1);
		add(h[i],1);
	}

	LL res=0;

	for(int i=1;i<=n;i++)
		res+=(LL)sum[i]*(sum[i]+1)>>1;

    cout<<res;

	return 0;
}
