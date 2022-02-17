/*
    数学题:
    根据均值不等式进行推导 (a+b+c)/3 > √abc
    通过导数求倒得 
    推得尽量划分为3等分 所得乘积是最大的
*/
class Solution {
public:
    int cuttingRope(int n) {
        //n小于等于 3 时
        if(n<=3)
            return n-1; //2时 1+1 3时 1+2


        int a = n/3;
        int b = n%3;
        if(b==0)
            return pow(3,a);
        
        //如果切分的最后一段长度为1 则加入到前一段的3中
        if(b==1)
            return (pow(3,a-1)*4);
        
        //等于2的情况
        return pow(3,a)*2;
    }
};