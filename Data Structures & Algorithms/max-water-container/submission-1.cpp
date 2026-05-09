class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int base = j - i;
                int h = min(heights[i], heights[j]);
                area = max(area, base * h);
            }
        }
        return area;
    }
};
