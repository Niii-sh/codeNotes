/*
基本上是秒A了
注意数据有些大
以后做题最好先判断一下吧 稍微感觉有些大就用long long好了
*/

#include<iostream>
#include<algorithm>
using namespace std;

typedef long LL;

LL dp[3010];
int v[20];
int n,m;
int main(){
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		cin>>v[i];
	
	dp[0] = 1;
	
	for(int i=0;i<n;i++){
		for(int j=v[i];j<=m;j++)
			dp[j]+= dp[j-v[i]] ;
	}
	
	cout<<dp[m]<<endl;
	
	return 0;
}