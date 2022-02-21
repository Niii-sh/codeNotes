/**
    直接双指针 
    遇到非字符数字 直接跳过 
    否则判断 如果不相等 则返回false 否则继续移动直至重合
 */
class Solution {
    private boolean isVaild(char ch){
        if(Character.isLetterOrDigit(ch))
            return true;
        return false;
    }

    public boolean isPalindrome(String s) { 
        if(s==null || s.length() == 0)
            return false;

        int n = s.length();
        int i=0, j = n-1;
        
        while(i<j){
            while(i<n && isVaild(s.charAt(i)) == false)
                i++;

            while(j>0 && isVaild(s.charAt(j)) == false  )
                j--;

            if(i>=n || j<0)
                continue;

            if( Character.toLowerCase(s.charAt(i)) == Character.toLowerCase(s.charAt(j))){
                i++;
                j--;
            }
            else
                return false;     
        }

        return true;
    }   
}