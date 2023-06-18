class Solution {
public:
    typedef pair<int, int> pi;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = intervals.size();
        for(int i=0;i<n;i++) {
            pq.push(make_pair(intervals[i][0], intervals[i][1]));
        }
        
        vector<vector<int>> ans;
        while(pq.size() != 0) {
            pair<int, int> p1 = pq.top();
            pq.pop();
            if(pq.size() == 0) {
                ans.push_back({p1.first, p1.second});
                break;
            }
            pair<int, int> p2 = pq.top();
            pq.pop();
            if(p1.second >= p2.first) {
                pq.push({p1.first, max(p1.second, p2.second)});
            } else {
                ans.push_back({p1.first, p1.second});
                pq.push(p2);
            }
        }
        
        // 1 element is left in the PQ
        pair<int, int> last = pq.top();
        pq.pop();
        if(ans[ans.size()-1][1] >= last.first) {
            ans[ans.size()-1][1] = last.second;
        } else {
            ans.push_back({last.first, last.second});
        }
        
        return ans;
    }
};