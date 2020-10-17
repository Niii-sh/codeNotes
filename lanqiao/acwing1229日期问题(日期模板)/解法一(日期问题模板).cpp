/*
题意很简单只有3种日期可能
年月日
月日年
日月年

但这题作为日期的模板题有很多值得注意(背诵)的地方
一个是is_leap的写法
一个是check_vaild的写法
一定要熟记于心才可以
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool check_vaild(int year,int month,int day){
	//月不合法
	if(month == 0||month>12)
		return false;
	//日不合法
	if(day==0)
		return false;
	if(month!=2){
		//日不合法 
		if(day>days[month])
			return false;
	}
	else{
		int leap = year%100 && year%4==0 || year%400 == 0;
		if(day>28 + leap)
			return false;
	}

	return true;
}

int main(){
	int a,b,c;
	scanf("%d/%d/%d",&a,&b,&c);	

	for(int date = 19600101; date<= 20591231 ;date++){
		int year = date/10000;
		int month = date%10000/100;
		int day = date%100;
		if(check_vaild(year,month,day)){
			if(a==year%100 && b==month && c==day 	 || 	//年月日
				a==month && b == day && c == year%100 || 	//月日年
				a==day && b==month && c==year%100)			//日月年		
				printf("%d-%02d-%02d\n",year,month,day);
		}
	}

	return 0;
}