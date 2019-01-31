class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dpn(m);
        for(int i = 0; i < dpn.size(); ++i){
            dpn[i].resize(n);
        }
        dpn[0][0] = grid[0][0];
        for(int i = 1; i < m; ++i){
            dpn[i][0] = dpn[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < n; ++i){
            dpn[0][i] = dpn[0][i-1] + grid[0][i];
        }
        int i = 1;
        int min_dim = min(m, n);
        while(i < min_dim){
            dpn[i][i] = min(dpn[i-1][i]+grid[i][i], dpn[i][i-1]+grid[i][i]);
            for(int k = i + 1; k < m; ++k){
                dpn[k][i] = min(dpn[k-1][i]+grid[k][i], dpn[k][i-1]+grid[k][i]);
            }
            for(int k = i + 1; k < n; ++k){
                dpn[i][k] = min(dpn[i][k-1]+grid[i][k], dpn[i-1][k]+grid[i][k]);
            }
            i++;
        }
        return dpn[m-1][ n-1];
    }
};