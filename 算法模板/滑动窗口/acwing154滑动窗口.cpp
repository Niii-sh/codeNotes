/*
基本策略:
通过单调队列来维护窗口
这样在求最小值时 队首就是最小值
求最大值时 队尾就是最大值

值得注意的是
队列中存的是下标而非值 这样有助于对于窗口的操作 以及单调队列的维护
*/
#include <iostream>
using namespace std;

const int N = 1000010;

int a[N],q[N];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);

	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	int hh=0,tt=-1;

	//寻找滑动窗口最小值
	for(int i=0;i<n;i++){
		//i-k+1 队首元素已经超出了 窗口范围直接弹出
		if(hh<=tt && i-k+1>q[hh])
			hh++;

		//保持窗口的单调性
		//如果队尾元素比当前元素大 则直接出队即可
		//因为不管怎么样 都不可能是这个值作为答案
		while(hh<=tt && a[q[tt]]>=a[i])
			tt--;

		//讲当前元素入队
		//此时队列是单调的
		//而队首元素为最小值
		q[++tt] = i;

		if(i>=k-1)
			printf("%d ",a[q[hh]]);
	}

	puts("");

	hh=0,tt=-1;

	for(int i=0;i<n;i++){
		//判断当前队首是否需要出队
		if(hh<=tt && i-k+1>q[hh])
			hh++;

		//维护单调队列 确保队首是最大值
		while(hh<=tt && a[i]>=a[q[tt]])
			tt--;

		//将当前元素入队
		q[++tt] = i;
		
		//确保当前队列 已经将一个窗口的元素全部加入后再输出
        if(i>=k-1)
		printf("%d ",a[q[hh]]);
	}

	return 0;
}