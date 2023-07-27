int func(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<int, int>> meets;
    for(int i=0;i<n;i++) {
        meets.push_back(make_pair(start[i], end[i]));
    }

    sort(meets.begin(), meets.end(), func);
    int ans = 1;
    int prev_end = meets[0].second;
    for(int i=1;i<n;i++) {
        if(meets[i].first > prev_end) {
            ans++;
            prev_end = meets[i].second;
        }
    }

    return ans;
}