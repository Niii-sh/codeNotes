/*
    删除指定的重复结点
    如传入45 但原链表中有多个45 就将多余的删掉使得链表里中只有一个45
    基本思路双指针
    第一个指针p找到一个存在的key
    而后第二个指针q从p开始走如果p->next为重复值则直接删除
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class node{
    public:
    int nodeValue;
    node*next;
    node():nodeValue(0),next(NULL){}
    node(int item):nodeValue(item),next(0){}
    
    
    //删除指定的重复结点
    void DeleteKeys(node*first,int key){
        if(!first||!first->next)    //表空或表中只有一个结点则直接返回无需删除
            return;
        node*p = first;
        while(p){
            if(p->nodeValue==key)
                break;
            p=p->next;
        }
        
        node* q=p->next;
    
        while(q){
            if(q->nodeValue==key){
                p->next=p->next->next;
                q=p->next;
            }
            else
                q=q->next;
        }
        
        return;
    }
    
    void traverse(node*head){
        auto p=head;
        while(p){
            printf("%d ",p->nodeValue);
            p=p->next;
            }
        puts("");
    }

    node* createList(node*head){
        auto p=head;
        int x=45;
        for(int i=1;i<=5;i++){
            p->next=new node(x);
            p=p->next;
        }
    
        return head;
    }
};



int main(){
    node*head=new node;
    
    head->createList(head);
    head->traverse(head);
    head->DeleteKeys(head,45);
    head->traverse(head);
    
    return 0;
}