class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.size();
        

        for(int i = 0; i < n; i++){
            unordered_set<int> st;
            st.insert(s[i]);
            for(int j = i + 1; j < n; j++){
                if(st.count(s[j])) break;
                else{
                    st.insert(s[j]);
                }       
            }
            int sz = st.size();
            ans = max(ans, sz);
        }

        return ans;
    }
};
