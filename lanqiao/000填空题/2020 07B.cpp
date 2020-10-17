/*
靠着日期的模板很快就可以解决了
但注意的是日期之间的长度问题
即 1-3 事实上经历了3天
而 从 第一天的12时  到 第三天的12时 这中间只经历了两天
做到这种题的时候一定要想清楚
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool check_valid(int year,int month,int day){
	if(month==0 || month>12)
		return false;
	
	if(day==0)
		return false;

	if(month!=2){
		if(day>days[month])
			return false;
	}
	else{
		int leap = year%100 && year%4==0 || year%400==0;
		if(day>28+leap)
			return false;
	}

	return true;
}

int main(){
	int tmp=0;

	for(int i=19210723;i<=20200701;i++){
		int year = i/10000;
		int month = i%10000/100;
		int day = i%100;
		if(check_valid(year,month,day))
			tmp++;
	}
	
	
	tmp--;
	
	LL res = (LL)tmp*24*60;
	
	
	
	cout<<res;

	return 0;
}