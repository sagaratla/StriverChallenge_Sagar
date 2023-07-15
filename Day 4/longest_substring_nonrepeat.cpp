class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0, r = 0, n = s.length(), ans = 0;
        while(l<n && r<n) {
            if(st.find(s[r]) == st.end()) {
                st.insert(s[r]);
                r++;
                ans = max(ans, r-l);
            } else {
                st.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};