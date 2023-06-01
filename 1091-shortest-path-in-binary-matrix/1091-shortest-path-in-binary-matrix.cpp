class Solution {
public:
    bool valid(int i,int j,int n){
        if(i>=0&&i<n&&j>=0&&j<n) return true;
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        q.push({0,0});
        if(grid[0][0]==1) return -1;
        int n=grid.size();
        vector<int>row={0,0,-1,+1,-1,+1,+1,-1};
        vector<int>col={1,-1,0,0,-1,+1,-1,+1};
        vector<vector<bool>>visit(n,vector<bool>(n,false));
        visit[0][0]=true;
        int move=1;
        
        while(q.empty()==false){
            int size=q.size();
            
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==n-1&&y==n-1) return move;

                for(int k=0;k<8;k++){
                    int nrow=x+row[k];
                    int ncol=y+col[k];
                    
                    if(valid(nrow,ncol,n)&&!visit[nrow][ncol]&&grid[nrow][ncol]==0){
                        q.push({nrow,ncol});
                        visit[nrow][ncol]=true;
                    }
                }
            }
            move++;
        }

        return -1;
    }
};