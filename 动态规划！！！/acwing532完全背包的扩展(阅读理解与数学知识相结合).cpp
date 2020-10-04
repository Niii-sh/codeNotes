/*
性质1: a1,a2,a3...an 一定都可以被表示出来
性质2: 在最优解中,b1,b2,...,bn一定都是从a1,a2,..,an中 选择的 
		 (可用反证法证明)
性质3:b1,b2,..,bm 一定不能被其他bi表示出来 

基本思路:
	就是从后往前 判断某一个ai 是否可以被前面的若干个ai表示
	(事实上解是确定的 并非最优化问题) 

DP:思路
将ai视为体积 判断 ai 能否装满容量为aj 的背包
*/ 

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int T;

int dp[25010];
int a[110];

int main(){
	cin>>T;
	
	while(T--){
		int ans=0;
		int n;
		cin>>n;
        
        memset(dp,0,sizeof dp);
        
        dp[0] = 1;
            		
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		sort(a,a+n);
		
		int m = a[n-1];
		
		for(int i=0;i<n;i++){
		    if(!dp[a[i]])
		        ans++;
			for(int j=a[i];j<=m;j++)
				dp[j]+=dp[j-a[i]];
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
} 