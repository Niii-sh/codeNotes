/*
比较巧妙的一题双指针
由于本题只要求交换一个数字
所以只需当前的cur = A[i] - B[j] 补足 差值(sumA-sumB)>>1 即可完成交换符合题意

太久没写代码了 
但为了之后的机试还是稍微早做准备多积累吧
*/
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();

        sort(A.begin(),A.end());
        sort(B.begin(),B.end());

        int sumA = accumulate(A.begin(),A.end(),0);
        int sumB = accumulate(B.begin(),B.end(),0);
        int target = (sumA-sumB)>>1;

        for(int i=0,j=0;i<n&&j<m;){
            int cur = A[i] - B[j];
            if(cur<target){
                i++;
            }else if(cur == target){
                return {A[i],B[j]};
            }
            else
                j++;
        }    

        return {};  
    }
};