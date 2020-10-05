/*
思路简单但实现时应该特别注意
借鉴二维数组的表示方法
每行每列的下标从0开始 
这样的话可以保证n/w m/w 就是对应的行号  n%w m%w就是对应的列好 (否则会有问题！！)
另外注意再求蛇形矩阵特殊的反转行时 由于我们的已经规定了行列从0开始 
所以在求反转后的结果时应该是 w-1-n%w 或 w-1-m%w
*/
#include<iostream>
#include<algorithm>
using namespace std;

int w,m,n;

int main(){
	cin>>w>>m>>n;
	
	int mc=m/w,mr=m%w;
	int nc=n/w,nr=n%w;
	
	cout<<abs(mc-nc)+abs(mr-nr);
	
	return 0;
}