class Solution {
public:
    void DFS(vector<vector<int>>& grid, int i, int j, int distance){
        int m = grid.size(), n = grid[0].size();

        //out of bounds
        if(i < 0 || i >= m || j < 0 || j >= n) return;
        //water
        if(grid[i][j] == -1) return;
        //shorter distance
        if(grid[i][j] < distance) return;
        //found
        grid[i][j] = distance;

        DFS(grid, i, j + 1, distance + 1);
        DFS(grid, i + 1, j, distance + 1);
        DFS(grid, i, j - 1, distance + 1);
        DFS(grid, i - 1, j, distance + 1);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    DFS(grid, i, j, 0);
                }
            }
        }

    }
};
