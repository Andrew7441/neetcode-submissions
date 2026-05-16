class Solution {
public:
    int DFS(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j){
        int m = grid.size(), n = grid[0].size();

        //check for out of bounds
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;

        //check for visited
        if(visited[i][j] != -1) return 0;

        //check for water
        if(grid[i][j] == 0) return 0;

        visited[i][j] = 1;
        int area = 1;

        area += DFS(grid, visited, i, j+1); // right
        area += DFS(grid, visited, i + 1, j); // down
        area += DFS(grid, visited, i, j - 1); // left
        area += DFS(grid, visited, i - 1, j); // up

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));

        int maxArea = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && visited[i][j] == -1){
                    int area = DFS(grid, visited, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
