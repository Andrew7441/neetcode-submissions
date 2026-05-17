class Solution {
public:
    vector<pair<int,int>> directions = {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;
        int min = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while(!q.empty() && fresh > 0){
            int sz = q.size();

            for(int k = 0; k < sz; k++){
                auto [i,j] = q.front();
                q.pop();

                for(const auto& [di,dj] : directions){
                    int newI = i + di;
                    int newJ = j + dj;

                    if(newI < 0 || newI >= m || newJ < 0 || newJ >= n) continue;

                    if(grid[newI][newJ] == 1){
                        fresh--;
                        grid[newI][newJ] = 2;
                        q.push({newI,newJ});
                    }
                }
            }
            min++;
        }

        if(fresh == 0) return min;
        return -1;
    }
};
