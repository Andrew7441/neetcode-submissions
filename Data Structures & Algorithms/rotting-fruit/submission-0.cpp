class Solution {
public:
    vector<pair<int,int>> directions ={
        {0,1}, //right
        {1,0}, //down
        {0,-1},//left
        {-1,0}
    };

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fruits = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1) fruits++;
            }
        }

        int min = 0;

        while(!q.empty() && fruits > 0){
            int size = q.size();

            for(int k = 0; k < size; k++){
                auto [i, j] = q.front();
                q.pop();

                //check 4 directions
                for(auto [di, dj] : directions){
                    int newI = i + di;
                    int newJ = j + dj;

                    if(newI < 0 || newI >= m || newJ < 0 || newJ >= n){
                        continue;
                    }

                    if(grid[newI][newJ] == 1){
                        grid[newI][newJ] = 2;
                        fruits--;
                        q.push({newI,newJ});
                    }
                }
            }

            min++;
        }

        if(fruits == 0) return min;
        return -1;
    }
};
