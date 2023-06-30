class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), ans = nums[0], count = 1;
        for(int i=1;i<n;i++) {
            // cout<<"ans: "<<ans<<", count: "<<count<<endl;
            if(nums[i] == ans) {
                count++;
            } else {
                count--;
                if(count == 0) {
                    ans = nums[i];
                    count = 1;
                }
            }
        }
        return ans;
    }
};