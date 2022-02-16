/*
    从右上角开始找
    如果符合的话 则直接返回 
    如果target小于当前值 则 往左找
    如果targer大于当前值 则 往右找
*/
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

        if(matrix.size()==0||matrix[0].size()==0)
            return false;

        int n = matrix.size();
        int m = matrix[0].size();

        int i=0,j=m-1;
        
        while(i<n&&j>=0){
            int &num = matrix[i][j];
            if(target==num)
                return true;
            else if (target<num)
                j--;
            else    
                i++;              
        }

        return false;

    }
};