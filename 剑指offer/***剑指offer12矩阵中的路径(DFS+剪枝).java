/**
    基本思路:
    dfs+剪枝
 */
class Solution {
    private int[] dx = {-1,0,1,0};
    private int[] dy = {0,-1,0,1};
    private int n,m,len;   

    public boolean exist(char[][] board, String word) {
        n = board.length;
        m = board[0].length;
        len = word.length();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(dfs(board,i,j,word,0))
                    return true;

        return false;
    }
    
    /**
        地图 i,j当前坐标 word目标词语 k为当前扫描字母的索引
     */
    boolean dfs(char[][] board,int i,int j,String word,int k){
        //越界情况判断
        if(i<0||j<0||i>=n||j>=m||board[i][j]!=word.charAt(k))
            return false;
        
        if(k==len-1)
            return true;

        board[i][j] = '\0'; //代表空格 这个位置已经走过了

        boolean res = false;

        for(int p=0;p<4;p++){
            res = res || dfs(board,i+dx[p],j+dy[p],word,k+1);
        }

        //恢复现场
        board[i][j] = word.charAt(k);

        return res;
    }

}