/*
    BST算法整理
    1.构造
    2.查找
    3.插入
    4.删除
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;


bool insert(BSTree &T,int k){
    if(!T){
        T = new BSTNode();
        T->key = k;
        T->lchild = T->rchild = nullptr;
        return true;
    }
    else if(k<T->key)
        return insert(T->lchild,k);
    else if(k>T->key)
        return insert(T->rchild,k);
    else
        return false;
}

bool find(BSTree T,int k){
    if(!T)
        return false;
        
    int v=T->key;
    
    if(v==k)
        return true;
    else if(v>k)
        return find(T->rchild,k);
    else if(v<k)
        return find(T->lchild,k);
        
}

void inOrderTraverse(BSTree&T){
    if(!T)
        return;
    inOrderTraverse(T->lchild);
    printf("%d",T->key);
    inOrderTraverse(T->rchild);
}

int main(){
    BSTree T=nullptr;
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        insert(T,x);
    }
    
    inOrderTraverse(T);
    cout<<endl;
    
    puts("查找");
    
    if(find(T,1))
        puts("yes");
    
    return 0;
}