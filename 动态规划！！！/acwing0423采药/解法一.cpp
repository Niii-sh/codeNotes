/*
算是没有辜负自己的努力吧
基本上是秒A了 DP分析也完全是按照01背包的来 也就不传了
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int M = 110;
int T;
int m;
int t[M],v[M];

int dp[110][1010];

int main(){
	cin>>T>>m;
	
	for(int i=1;i<=m;i++)	
		cin>>t[i]>>v[i];
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=T;j++){
		    dp[i][j] = dp[i-1][j];
		    if(j>=t[i])
			    dp[i][j] = max(dp[i][j],dp[i-1][j-t[i]]+v[i]);
		}
	}
	
	cout<<dp[m][T]<<endl;
	
	return 0;
}