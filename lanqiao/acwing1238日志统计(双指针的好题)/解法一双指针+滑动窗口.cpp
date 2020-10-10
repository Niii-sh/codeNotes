/*
如果想清楚的话事实上这题并不复杂
但却是为双指针与滑动窗口应用的一道好题
*/

#include<iostream>
#include<algorithm>
#include<cstdio> 
using namespace std;

const int N = 1e5+10;

struct Node{
	int t;
	int id;
	bool operator < (Node &tmp) const{
		return t<tmp.t;
	}
}record[N];

int cnt[N];	//用于各个店在在时间段内点赞的次数 
bool st[N];

imt n,d,k;

int main(){
	scanf("%d%d%d",&n,&d,&k);
	
	for(int i=0;i<n;i++){
		scanf("%d%d",&record[i].t,&record[i].id);
	}
	
	sort(record,record+n);
	
    /*
    以下while循环为本题的主要思维难点 也是需要注意的点
    要想写正确首先需要弄清楚每一个量代表的含义
    cnt[]记录的是id店铺在k时间段内收获的点赞数
    而i,j代表的是按时间排序的记录对应的下标(不代表时间 也不代表其他别的！！！ 这点很重要)
    因此该段时间为record[i].t - record[j].t 记为T
    而T内所包含的是i-j的所有店铺
    因此T>d 时j++ ,而第j条记录所对应的店铺id的点赞消息 将会被清除T区间
    因此时cnt[record[j].t]--
    */

	for(int i=0,j=0;i<n;i++){
		int id = record[i].id;
		
		cnt[id]++;		
		
		while(record[i].t-record[j].t>=d){
			cnt[record[j].t]--;
			j++;
		}
		
		if(cnt[id]>=k)
			st[id]=true;
	}
	
	for(int i=0;i<=1e5;i++){
		if(st[i])
			printf("%d\n",i);
	}
	
	
	return 0;
}