class Solution {
public:
    void swap(vector<int>& nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
    
    void print(const vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            cout << nums[i] << " ";
        }
        cout<<endl;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1) {
            return;
        }
        
        int i = n-2;
        while(i>=0) {
            if(nums[i] < nums[i+1]) {
                break;
            }
            i--;
        }
        
        if(i == -1) {
            if(nums[i+1] >= nums[i+2]) {
                // we have to sort in ascending order
                sort(nums.begin(), nums.end());
                return;
            } else {
                i++;
            }
        }
        
        // cout<<i<<endl;
        // we have to find the next greater element in the other half of the arr
        sort(nums.begin() + i + 1, nums.end());
        int local_min_idx = -1;
        for(local_min_idx = i+1; local_min_idx<n; local_min_idx++) {
            if(nums[i] < nums[local_min_idx]) {
                break;
            }
        }
        // cout<<local_min_idx<<endl;
        // print(nums);
        swap(nums, i, local_min_idx);
        sort(nums.begin() + i + 1, nums.end());
    }
};