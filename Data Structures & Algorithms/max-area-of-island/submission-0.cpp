class Solution {
public:

    int DFS(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j){
        int height = 0, width = 0;
        int m = grid.size(), n = grid[0].size();

        //out of bounds check
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;

        //water check
        if(grid[i][j] == 0) return 0;

        //visited check
        if(visited[i][j] != -1) return 0;

        //mark visited
        visited[i][j] = 1;
        int area = 1;

        area += DFS(grid, visited, i, j + 1); // right
        area += DFS(grid, visited, i + 1, j); // down
        area += DFS(grid, visited, i, j - 1); // left
        area += DFS(grid, visited, i - 1, j); // up

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0;

        vector<vector<int>> visited(m, vector<int>(n, -1));

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
