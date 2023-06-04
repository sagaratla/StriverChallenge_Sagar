class Solution {
public:
    void swap(vector<int>& arr, int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }
    
    void print(const vector<int>& arr) {
        for(int i=0;i<arr.size();i++) {
            cout << arr[i] << " ";
        }
        cout<<"\n";
    }
    
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero_idx = 0, two_idx = n-1;
        int i = 0;
        while(i<=two_idx) {
            if(nums[i] == 0) {
                swap(nums, zero_idx, i);
                zero_idx++;
                i++;
            } else if(nums[i] == 2) {
                swap(nums, two_idx, i);
                two_idx--;
            } else {
                i++;
            }
            // print(nums);
        }
    }
};