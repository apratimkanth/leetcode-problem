class Solution {
public:
    int ans=0;
    void dfs(int node,vector<bool>&visit,vector<vector<int>>&edges,unordered_map<int,unordered_set<int>>&m){
        visit[node]=true;
        for(auto i:edges[node]){
            if(!visit[i]){
                if(m[node].count(i)) ans++;
                dfs(i,visit,edges,m);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>edges(n);
        unordered_map<int,unordered_set<int>>m;

        for(auto i:connections){
            int x=i[0];
            int y=i[1];
            edges[x].push_back(y);
            edges[y].push_back(x);
            m[x].insert(y);
        }
        vector<bool>visit(n,false);

        dfs(0,visit,edges,m);

        return ans;
    }
};