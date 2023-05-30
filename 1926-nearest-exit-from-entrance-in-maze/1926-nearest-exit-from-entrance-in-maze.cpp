class Solution {
public:
    bool isValid(int x, int y,int n,int m) {
        return x >= 0 and y >= 0 and x < n and y < m;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue< pair< pair<int,int>,int > >q;
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        q.push({{entrance[0],entrance[1]},0});
        visited[entrance[0]][entrance[1]]=true;
        vector<int>row={+1,-1,0,0};
        vector<int>col={0,0,-1,+1};
        
        

        
        while (!q.empty()) {
            // get the queue size
            int size = q.size();
            
            while (size--) {
                // take the first element from queue
                auto cur = q.front();
                q.pop(); // remove it

                if ((cur.first.first != entrance[0] or cur.first.second != entrance[1]) and (cur.first.first == 0 or cur.first.first == n - 1 or cur.first.second == 0 or cur.first.second == m - 1)) {
                    return cur.second;
                }
                
                // check in 4 dir
                for (int i = 0; i < 4; ++i) {
                    // get the new adj row and col
                    int x = cur.first.first + row[i];
                    int y = cur.first.second + col[i];
                    
                    if (isValid(x, y,n,m) and !visited[x][y] and maze[x][y] == '.') {
                        visited[x][y] = true;
                        q.push({{x, y},cur.second+1});
                    }
                }
            }
        }
        return -1;
    }
};