/*
    结构定义可能写的有些奇怪 
    但主要还是根据 18年题干所给出的条件去写 忠实于原题
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d,Node*n=NULL):data(d),next(n){}
    
};

void Add2Last(Node* head,int item){
    Node*p = head;
    
    if(!p)
        p = new Node(item);
    while(p->next){
        p=p->next;
    }
    
    p->next = new Node(item);
    p=p->next;
}

void traverse(Node*head){
    auto p=head;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    cout<<endl;
}


int main(){
    Node *L = new Node(0);
    
    for(int i=1;i<=5;i++)
        Add2Last(L,i);
    
    traverse(L);
    
    return 0;
}