https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int lMax = 0, rMax = 0, water = 0;
        while(left<right){
            if(height[left] <= height[right]){
                lMax = max(lMax, height[left]);
                water += max(0, lMax-height[left]);
                left++;
            }else{
                rMax = max(rMax, height[right]);
                water += max(0, rMax-height[right]);
                right--;
            }
        }
        return water;
    }
};