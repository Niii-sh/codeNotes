#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 1e4+10;

int b[N];
bool st[N];

int n;

int main(){
	cin>>n;
	
	for(int i=1;i<=n;i++)
		cin>>b[i];
		
	int cnt=0;
	
	for(int i=1;i<=n;i++){
		if(!st[i]){
		    cnt++;
			for(int j=i;!st[j];j=b[j]){
				st[j] = true;
			}
		}
	}
	
	cout<<n-cnt;
	
	return 0;
}