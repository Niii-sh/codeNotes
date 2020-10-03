/*
lc刷多了之后就习惯vector了... 
有些不简洁..
*/
#include<iostream>
#include<vector>
using namespace std;

int n,m;

int main(){
	cin>>n>>m;
	vector<char>a(n+1,0);
	vector<char>b(m+1,0);
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	for(int i=1;i<=m;i++)
		cin>>b[i];
			
	
	vector<vector<int>>dp(n+1,vector<int>(m+1));
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			dp[i][j] = max(dp[i][j],dp[i-1][j-1] + (int)(a[i]==b[j]));
		}
	
	cout<<dp[n][m]<<endl;
	
	return 0;
}