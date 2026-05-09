class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> st;
        int i = 0;
        
        //check rows
        for(int i = 0 ; i < 9; i++){
            st.clear();

            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }
        
        //check columns
        for(int j = 0; j < 9; j++){
            st.clear();

            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                if(st.count(board[i][j])) return false;

                st.insert(board[i][j]);
            }
        }

        for(int row = 0; row < 9; row += 3){
            for(int col = 0; col < 9; col += 3){
                st.clear();

                for(int i = row; i < row + 3; i++){
                    for(int j = col; j < col + 3; j++){
                        if(board[i][j] == '.') continue;
                        if(st.count(board[i][j])) return false;
                        st.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }

};
