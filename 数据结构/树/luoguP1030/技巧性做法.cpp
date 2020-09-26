/*
通过后序遍历可确定根
通过中序遍历可以将树分开分为左右子树
而每一次分开后 一个位置每被划分为右半部分一次 中序和后序的位置 就会错开1
*/

#include<iostream>
#include<algorithm>

using namespace std;

string s1;  //读入先序序列
string s2;  //读入后序序列

//l,r为当前这个树的边界范围 以中序树为基准
//s为子树分割为右半部分的次数  视为根的偏移量
void dfs(int l,int r,int s){
    cout<<s2[r-s];

    for(int i=l;i<=r;i++){
        if(s1[i]==s2[r-s]){
            //仍存在左子树
            if(i>l)
                dfs(l,i-1,s);
            //仍存在右子树
            if(i<r)
                dfs(i+1,r,s+1);
        }
    }
}


int main(){
    cin>>s1>>s2;

    dfs(0,s1.size()-1,0);

    return 0;
}