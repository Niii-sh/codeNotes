/*
数组实现链表主要为了加快运算速度
以及简化相应的操作
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=1e5+10;

int head;   //指向表头的指针
int e[N];   //存放值
int ne[N];  //存放next的值 相当于链表中指向下一条的指针

int idx;    //代表当前操作的数的位置(也可以认为是当前操作节点的指针值)

//初始化链表
void init(){
    head=-1;
    idx=0;
}

//将某个数插入到位置k后
void add(int k,int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;  
}

//在表头插入 插入到链表首部的位置
void addHead(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx++; 
}

//删除k后的一个元素
void remove(int k){
    ne[k] = ne[ne[k]];
}

//删除表头
void removeHead(){
    head = ne[head];
}

int m;

int main(){
    cin>>m;
    init();
    while(m--){
        char op;
        cin>>op;
        int k,x;
        switch(op){
            ///向表头插入一个数
            case 'H': 
                cin>>x;
                addHead(x);
                break;
            //删除第k个输入数后面的数
            case 'D':
                cin>>k;
                if(!k)
                    removeHead();
                else
                    remove(k-1);
                break;
            //在第k个输入的数后面插入一个数
            case 'I':
                cin>>k>>x;
                add(k-1,x);
        }

    }
    
    for(int i=head;i!=-1;i=ne[i]){
        cout<<e[i]<<' ';
    }
    
    return 0;
}