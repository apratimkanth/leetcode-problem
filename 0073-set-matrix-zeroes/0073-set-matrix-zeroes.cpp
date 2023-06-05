class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int>row;
        unordered_set<int>column;
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row.count(i)) matrix[i][j]=0;
                if(column.count(j)) matrix[i][j]=0;
            }
        }
    }
};