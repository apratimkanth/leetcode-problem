//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,unordered_map<int,vector<int>>&m,vector<bool>&visited){
        visited[node]=true;
        
        for(auto i:m[node]){
            if(visited[i]==false){
                dfs(i,m,visited);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        unordered_map<int,vector<int>>m;
        
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                if(adj[i][j]==1&&i!=j)
                    m[i].push_back(j);
            }
        }
        
        vector<bool>visited(V,false);
        int cnt=0;
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                dfs(i,m,visited);
                cnt++;
            }
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends