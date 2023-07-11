#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
  int n = arr.size(), cum_sum = 0, ans = 0;
  map<int, int> m;
  for(int i=0;i<n;i++) {
    cum_sum += arr[i];
    
    if(cum_sum == 0) {
      ans = max(ans, i+1);
    }

    if(m.find(cum_sum) != m.end()) {
      // we found something that made it a zero sum
      ans = max(ans, i-m[cum_sum]);
    } else {
      m[cum_sum] = i;
    }
  }
  return ans;
}