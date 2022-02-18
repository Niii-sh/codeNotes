class Solution {
    public int[] printNumbers(int n) {
        int num_len = 1;
        while(n>0){
            num_len*=10;
            n--;
        }

        int[] res = new int[num_len-1];

        for(int i=0;i<res.length;i++)
            res[i] = i+1;
        return res;
    }
}