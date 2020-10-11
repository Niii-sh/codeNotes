/*
这题还是蛮不错的 尤其对公倍数的计算十分取巧

基本思路:
	1.如果n<=2 最小公倍数为n
	2.如果n是奇数 那么最小公倍数的最大值为末尾三个数相乘
	(这是因为此时末尾三数为2奇1偶 所得数仍然为奇数 不存在可以被2除的情况 )
	3.如果n为偶数
	a.n是偶数且不是3的倍数那么跳过n-2 即可满足情况2 
	(这是因为n为偶数则 n-1为奇数 n-2为偶数 n-3为奇数)
	b.如果n是偶数且为3的倍数 则会被约去一个3
	所以不能像上面那样选择必须(n-1)*(n-2)*(n-3)这样保证了三个数均非3的倍数 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long LL;

LL n;

int main(){
	cin>>n;
	if(n<=2)
		cout<<n;
	else if(n%2){
		cout<<n*(n-1)*(n-2);
	}
	else if(n%2==0){
		if(n%3==0)
			cout<<(n-1)*(n-2)*(n-3);
		else
			cout<<n*(n-1)*(n-3);
	}
}