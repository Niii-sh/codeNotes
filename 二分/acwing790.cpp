/*
非整数二分 没有那么多边界的情况
但却更加灵活 需要结合实际具体的去考虑
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    double n;
    cin>>n;
    
    double l=0;
    double r=n;
    
    while(abs(r-l)>1e-7){
        double mid = (l+r)/2;
        if(abs(mid*mid*mid)<abs(n))
            l=mid;
        else
            r=mid;
    }
    
    printf("%.6lf",l);
    
    return 0;
}