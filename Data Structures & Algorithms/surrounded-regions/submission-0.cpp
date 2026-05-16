class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        int m = board.size(), n = board[0].size();
        //out of bounds
        if(i < 0 || i >= m || j < 0 || j >= n) return;
        //not an O
        if(board[i][j] != 'O') return;

        //mark safe
        board[i][j] = 'S';

        dfs(board, i, j + 1);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i - 1, j);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        for(int c = 0; c < n; c++){
            if(board[0][c] == 'O') dfs(board, 0, c);
            if(board[m - 1][c] == 'O') dfs(board, m - 1, c);
        }

        for(int r = 0; r < m; r++){
            if(board[r][0] == 'O') dfs(board, r, 0);
            if(board[r][n - 1] == 'O') dfs(board, r, n - 1);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
