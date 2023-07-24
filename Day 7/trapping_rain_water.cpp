class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0, l = 0, r = n-1, left_max = 0, right_max = 0;
        
        while(l<=r) {
            // left_max/block is the determining factor
            if(height[l] <= height[r]) {
                if(height[l] >= left_max) {
                    left_max = height[l];
                } else {
                    ans += left_max - height[l];
                }
                l++;
            } else {
                // right_max/block is the determining factor
                if(height[r] >= right_max) {
                    right_max = height[r];
                } else {
                    ans += right_max - height[r];
                }
                r--;
            }
        }
        
        return ans;
    }
};