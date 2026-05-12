class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        vector<int> res;

        for(int i : nums){
            mp[i]++;
        }

        vector<pair<int, int>> v;

        for(const auto& p : mp){
            v.push_back({p.first, p.second});
        }

        sort(v.begin(), v.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });

        for(int i = 0; i < k; i++){
            res.push_back(v[i].first);
        }

        return res;
    }
};
