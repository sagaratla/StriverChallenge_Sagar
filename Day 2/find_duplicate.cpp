class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        while(nums[0] != nums[nums[0]]) {
            int temp = nums[0]; // temp = 1
            nums[0] = nums[temp]; // nums[0] = 3
            nums[temp] = temp; // nums[1] = 1
        }
        return nums[0];
    }
};