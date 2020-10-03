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

int dp[30+10][20010];

int v[30+10];

int n,m;	//n代表物品数 m代表体积 

int main(){
	cin>>m>>n;
	
	for(int i=1;i<=n;i++)
		cin>>v[i];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j] = dp[i-1][j];
			if(j>=v[i])
				dp[i][j] = max(dp[i][j],dp[i-1][j-v[i]]+v[i]);
		}	
	}
	
	cout<<m-dp[n][m]<<endl;
	
	return 0;
}