/*
最原始方法ac了
感觉自己的智商受到了侮辱
*/ 
#include<iostream>
#include<algorithm>
using namespace std;

int q[4];
int n;

int main(){
	cin>>n;
    
    q[0]=2;
    q[1]=0;
    q[2]=1;
    q[3]=9;
    
    int ans=0;
    	
	for(int i=1;i<=n;i++){
	    int k=i;
	    bool flag=false;
	    while(k){
	        for(int j=0;j<4;j++){
	            if(q[j]==k%10){
	                flag=true;
	                ans+=i;
	                break;
	            }
	        }
	        if(flag)
	            break;
	        k=k/10;
	    }
	}
	
	cout<<ans;
	
	return 0;
}