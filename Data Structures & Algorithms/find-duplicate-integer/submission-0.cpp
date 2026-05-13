class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int ans = 0;

        for(int& i : nums){
            mp[i]++;
        }

        for(const auto& p : mp){
            if(p.second > 1){
                ans = p.first;
            }
        }
        return ans;
    }
};
