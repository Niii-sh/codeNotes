/*
    判断单链表的元素是否递增 
    没什么难度主要看对链表的基本操作是否熟悉
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    struct ListNode*next;
    ListNode(): val(0),next(nullptr) {}
};

bool isIncreaseSeq(ListNode*L){
    if(!L)
        return false;
        
    ListNode *p=L;
    ListNode *q;
    while(p->next){
        q=p->next;
        if(q->val<p->val){
            puts("非递增序列");
            return false;
        }
            
        p=p->next;
    }
    
    puts("是递增序列");
    return true;
}

//获取第i个位置的结点
ListNode *getElem(ListNode *L,int i){
    auto p=L;
    while(i--&&p){
        p=p->next;
    }
    
    return p;
}

//第i个位置插入值为x的元素
bool listInsert(ListNode*L,int x,int i){
    //非法位置
    if(i<0)
        return false;
    auto p=getElem(L,i);
    ListNode *s = new ListNode;
    s->val = x;
    s->next = p->next;
    p->next = s;
    return true;
}

void travserse(ListNode *L){
    auto p=L;
    while(p){
        printf("%d ",p->val);
        p=p->next;
    }
    cout<<endl;
}


int main(){
    ListNode*L = new ListNode;    
    
    for(int i=0;i<5;i++)
        listInsert(L,i+1,i);
    
    travserse(L);
    isIncreaseSeq(L);
    listInsert(L,-9,2);
    travserse(L);
    isIncreaseSeq(L);
    
    return 0;
}