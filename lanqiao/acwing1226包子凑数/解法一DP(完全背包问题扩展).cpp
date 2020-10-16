/*
虽然说是听了思路的
但是基本上全是自己写出来的
有些感动
DP的题之前真的是练的太多太多了
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 110;
const int M = 1e4+10;

bool dp[M];
int a[N];
int n;

int main(){
    int m=1e4;
	scanf("%d",&n);

	
    cin>>a[1];
    int d=a[1];
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		//dp[a[i]] = true;
		d=__gcd(a[i],d);
	}

	if(d!=1){
		puts("INF");
	}
	else{
		dp[0] = true;
		for(int i=1;i<=n;i++){
			for(int j=a[i];j<=m;j++)
				dp[j] = dp[j] | dp[j-a[i]];
		}	

		int ans=0;

		for(int i=1;i<=m;i++){
			if(!dp[i]){
				ans++;
			}
		}

		printf("%d\n",ans );
	}
	
	return 0;
}