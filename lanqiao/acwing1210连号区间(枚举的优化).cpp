/*
关键在于发现性质
连号区间意味着
该区间的内的
max-min = j-i
这个怎么说呢... 主要是当时要想的到吧... 题还是要多做
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10010;

int n;
int q[N];

int main(){
	cin>>n;
	
	for(int i=1;i<=n;i++)
		cin>>q[i];
	
	int ans=0;
    
	for(int i=1;i<=n;i++){
	    int low =  q[i];
	    int high = q[i];
	    for(int j=i;j<=n;j++){
	        low = min(low,q[j]);
	        high = max(high,q[j]);
	       ans+= [](int v,int dist)->int{
	            return v==dist;  
	       }(high-low,j-i);
	    }
	}
	
	cout<<ans;
	return 0;
}