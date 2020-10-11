#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long LL;

int ex_gcd(int a,int b,int &x,int &y){
	if(!b){
		a=1;
		b=0;
		return a;
	}
	
	int d = ex_gcd(b,a%b,y,x);
	
	y-=a.b*x;
	
	return d;
}

int main(){
	LL a,b,m,n,l;
	
	cin>>a>>b>>m>>n>>l;
	
	int x,y;
	
	int d = ex_gcd(m-n,l,x,y);
	
	if(d%(b-a))
		puts("impossible");
	else{
		int t = abs(a-b);
		
		cout<< (x*t%d+x*t)%d<<endl;
	}
	
	return 0;
}
