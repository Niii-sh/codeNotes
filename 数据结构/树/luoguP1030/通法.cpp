/*
通法:
在中序和后序中分别寻找
后序确定根后
然后通过根在中序中的位置分割子树然后不断输出
*/
#include<iostream>
#include<algorithm>

using namespace std;

string s1;
string s2;

void build(int l1,int r1,int l2,int r2){
    if(l1>r1)
        return;
    cout<<s2[r2];
    int p=l1;
    
    while(s1[p]!=s2[r2])
        p++;
    
    int cnt=p-l1;
    build(l1,p-1,l2,l2+cnt-1);
    build(p+1,r1,l2+cnt,r2-1);
    
}

int main(){
    cin>>s1>>s2;

    int n= s1.size() -1;

    build(0,n,0,n);

    return 0;
}