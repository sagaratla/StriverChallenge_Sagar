class Solution {
public:
    void shiftSecondProper(vector<int>& arr) {
        // printArr(arr, arr.size());
        for(int i=1;i<arr.size();i++) {
            if(arr[i] < arr[i-1]) {
                int temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
            }
        }
        // printArr(arr, arr.size());
    }
    void printArr(vector<int>& arr, int n) {
        for(int i=0;i<n;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) {
            return;
        }
        int l = 0;
        while(l<m) {
            if(nums1[l] > nums2[0]) {
                // swap
                int temp = nums1[l];
                nums1[l] = nums2[0];
                nums2[0] = temp;
                shiftSecondProper(nums2);
            }
            l++;
            // printArr(nums1, m);
            // printArr(nums2, n);
        }
        
        // l = m now
        for(int i=m;i<m+n;i++) {
            nums1[i] = nums2[i-m];
        }
    }
};