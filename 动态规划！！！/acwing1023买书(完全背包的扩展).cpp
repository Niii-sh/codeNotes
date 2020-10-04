/*
n元视为容量 
书的价格视为每一种物品的体积 
状态初始化 dp[0] = 1;
这是一本书都不选的 恰好花费为0 的方案数就为1
*/

#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;
int n;
int dp[N];

int main(){
	cin>>n;
	int v[4] = {10,20,50,100};
	
	dp[0] = 1; 
	
	for(int i=0;i<4;i++){
		for(int j=v[i];j<=n;j++)
			dp[j]+= dp[j-v[i]] ;
	}
	
	cout<<dp[n]<<endl;
	
	return 0;
}