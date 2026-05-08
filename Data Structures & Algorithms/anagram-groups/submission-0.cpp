class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;

        for(string word: strs){
            string key = word;

            sort(key.begin(), key.end());

            mp[key].push_back(word);
        }

        for(const auto& p: mp){
            res.push_back(p.second);
        }

        return res;
    }
};
