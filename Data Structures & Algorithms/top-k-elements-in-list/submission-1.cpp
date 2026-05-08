class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> mp;

        for(int i : nums) mp[i]++;

        vector<pair<int,int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(), [](auto& a,auto& b){
            return a.second > b.second;
        });

        for(int i = 0; i < k; i++){
            res.push_back(v[i].first);
        }
        return res;
    }
};
