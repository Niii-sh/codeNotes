/*
思路上倒也不是很难吧
但这篇作为三个枚举方法的起点 还是把一些把重要点罗列一下
枚举关键是要清楚枚举的顺序 这点非常重要
清楚枚举顺序之后然后再对代码做简单优化等价变形之后 即可将O(n3) o(n2) 优化为ologn

法一.双指针
首先要理解的分步乘法的概念
即可将求解的过程分为两步
遍历一遍 b数组
然后分别求出a中 小于bi 的个数
求出c中大于 bi 的个数
然后 ans+=a*c 
每步相加就可以

所以先加三个数组排序即可

注意点:
这里尤其是要注意sort方法的使用
如果数组是从1 开始的那么一定要从 1开始sort 即sort(q+1,q+1+n)

*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N =1e5+10;

typedef long long LL;

int a[N];
int b[N];
int c[N];

int n;

int main(){
	cin>>n;
	
	for(int i=1;i<=n;i++)	
		cin>>a[i];

	for(int i=1;i<=n;i++)	
		cin>>b[i];
	
	for(int i=1;i<=n;i++)	
		cin>>c[i];
				 
	
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	
	LL ans=0;
    
	for(int j=1,i=1,k=1;j<=n;j++){
	    while(a[i]<b[j] && i<=n){
	        i++;
	   }
	    
	    while(c[k]<=b[j] && k<=n){
	        k++;
	    }
	    
	   ans+= (LL)(i-1)*(n-k+1);
	}
	
	cout<<ans;
	
	return 0;
}