#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=1e5+10;;

int p[N];


//1.查找该点的根节点 (即找到该点属于哪个集合)
//2.路径压缩
int find(int x){
    if(p[x]!=x)
        p[x]=find(p[x]);    //路径压缩主要体现在这里
                            //find()中不断递归 最终p[]的祖宗节点赋值为整个集合的根节点
    return p[x];
}



int main(){
    int n,m;
    cin>>n>>m;

    //初始化并查集
    //每个节点的根为自己
    for(int i=1;i<=n;i++)
        p[i]=i;


    while(m--){
        char op[2];
        int a,b;
        cin>>op>>a>>b;

        //如果合并操作
        if(*op=='M')
            p[find(a)] = find(b);
        else{
            if(find(a)==find(b))
                puts("Yes");
            else    
                puts("No");    
        }
    }

    return 0;
}