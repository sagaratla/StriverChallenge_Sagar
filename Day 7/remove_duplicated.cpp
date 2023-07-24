class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return n;
        }
        int run_idx = 1;
        int i = 0;
        while(i<n) {
            while(run_idx < n && nums[run_idx] == nums[i]) {
                run_idx++;
            }
            if(run_idx == n) {
                break;
            }
            nums[++i] = nums[run_idx];
        }
        return i+1;
    }
};