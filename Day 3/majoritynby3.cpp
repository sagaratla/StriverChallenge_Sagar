class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ans1 = INT_MIN, ans2 = INT_MIN;
        int count1 = 0, count2 = 0;
        for(int i=0;i<nums.size();i++) {
            if(count1 == 0 && nums[i] != ans2) {
                ans1 = nums[i];
                count1++;
            } else if(count2 == 0 && nums[i] != ans1) {
                ans2 = nums[i];
                count2++;
            } else if(nums[i] == ans1) {
                count1++;
            } else if(nums[i] == ans2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        
        // check if the frequency of ans1 and ans2 > [n/3]
        int min_freq = nums.size()/3;
        int freq1 = 0, freq2 = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == ans1) {
                freq1++;
            } else if(nums[i] == ans2) {
                freq2++;
            }
        }
        
        if(freq1 > min_freq && freq2 > min_freq) {
            return {ans1, ans2};
        } else if(freq1 > min_freq) {
            return {ans1};
        } else if(freq2 > min_freq) {
            return {ans2};
        }
        
        return {};
    }
};