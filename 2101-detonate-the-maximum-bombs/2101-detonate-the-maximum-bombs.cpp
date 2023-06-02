class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&m,vector<bool>&visit,int &move){
        visit[node]=true;
        move++;
        if(m.count(node)==false) return;
        for(auto i:m[node]){
            if(!visit[i]){
                dfs(i,m,visit,move);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        unordered_map<int,vector<int>>m;
        
        for(int i=0;i<n;i++){
            long long x1=bombs[i][0];
            long long y1=bombs[i][1];
            long long r1=bombs[i][2];

            for(int j=0;j<n;j++){
                if(i==j) continue;
                long long x2=bombs[j][0];
                long long y2=bombs[j][1];

                long long x=abs(x1-x2)*abs(x1-x2);
                long long y=abs(y1-y2)*abs(y1-y2);
                long long r=r1*r1;

                if(x+y<=r){
                    m[i].push_back(j);
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int move=0;
            vector<bool>visit(n,false);
            dfs(i,m,visit,move);
            ans=max(ans,move);
        }

        return ans;
    }
};