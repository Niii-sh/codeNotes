/*
01背包问题的一种扩展
可能是因为我写的题还是太少了..
这种比较直接的转换居然还是没想到
这题与01背包问题的最大区别就是
这里少了一个value的概念
但我们可以将物体的体积看作value
最后输出V-value 就是答案 

另外这种简单题 以后就直接用一维优化版去做好了
其实真的不难理解的 
*/

#include<iostream>
#include<algorithm>
using namespace std;

int dp[20010];

int v;

int n,m;	//n代表物品数 m代表体积 

int main(){
	cin>>m>>n;
	
	for(int i=1;i<=n;i++){
	    int v;
	    cin>>v;
	    for(int j=m;j>=v;j--)
	        dp[j] = max(dp[j],dp[j-v]+v);
	}
	
	cout<<m-dp[m]<<endl;
	
	return 0;
}