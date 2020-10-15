#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

string start,last;
int n;

void turn(string &s,int i){
	if(s[i]=='o')
		s[i] = '*';
	else
		s[i] = 'o';

	if(s[i+1]=='o')
		s[i+1] = '*';
	else
		s[i+1] = 'o';
}

int main(){
	cin>>start>>last;

	n = start.size();

	int ans=0;

	for(int i=0;i<n-1;i++){
		if(start[i]!=last[i]){
			ans++;
			turn(start,i);
		}
	}

	printf("%d",ans);

	return 0;
}