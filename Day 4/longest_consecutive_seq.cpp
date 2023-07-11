class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++) {
            s.insert(nums[i]);
        }
        
        int ans = 0;
        for(auto elem : s) {
            // if its the first element of the sequence
            if(s.find(elem-1) == s.end()) {
                int temp_count = 1;
                int curr_elem = elem;
                while(s.find(curr_elem+1) != s.end()) {
                    temp_count++;
                    curr_elem++;
                }
                ans = max(ans, temp_count);
            }
        }
        return ans;
    }
};