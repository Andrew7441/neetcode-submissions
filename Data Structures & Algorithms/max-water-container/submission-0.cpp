class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int i = 0, j = heights.size() - 1;

        while(i < j){
            int base = j - i;
            int height = min(heights[i], heights[j]);

            area = max(area, base * height);
            
            if(heights[i] > heights[j]){
                j--;
            }else{
                i++;
            }
        }
        return area;
    }
};
