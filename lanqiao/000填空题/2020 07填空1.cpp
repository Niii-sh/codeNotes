/*
审题比较重要 
如果在考场这题我肯定错了...
*/
/*
1分钟消耗600 即1秒钟消耗10
1分钟回复300 即1秒钟回复5
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int n = 10000;
		
	int ans=0;
	
	while(n){
		//还可以在坚持1分钟的情况下 
		if(n>=600){
			n-=600;
			ans+=60;
			n+=300;
			ans+=60;
		}
		//无法再坚持1分钟
		//添加上最后支持的时间(秒为单位) 
		else{
			ans+=n/10;
			n=0;
		}
	}


	printf("%d",ans);

	return 0;
}