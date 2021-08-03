/*
    原题LC 210
    基本思路:拓扑排序
    拓扑序列的定义:
        对于图G中的任意一条有向边(u,v), u在排列中都出现在v的前面
        则称该排列是图G的拓扑序列
    关于拓扑序列的两个结论:
    1.拓扑序列无环 有环就没有拓扑序列
    2.有向无环图拓扑序列可能不止一中
    
    拓扑排序的基本思路:
    每一次在图中删除没有前驱的结点(即入度为0的点) 依次得到的序列就是 拓扑序列
    (具体实现时 可以借助一个邻接表记录每个点的后继 可以借助一个数组标记每个点的入度)

    算法实现(采用BFS)
    1.将入度为0的点入队
    2.只用队列非空去除队首元素,加入结果集中
        然后让该点所有的邻接点的入度-1 若邻接点-1后 入度为0则继续入队
    3.队列为空比较结果集的结点与图中结点数是否相等 若是则可生成一个拓扑序 否则无法生成

*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //先通过给定的信息生成相应的图用邻接表存储
        //[i,j] 要学习i需要先学j 所以反应在图里的关系就应该是 j->i 即j是i的先驱 i是j的后继
        unordered_map<int,set<int>>adj;
        vector<int>inDegree(numCourses,0);  //记录每个点的入度方便计算
        for(auto node:prerequisites){
            adj[node[1]].insert(node[0]);
            inDegree[node[0]]++;
        }

        queue<int>q;
        vector<int>ans;
        //开始拓扑排序
        //先将入度为0的点全部入队
        for(int i=0;i<inDegree.size();i++){
            if(!inDegree[i])
                q.push(i);          
        }

        while(!q.empty()){
            int t = q.front();
            q.pop();
            ans.push_back(t);
            //将其邻接点的入度减1
            for(auto node:adj[t]){
                inDegree[node]--;
                //如果其邻接点入度为0则入队
                if(!inDegree[node])
                    q.push(node);
            }                    
        }

        if(ans.size()!=numCourses)
            return vector<int>();
        
        return ans;
    }
};