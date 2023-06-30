import java.util.* ;
import java.io.*; 
public class Solution {
    static long ans = 0;
    public static void merge(long arr[], int low, int mid, int high) {
        List<Long> mergingArr = new ArrayList<>();
        int left = low;
        int right = mid+1;

        while(left <= mid && right <= high) {
            if(arr[left] <= arr[right]) {
                mergingArr.add(arr[left]);
                left++;
            } else {
                ans+= (mid-left+1);
                mergingArr.add(arr[right]);
                right++;
            }
        }

        while(left <= mid) {
            mergingArr.add(arr[left]);
            left++;
        }

        while(right <= high) {
            mergingArr.add(arr[right]);
            right++;
        }

        for(int i=low; i<=high; i++) {
            arr[i] = mergingArr.get(i-low);
        }
    }

    public static void mergeSort(long arr[], int low, int high) {
        if(low >= high) {
            return;
        }

        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
    public static long getInversions(long arr[], int n) {
        mergeSort(arr, 0, n-1);
        return ans;
    }
}