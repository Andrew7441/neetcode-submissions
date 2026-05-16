class Solution {
public:
    int ROWS, COLS;

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, 
             int i, int j, int prevHeight){

        ROWS = grid.size(), COLS = grid[0].size();

        if(i < 0 || i >= ROWS || j < 0 || j >= COLS) return;
        if(visit[i][j]) return;
        if(grid[i][j] < prevHeight) return;

        visit[i][j] = true;

        dfs(grid, visit, i, j + 1, grid[i][j]);
        dfs(grid, visit, i + 1, j, grid[i][j]);
        dfs(grid, visit, i, j - 1, grid[i][j]);
        dfs(grid, visit, i - 1, j, grid[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        for(int c = 0; c < COLS; c++){
            dfs(heights, pac, 0, c, heights[0][c]);
            dfs(heights, atl, ROWS-1, c, heights[ROWS-1][c]);
        }

        for(int r = 0; r < ROWS; r++){
            dfs(heights, pac, r, 0, heights[r][0]);
            dfs(heights, atl, r, COLS-1, heights[r][COLS-1]);
        }

        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
