/*
双向链表:
    就是可以向前找也可以向后找的单链表
    本题考察的是双链表的插入操作 也是最重要的一个  但还是把全部内容都顺带复习了一下
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct ListNode{
    int data;
    struct ListNode *next;
    struct ListNode *pre;
    ListNode(): data(0),next(nullptr),pre(nullptr){}
};

//找到相应位置结点的值
ListNode *getElem(ListNode *L,int i){
    ListNode* p = L;
    while(i--&&p){
        p=p->next;
    }
    
    return p;
}

//x为插入的值 i为位置
bool listInsert(ListNode*L,int x,int i){
    auto p=getElem(L,i);
    ListNode *s= new ListNode;
    s->data=x;
    s->next = p->next;
    if(p->next)
        p->next->pre=s;
    s->pre=p;
    p->next=s;
    return true;
}

//删除第i个位置的元素
bool listDelete(ListNode*L,int i){
    auto p=getElem(L,i-1);
    auto q=p->next->next;
    p->next=p->next->next;
    q->pre=q->pre->pre;
}

//正向遍历
void traverse(ListNode *L){
    auto p=L->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    
    cout<<endl;
}

//检验双链表的性质反向遍历
void Rtraverse(ListNode*L){
    auto pEnd = L;
    //获取最后一个元素的位置然后反向遍历
    while(pEnd->next)
        pEnd=pEnd->next;
    
    while(pEnd->pre){
        printf("%d ",pEnd->data);
        pEnd=pEnd->pre;
    }
    
    cout<<endl;
}


int main(){
    ListNode*L = new ListNode;
    for(int i=0;i<=5;i++){
       listInsert(L,i,i);
    }
        
    traverse(L);
    Rtraverse(L);
    
    listDelete(L,3);
    traverse(L);
    Rtraverse(L);
    
    return 0;
}