class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        for(int i = 0; i < n; i++){
            vector<int> triplets;
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(i != j && i != k && j != k && 
                        (nums[i] + nums[j] + nums[k] == 0)){
                        res.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        std::for_each(res.begin(), res.end(), [](vector<int>& v){
            sort(v.begin(), v.end());
        });

        sort(res.begin(), res.end());

        res.erase(std::unique(res.begin(), res.end()), res.end());
        return res;
    }
};
