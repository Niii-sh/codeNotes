/*
对日期模板的直接应用
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int s[8];

bool check_valid(int year,int month,int day){
	if(month==0||month>12)
		return false;
	
	if(day==0)
		return false;

	if(month!=2){
		if(day>days[month])
			return false;
	}
	else{
		int leap = year%100 && year%4==0 || year%400==0;
		if(day > 28+leap)
			return false;
	}

	return true;
}

bool is_pal(int n){
	int p=0;
	while(n){
		s[p++] = n%10;
		n/=10;
	}

	for(int i=0,j=p-1;i<j;i++,j--){
		if(s[i]!=s[j])
			return false;
	}

	return true;
}

int main(){
	int date1,date2;

	scanf("%d%d",&date1,&date2);
    
    
	int ans=0;

	for(int date = date1 ;date<=date2;date++){
		int year = date/10000;
		int month = date%10000/100;
		int day = date%100;
		if(check_valid(year,month,day)){
			if(is_pal(date))
				ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}