/**
    基本思路:
        横向扫描
 */
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs == null || strs.length == 0)
            return null;

        if(strs.length == 1)
            return strs[0];


        String prefix = strs[0];

        String res="";
        int reslen = Integer.MAX_VALUE;

        for(int i=1 ; i<strs.length;i++){
            String tmp = commonPrefix(prefix,strs[i]);
            if(reslen > tmp.length()){
                res = tmp;
                reslen = tmp.length();
            }
        }  

        return res;
    }

    String commonPrefix(String prefix,String str){
        int len = Math.min(prefix.length(),str.length());
        int p = 0;

        while(p<len){
            if(prefix.charAt(p)!=str.charAt(p))    
                break;
            p++;
        }

        return prefix.substring(0,p);
    }

}