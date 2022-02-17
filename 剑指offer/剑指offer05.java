class Solution {
    public String replaceSpace(String s) {
        String res="";
        char[] str = s.toCharArray();
        for(int i=0;i<str.length;i++){
            if(str[i]==' ')
                res+="%20";
            else
                res+=str[i];
        }

        return res;
    }
}