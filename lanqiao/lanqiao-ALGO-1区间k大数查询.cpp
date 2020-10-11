/*
luoruo的代码也不一定都是最好的
更多还是作为参考答案
这题存负数逆序的这个方法算是我独创的就感觉很妙
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

const int N = 1e5+10;

int a[N];

int n,m;

int main(){
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	scanf("%d",&m);
	
	vector<int>ans;
	
	while(m--){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		vector<int>tmp;
		for(int i=l;i<=r;i++)
			tmp.push_back(-a[i]);
		sort(tmp.begin(),tmp.end());
		ans.push_back(-tmp[k-1]);
	}
	
	for(int i=0;i<ans.size();i++)
		printf("%d\n",ans[i]);
	
	return 0;
}