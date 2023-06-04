class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0, l_min = prices[0];
        for(int i=1;i<n;i++) {
            ans = max(ans, prices[i] - l_min);
            l_min = min(l_min, prices[i]);
        }
        return ans;
    }
};