class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            if(i>0 && nums[i] == nums[i-1]) {
                continue;
            }
            int l = i+1, r = n-1;
            while(l<r) {
                long long sum = nums[i];
                sum += nums[l];
                sum += nums[r];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l] == nums[l-1]) {
                        l++;
                    }
                    while(l<r && nums[r] == nums[r+1]) {
                        r--;
                    }
                } else if(sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
};