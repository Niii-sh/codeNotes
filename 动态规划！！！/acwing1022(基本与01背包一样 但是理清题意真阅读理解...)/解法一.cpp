#include<iostream>
#include<algorithm>
using namespace std;

//n表示精灵球的数量
//m表示皮卡丘的初始体力值
//k表示野生小精灵的数量 
int n,m,k;

int v[1010];	//收服每种小精灵所需精灵球的数量
int d[110];		//每种小精灵收服时对皮卡丘造成的伤害 

int dp[1010][510];	//第一维表示剩余的精灵球 第二维表示剩余的体力	值代表可以收服小精灵的最大数 

int main(){
	cin>>n>>m>>k;
	
	for(int i=1;i<=k;i++)
		cin>>v[i]>>d[i];
	
	for(int i=1;i<=k;i++){
		for(int j=n;j>=v[i];j--)
		    //这里要注意 一定要从m-1开始
		    //也许这就是所谓的阅读理解吧...
		    //皮卡丘不能死 真的是太蛋疼了这题
			for(int u=m-1;u>=d[i];u--)
			    if(dp[j-v[i]][u-d[i]]+1>dp[j][u]){
			        dp[j][u] = dp[j-v[i]][u-d[i]]+1;
			    }
	}
    
    int r=0;
    
    for(int i=0;i<=m;i++)
        if(dp[n][i] == dp[n][m-1]){
            r=i;
            break;
        }
            	
	cout<<dp[n][m-1]<<' '<<m-r<<endl;
	
	
	return 0;
}