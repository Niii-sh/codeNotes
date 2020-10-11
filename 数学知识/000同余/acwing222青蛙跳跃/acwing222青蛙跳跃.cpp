#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long LL;

int ex_gcd(LL a,LL b,LL &x,LL &y){
	if(!b){
		x=1;
		y=0;
		return a;
	}
	
	LL d = ex_gcd(b,a%b,y,x);
	
	y-=a/b*x;
	
	return d;
}

int main(){
	LL a,b,m,n,l;
	
	cin>>a>>b>>m>>n>>l;
	
	LL x,y;
	
	LL d = ex_gcd(m-n,l,x,y);
	
	if((b-a)%d)
		puts("Impossible");
	else{
	    x*=(b-a)/d;
		LL t = abs(l/d);
		
		cout<< (x%t+t)%t<<endl;
	}
	
	return 0;
}
