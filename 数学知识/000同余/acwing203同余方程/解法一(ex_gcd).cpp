#include<iostream>
#include<algorithm>
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
	LL a,b;
	cin>>a>>b;
	LL x,y;
	
	LL d = ex_gcd(a,b,x,y);
	
	cout<<(x%b+b)%b<<endl;	
	
	return 0;
}