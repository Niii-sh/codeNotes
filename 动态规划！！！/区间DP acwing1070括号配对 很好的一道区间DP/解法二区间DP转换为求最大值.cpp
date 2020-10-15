/*
两种方法都是很好的解法这种相对来说要更好理解一些
也是完全由我自己推导出来解法
主要是对DP的状态划分分为两种情况
1.[[] 2.[][]
向详情见分析的pdf就好了
但要特别注意的是在情况2 枚举区间的时候
由于我们的r本就是=i+len-1<n
即在推导的状态表示中本身就是一个确定的可以取到
所以在求dp[i][k]+dp[k+1][r] 时 k是可以取到r的
因为dp[r][r]也是一种状态 如果漏掉那么就会出错
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 110;

int dp[N][N];
string s;

bool check(char a,char b){
	if(a=='['&&b==']')
		return true;
	if(a=='('&&b==')')
		return true;
	return false;
}

int main(){
    cin>>s;
	int n = s.size();

	for(int len=1;len<=n;len++)
		for(int l=0;l+len-1<n;l++){
			int r = l+len-1;
			if(check(s[l],s[r]))
				dp[l][r] = max(dp[l][r],dp[l+1][r-1]+2);
			dp[l][r] = max(max(dp[l+1][r],dp[l][r-1]),dp[l][r]);
			for(int k=l;k<=r;k++)
				dp[l][r] = max(dp[l][r],dp[l][k]+dp[k+1][r]);    
			
		}

		printf("%d\n",n-dp[0][n-1]);

	return 0;
}