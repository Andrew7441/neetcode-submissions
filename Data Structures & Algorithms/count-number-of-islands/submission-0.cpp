class Solution {
public:
    int ans = 0;

    void DFS(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j){
        int m = grid.size(), n = grid[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n){
            return;
        }

        if(visited[i][j] != -1) return;

        if(grid[i][j] == '0') return;

        visited[i][j] = 1;

        DFS(grid, visited, i, j + 1);
        DFS(grid, visited, i + 1, j);
        DFS(grid, visited, i, j - 1);
        DFS(grid, visited, i - 1, j);

    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && visited[i][j] == -1){
                    ans++;
                    DFS(grid, visited, i, j);
                }
            }
        }
        return ans;
    }
};
