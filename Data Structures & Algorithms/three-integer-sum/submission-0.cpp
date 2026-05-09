class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(i != j && i != k && j != k &&
                       nums[i] + nums[j] + nums[k] == 0){
                            res.push_back({nums[i], nums[j], nums[k]});
                       }
                }
            }
        }

        for(auto& v : res){
            sort(v.begin(), v.end());
        }

        sort(res.begin(), res.end());

       res.erase(unique(res.begin(), res.end()), res.end());

        return res;
    }
};
