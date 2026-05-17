class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int distance){
        int m = grid.size(), n = grid[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n) return;
        if(grid[i][j] == -1) return;
        if(distance > grid[i][j]) return;

        grid[i][j] = distance;

        dfs(grid, i, j + 1, distance + 1);
        dfs(grid, i + 1, j, distance + 1);
        dfs(grid, i, j - 1, distance + 1);
        dfs(grid, i - 1, j, distance + 1);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    dfs(grid, i, j, 0);
                }
            }
        }
    }
};
