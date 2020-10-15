/*
总结还是很重要的
做了那么多类似的 才发现这是属于区间DP
这样的话 方法也就清晰很多了
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1010;

string s;
int dp[N][N];
int n;

int main(){
	cin>>s;
	n = s.size();

	for(int len=1;len<=n;len++){
		for(int l=0;l+len-1<n;l++){
			int r = l+len-1;
			if(len == 1)
				dp[l][r] = 1;
			else{
				if(s[l]==s[r])
					dp[l][r] = max(dp[l][r],dp[l+1][r-1]+2);
				dp[l][r] = max(max(dp[l+1][r],dp[l][r-1]),dp[l][r]);
			}
		}
	}

	printf("%d\n",n-dp[0][n-1]);

	return 0;
}