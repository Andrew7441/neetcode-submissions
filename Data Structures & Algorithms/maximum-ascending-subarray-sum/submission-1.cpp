class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0, mx = 0, ans = 0;
        
        for(int i : nums) {
            if(i > mx) {
                res += i;
                mx = i;
            }
            else {
                ans = max(ans, res);
                mx = i;
                res = i;
            }
        }

        return max(res, ans);
    }
};