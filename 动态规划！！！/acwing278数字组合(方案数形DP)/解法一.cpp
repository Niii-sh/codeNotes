/*
难点和易错点都在于初始化条件的定义
由于定义的状态是 恰好为体积j的方案数
那么初始化时 一个都不选 则只有对应体积为0时的方案数为 即dp[0]=1 其他状态数均应初始化为0
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 110;

int n,m;

int dp[10010];

int main(){
	
	cin>>n>>m;
	
	dp[0] = 1;
	for(int i=1;i<=n;i++){
		int v;
		cin>>v;
		for(int j=m;j>=v;j--){
			dp[j] = dp[j-v] + dp[j];
		}
	}
	
	cout<<dp[m]<<endl;
	
	return 0;
} 