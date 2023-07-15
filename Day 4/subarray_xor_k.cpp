#include <unordered_map>
int subarraysWithSumK(vector < int > a, int b) {
    int n = a.size(), ans = 0;
    
    int curr_xr = 0;
    // <front xor till there, count>
    unordered_map<int, int> m;
    m[curr_xr]++;
    for(int i=0;i<n;i++) {
        curr_xr ^= a[i];
        
        // looking for x
        int x = curr_xr ^ b;

        // find how many x are there in the map
        ans += m[x];

        // increment front xor count
        m[curr_xr]++;
    }
    
    return ans;
}