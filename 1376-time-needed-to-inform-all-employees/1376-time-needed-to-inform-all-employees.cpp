class Solution {
public:
    int dfs(int headID,unordered_map<int,vector<int>>&m,vector<int>&informTime){
        int maxtime=0;
        for(auto i:m[headID]){
            maxtime=max(dfs(i,m,informTime),maxtime);
        }

        return informTime[headID]+maxtime;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>m;

        for(int i=0;i<n;i++){
            int man=manager[i];
            m[man].push_back(i);
        }

        for(auto i:m){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        return dfs(headID,m,informTime);
    }
};