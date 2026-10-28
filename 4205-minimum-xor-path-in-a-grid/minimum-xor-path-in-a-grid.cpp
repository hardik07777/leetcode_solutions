class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<unordered_set<int>>>st(m,vector<unordered_set<int>>(n));
        st[0][0].insert(grid[0][0]);
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 and j == 0){
                    continue;
                }
                if( i > 0){
                    for(auto val : st[i-1][j]){
                        st[i][j].insert(val ^ grid[i][j]);
                    }
                }
                if( j > 0){
                    for(auto val : st[i][j-1]){
                        st[i][j].insert(val ^ grid[i][j]);
                    }
                }
            }
        }
        int maxi = INT_MAX;
        for(auto val : st[m-1][n-1]){
            maxi = min(maxi , val);
        }
        return maxi ;
    }
};