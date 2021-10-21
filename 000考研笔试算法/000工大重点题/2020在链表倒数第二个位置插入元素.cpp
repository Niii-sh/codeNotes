/*
    结构定义 根据当年原题的定义尽量不做修改
    编程实现将指定值插入到单向链表倒数第二个位置上
    送分题:
        这题的强化版本可以考插入中间位置 甚至是任意位置
        主要是用快慢指针就很好解决
*/
#include<iostream>
#include<algorithm>
using namespace std;

class node{
public:
    int value;
    node*next;
    node(int v,node*ptr =NULL){value=v;next=ptr;}
};

node*ListInsert(node*first,int data){
    //链表为空 或者只有一个元素则不存在倒数第二这个概念故直接返回
    if(!first||!first->next)
        return NULL;
    node*p=first->next->next;     //p为快指针   
    node*q=first;
    
    //当p走到空时 q则正好处于倒数第二个的位置
    while(p){
        p=p->next;
        q=q->next;
    }
    
    //正常的链表插入步骤即可
    node*s = new node(data);
    s->next = q->next;
    q->next = s;
    
    return first;
}

void traverse(node*L){
    node*p =L;
    while(p){
        printf("%d ",p->value);
        p=p->next;
    }
    
    cout<<endl;
}

int main(){
    node *L = new node(0);
    
    node*p = L;
    
    for(int i=1;i<=5;i++){
        node*s = new node(i);
        p->next = s;
        p=p->next;
    }
    
    traverse(L);
    
    ListInsert(L,111);
    
    traverse(L);
    
    return 0;
}
