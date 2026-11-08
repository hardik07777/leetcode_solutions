class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i <m; i++){
            for(int j = 0; j<n; j++){
                bool flag = false;
                if(grid[i][j] == 1){
                    for(int col = 0; col < n; col++){
                        if(col == j){
                            continue;
                        }
                        if(grid[i][col] == 1){
                            flag = true;
                            break;
                        }

                    }
                    for(int row = 0; row < m; row++){
                        if(row == i){
                            continue;
                        }
                        if(grid[row][j] == 1){
                            flag = true;
                            break;
                        }

                    }
                }
                if(flag){
                    cnt++;
                }

            }
        }
        return cnt;
        
    }
};