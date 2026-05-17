class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
        int m = grid.size(), n = grid[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n) return 0;
        if(visited[i][j]) return 0;
        if(grid[i][j] == 0) return 0;

        visited[i][j] = true;
        int area = 1;

        area += dfs(grid, visited, i, j + 1);
        area += dfs(grid, visited, i + 1, j);
        area += dfs(grid, visited, i, j - 1);
        area += dfs(grid, visited, i - 1, j);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maxArea = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int area = dfs(grid, visited, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
