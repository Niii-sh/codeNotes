/*
    单链表的基本操作 
    按位序 删除或插入元素
    可能这种考的会比较多一些
    王道以及教科书 是把第一个元素的位置视作1 即头节点后的第一个元素为第一个元素
    但还是看具体题目吧 
*/
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode* next;
}LNode,*LinkList;

//题目的意思就是 删除第i个位置的元素
//然后用s返回其值
bool listDelete(LinkList L,int i,int *s){
    LNode *p=L,*q;
    int j=0;
    while(p&&j<i-1){
        p=p->next;
        j++;
    }
    
    /*这里原题是有些问题
    if(p->next==NULL||j>i-1)
        return false;
    这样判断 如果已经是 p==NULL的话就会段错误
    */
    q=p->next;
    p->next=q->next;
    *s->data = q->data;
    free(q);
    
}

