/*
    双栈即共享栈
    就是一个数组做成两个栈 两边作为栈顶
    按照工大这个题的意思的话 是bottom数组表示两个栈底的位置的位置
        其实也不用也没什么关系 直接判断即可
    与普通栈的区别就是 那个以最大值为栈底的栈每次入栈操作都是栈顶-1 
    然后就是栈满的条件改为了 top1==top2
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxSize=5;

struct dualStack{
    int bottom[2]={0,maxSize-1};
    int top1=-1;    //第一个栈的栈顶
    int top2=maxSize;  //第二个栈的栈顶
    int q[maxSize]={0};
};

void stackTraverse(dualStack&S);

//判空
bool isEmpty(dualStack S){
    return S.top1+1==S.bottom[0]&&S.top2-1==S.bottom[1];
    //有些别扭 但根据这个题目的意思 应该是这么做的
    //否则这个bottom就没有任何意义了 当然其实可以直接S.top1==-1&&S.top2==maxSize;
}

bool isFull(dualStack S){
    return S.top2-S.top1==1;
}

//x表示要入栈的数值 i表示要入哪个栈
bool push(int x,int i,dualStack &S){
    if(i<1||i>2){
        puts("输入栈号错误");
        return false;   
    }
    if(isFull(S)){
        puts("栈满无法继续入栈");
        return false;
    }  //栈满 
        
    //入第一个栈
    if(i==1){
        S.q[++S.top1]=x;
    }
    
    if(i==2){
        S.q[--S.top2]=x;
    }
    
    stackTraverse(S);
}

//i表示要出栈的栈号
bool pop(int i,dualStack&S){
    if(i<1||i>2){
        puts("栈号输入错误");
        return false;
    }
    
    if(isEmpty(S)){
        puts("栈空无法继续出栈");
        return false;
    }
    
    if(i==1)
        S.top1--;
    
    if(i==2)
        S.top2++;
        
    stackTraverse(S);
}


void stackTraverse(dualStack &S){
    puts("栈1的元素:");
    for(int i=0;i<=S.top1;i++)
        printf("%d ",S.q[i]);
    cout<<endl;    
    
    puts("栈2的元素:");    
    for(int i=maxSize-1;i>=S.top2;i--)
        printf("%d ",S.q[i]);
    
    cout<<"---";
    
    cout<<endl;
}

int main(){
    struct dualStack S;
    push(1,1,S);
    push(1,2,S);
    push(2,1,S);
    push(3,1,S);
    push(3,1,S);
    push(4,1,S);
    pop(2,S);
    pop(1,S);
    return 0;
}



