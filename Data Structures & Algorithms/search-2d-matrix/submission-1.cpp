class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        int n = matrix[0].size();

        while(l <= r){
            int mid = (l + r) / 2;

            for(int j = 0; j < n; j++){
                if(matrix[mid][j] == target) return true;
            }

            if(target > matrix[mid][0]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return false;
    }
};
