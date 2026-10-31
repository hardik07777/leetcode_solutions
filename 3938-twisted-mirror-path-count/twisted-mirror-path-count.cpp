
class Solution {
public:
    int m, n;
    int mod = 1e9 + 7;

    int left = 0;
    int up = 1;

    int helper(int i, int j,
               vector<vector<int>>& grid,
               vector<vector<vector<int>>>& answer,
               int camefrom) {

        if (i >= m || i < 0 || j >= n || j < 0) {
            return 0;
        }

        if (i == m-1 && j == n-1) {
            return 1;
        }

        if (answer[i][j][camefrom] != -1) {
            return answer[i][j][camefrom];
        }

        int right = 0;
        int down = 0;

        if (grid[i][j] == 0) {
            right = helper(i, j+1, grid, answer, left);
            down = helper(i+1, j, grid, answer, up);
        }
        else {
            if (camefrom == left) {
                return answer[i][j][camefrom] =
                    helper(i+1, j, grid, answer, up);
            }
            else {
                return answer[i][j][camefrom] =
                    helper(i, j+1, grid, answer, left);
            }
        }

        return answer[i][j][camefrom] =
            (right + down) % mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> answer(
            m, vector<vector<int>>(n, vector<int>(2, -1))
        );

        return helper(0, 0, grid, answer, left);
    }
};
