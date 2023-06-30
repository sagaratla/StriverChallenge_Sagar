class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> copy;
        int l = left, r = mid+1;
        
        while(l<=mid && r<=right) {
            if(arr[l] <= arr[r]) {
                copy.push_back(arr[l]);
                l++;
            } else {
                copy.push_back(arr[r]);
                r++;
            }
        }
        
        while(l<=mid) {
            copy.push_back(arr[l]);
            l++;
        }
        
        while(r<=right) {
            copy.push_back(arr[r]);
            r++;
        }
        
        // copy into the new array
        for(int i=left;i<=right;i++) {
            arr[i] = copy[i-left];
        }
    }
    
    int countAns(vector<int>& arr, int left, int mid, int right) {
        int ans = 0;
        int idx = mid+1;
         // given condition calculation
        for(int i=left;i<=mid;i++) {
            while(idx<=right && 
                  static_cast<long>(arr[i]) > static_cast<long>(2*static_cast<long>(arr[idx]))) {
                idx++;
            }
            ans += (idx-mid-1);
        }
        return ans;
    }
    
    int mergeSort(vector<int>& arr, int l, int r) {
        int ans = 0;
        
        if(l>=r) {
            return ans;
        }
        
        int mid = l + (r-l)/2;
        ans += mergeSort(arr, l, mid);
        ans += mergeSort(arr, mid+1, r);
        
        ans += countAns(arr, l, mid, r);
        
        merge(arr, l, mid, r);
        
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};