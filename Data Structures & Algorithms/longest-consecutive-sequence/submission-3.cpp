class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        int mx = 1;
        set<int> st(nums.begin(), nums.end());
        vector<int> v(st.begin(), st.end());

        if(v.size() == 0) return 0;

        for(int i = 1; i < v.size(); i++){
            if(v[i] - v[i-1] == 1) mx++;
            else{
                ans = max(mx, ans);
                mx = 1;
            }
        }
        ans = max(mx, ans);
        return ans;
    }
};
