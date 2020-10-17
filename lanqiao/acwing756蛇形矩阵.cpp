/*
这题好像就是1年前 校内选拔的那道题
时间过的好快... 又回到了最初的点
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;

int a[N][N];
int n,m;

int main(){
	cin>>n>>m;

	int left = 0, right = m-1;
	int top = 0 , bottom = n-1;

	int k = 1;

	while(left<=right && top<=bottom){
		for(int i=left ;i<=right;i++){
			a[top][i] = k++;
		}

		for(int i=top+1;i<=bottom;i++){
			a[i][right] = k++;
		}

		for(int i = right-1;i>=left&&top<bottom;i--){
			a[bottom][i] = k++;
		}

		for(int i = bottom-1;i>top && left<right ;i--){
			a[i][left] = k++;
		}

		left++,right--,top++,bottom--;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}

	return 0;
}