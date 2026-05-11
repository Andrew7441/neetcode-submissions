class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);

        for(int i = 0; i < n; i++){
            int x = 0;
            for(int j = i; j < n; j++){
                if(temperatures[j] > temperatures[i]){
                    res[i] = x;
                    x = 0;
                    break;
                }else{
                    x++;
                }
            }
        }

        return res;
    }
};
