/**
    这题 还是要首先审题 是用给定的串去构造回文串 而不是在给定的串的去寻找
    这个直接用数组建立映射会更快 不过就当是练习使用hashmap 巩固java基础语法了
    统计字母个数 
    偶数一定可以称为回文串
    奇数 取一个 称为回文串 其余-1作为偶数即可
 */
class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character,Integer> map = new HashMap<>();
        
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(map.containsKey(ch)){
                int val = map.get(ch);
                map.put(ch,val+1);
            }
            else
                map.put(ch,1);
        }

        int res=0;

        int flag = 0;

        for(var node:map.entrySet()){
            if(node.getValue() % 2 == 0)
                res+=node.getValue();
            else{
                res+=node.getValue()-1;
                flag = 1;
            }
                
        }

        return res + flag;
    }
}