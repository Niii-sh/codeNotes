/*
会超时但最能体现出 将求最长上升子序列 与 最长公共子序列相结合的思想
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=3010;

int n;
int a[N],b[N];
int f[N][N];
int main() {
	scanf("%d",&n);

	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);

	for(int i=1; i<=n; i++)
		scanf("%d",&b[i]);

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			f[i][j] = f[i-1][j];
			if(a[i] == b[j]) {
				f[i][j] = max(f[i][j],1);
				for(int k=1; k<j; k++) {
					if(b[k]<b[j])
						f[i][j] = max(f[i][j],f[i][k]+1);
				}
			}
		}


	int res=0;

	for(int i=1; i<=n; i++)
		res = max(res,f[n][i]);

	printf("%d\n",res);

	return 0;
}