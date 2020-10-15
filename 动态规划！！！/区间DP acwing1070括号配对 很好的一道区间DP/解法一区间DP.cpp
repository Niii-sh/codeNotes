#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 110;

int dp[N][N];
string s;

bool check(char l,char r){
	if(l=='(' && r==')')
		return true;

	if(l=='[' && r==']')
		return true;

	return false;
}

int main(){
	cin>>s;

	int n = s.size();

	for(int len=1;len<=n;len++)
		for(int l=0;l+len-1<n;l++){
			int r = l+len-1;
			dp[l][r] = 1e9;
			if(check(s[l],s[r]))
				dp[l][r] = dp[l+1][r-1];
			dp[l][r] = min(min(dp[l+1][r],dp[l][r-1])+1,dp[l][r]);
		
			for(int k=l;k<r;k++)
					dp[l][r] = min(dp[l][r],dp[l][k]+dp[k+1][r]);
		}

	printf("%d\n",dp[0][n-1]);

	return 0;
}