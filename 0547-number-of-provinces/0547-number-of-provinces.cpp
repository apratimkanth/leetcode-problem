class Solution {
public:
    void dfs(int node,vector<bool>&visited,unordered_map<int,vector<int>>m){
        visited[node]=true;

        for(auto i:m[node]){
            if(visited[i]==false)
                dfs(i,visited,m);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>m;
        int n=isConnected.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(isConnected[i][j]==1)
                    m[i].push_back(j);
            }
        }

        //apply dfs
        vector<bool>visited(n,false);
        int cnt=0;

        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(i,visited,m);
                cnt++;
            }
        }

        return cnt;
    }
};