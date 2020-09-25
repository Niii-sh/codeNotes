/*
基本思路:
模拟 + 递推应该就可以解决
几乎是秒A了 
不过还是出了 一点小问题 蓝桥杯OI赛制查不出来可能会比较麻烦..
*/

#include<iostream>
#include<algorithm>
using namespace std;

string s;

int main(){
    cin>>s;

    for(int i=0;i<s.size();i++){
        if(isalpha(s[i])&&i+1<s.size()&&isalpha(s[i+1])){
            cout<<s[i];
        }
        else if(isalpha(s[i])&&i+1<s.size()&&isdigit(s[i+1])){
            for(int j=0;j<s[i+1]-'0';j++)
                cout<<s[i];
            i++;
        }
        else
            cout<<s[i];
    }

    return 0;
}